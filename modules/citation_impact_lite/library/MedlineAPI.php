<?php
/************************************************************************************************
 * // Name:    MedlineAPI.php
 * // Author:    Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    MedlineAPI class - a stand alone PHP wrapper around Pubmed API
 ************************************************************************************************/

define('PUBMEDAPI_VERSION', '1'); // Sat 10 Nov 2012

class MedlineAPI extends Exception
{
    public $retmax = 5000; // Max number of results to return
    public $retstart = 0; // The search result number to start displaying data, useful for pagination
    public $count = 0; // Sets to the number of search results

    public $term = '';
    public $db = 'pubmed';
    public $retmode = 'xml';
    public $exact_match = true; // Exact match narrows the search results by wrapping in quotes

    // For accessing PubMed through proxy servers
    static public $proxy_name = '';
    static public $proxy_port = '';
    static public $proxy_username = '';
    static public $proxy_password = '';
    static public $curl_site_url = '';

    private $esearch = 'https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?';
    private $efetch = 'https://eutils.ncbi.nlm.nih.gov/entrez/eutils/efetch.fcgi?';

    public function query($term)
    {
        $this->term = $term;

        $xml = null;
        $xml = $this->pubmed_esearch($this->term);

        $this->count = (int)$xml->Count;

        // esearch returns a list of IDs so we have to concatenate the list and do an efetch
        $ids = array();
        if (isset($xml->IdList->Id) && !empty($xml->IdList->Id)) {
            foreach ($xml->IdList->children() as $id) {
                $ids[] = (string)$id;
            }
        }
        return $ids;
    }

    public function query_pmid($pmid)
    {
        $XML = $this->pubmed_efetch($pmid);
        return $this->parse($XML);
    }

    public function query_multi_pmids($str_pmids)
    {
        $XML = $this->pubmed_multi_efetch($str_pmids);
        return $this->parse($XML);
    }

    // Retuns an XML object
    public function pubmed_esearch($term)
    {
        // Setup the URL for esearch
        $q = array();
        $params = array(
            'db' => $this->db,
            'retmode' => $this->retmode,
            'retmax' => $this->retmax,
            'retstart' => $this->retstart,
            'term' => str_replace('%20', ' ', str_replace('%255D', ']', str_replace('%255B', '[', str_replace('%2529', ')', str_replace('%2528', '(', str_replace('%2B', '+', stripslashes(urlencode($term))))))))
        );

        foreach ($params as $key => $value) {
            $q[] = $key . '=' . $value;
        }
        $httpquery = implode('&', $q);
        $url = $this->esearch . $httpquery;

        // echo $url . "\n";

        $XML = self::proxy_simplexml_load_file($url); // results of esearch, XML formatted

        return $XML;
    }

    // Returns an XML object
    public function pubmed_efetch($pmid)
    {
        // Setup the URL for efetch
        $params = array(
            'db' => $this->db,
            'retmode' => $this->retmode,
            'retmax' => $this->retmax,
            'id' => (string)$pmid
        );
        $q = array();
        foreach ($params as $key => $value) {
            $q[] = $key . '=' . $value;
        }
        $httpquery = implode('&', $q);

        $url = $this->efetch . $httpquery;

        // echo $url . "\n";

        $XML = self::proxy_simplexml_load_file($url);

        return $XML;
    }

    public function pubmed_multi_efetch($str_pmids)
    {
        // Setup the URL for efetch
        $params = array(
            'db' => $this->db,
            'retmode' => $this->retmode,
            'retmax' => $this->retmax,
            'id' => str_replace(' ', '%20', trim($str_pmids))
        );
        $q = array();
        foreach ($params as $key => $value) {
            $q[] = $key . '=' . $value;
        }
        $httpquery = implode('&', $q);

        $url = $this->efetch . $httpquery;

        // echo $url . "\n";

        $XML = self::proxy_simplexml_load_file($url);

        return $XML;
    }

    public function pubmed_random_efetch($pmids, $count = 200)
    {
        $results = array();

        $rand_keys = array_rand($pmids, $count);

//        for ($i = 0; $i < $count; $i++) {
//            $curr_pmid = $pmids[$rand_keys[$i]];
//            $results[$curr_pmid] = $this->query_pmid($curr_pmid, false);
//        }

        $StrPmids = '';
        for ($i = 0; $i < $count; $i++) {
            $StrPmids .= $pmids[$rand_keys[$i]]. ' ';

        }
        if(!empty($StrPmids)){
            $results = $this->query_multi_pmids($StrPmids, false);
        }

        return $results;
    }

    public function parse($xml)
    {
        $data = array();
        foreach ($xml->PubmedArticle as $art) {

                // Full metadata

                // Authors array contains concatendated LAST NAME + INITIALS
                $authors = array();
                if (isset($art->MedlineCitation->Article->AuthorList->Author)) {
                    try {
                        foreach ($art->MedlineCitation->Article->AuthorList->Author as $k => $a) {
                            $authors[] = (string)$a->LastName . ' ' . (string)$a->Initials;
                        }
                    } catch (Exception $e) {
                        $a = $art->MedlineCitation->Article->AuthorList->Author;
                        $authors[] = (string)$a->LastName . ' ' . (string)$a->Initials;
                    }
                }

                // Keywords array
                $keywords = array();
                if (isset($art->MedlineCitation->MeshHeadingList->MeshHeading)) {
                    foreach ($art->MedlineCitation->MeshHeadingList->MeshHeading as $k => $m) {
                        $keywords[] = (string)$m->DescriptorName;
                        if (isset($m->QualifierName)) {
                            if (is_array($m->QualifierName)) {
                                $keywords = array_merge($keywords, $m->QualifierName);
                            } else {
                                $keywords[] = (string)$m->QualifierName;
                            }
                        }
                    }
                }

                // Article IDs array
                $articleid = array();
                if (isset($art->PubmedData->ArticleIdList)) {
                    foreach ($art->PubmedData->ArticleIdList->ArticleId as $id) {
                        $articleid[] = $id;
                    }
                }

                $article_types = array();
                if (isset($art->MedlineCitation->Article->PublicationTypeList)) {
                    foreach ($art->MedlineCitation->Article->PublicationTypeList->children() as $id) {
                        $article_types[] = $id;
                    }
                }

                $data[] = array(
                    'pmid' => (string)$art->MedlineCitation->PMID,
                    'volume' => (string)$art->MedlineCitation->Article->Journal->JournalIssue->Volume,
                    'issue' => (string)$art->MedlineCitation->Article->Journal->JournalIssue->Issue,
                    'year' => (string)$art->MedlineCitation->Article->Journal->JournalIssue->PubDate->Year,
                    'month' => (string)$art->MedlineCitation->Article->Journal->JournalIssue->PubDate->Month,
                    'pages' => (string)$art->MedlineCitation->Article->Pagination->MedlinePgn,
                    'issn' => (string)$art->MedlineCitation->Article->Journal->ISSN,
                    'journal' => (string)$art->MedlineCitation->Article->Journal->Title,
                    'journalabbrev' => (string)$art->MedlineCitation->Article->Journal->ISOAbbreviation,
                    'title' => (string)$art->MedlineCitation->Article->ArticleTitle,
                    'abstract' => (string)$art->MedlineCitation->Article->Abstract->AbstractText,
                    'affiliation' => (string)$art->MedlineCitation->Article->Affiliation,
                    'authors' => $authors,
                    'articleid' => implode(',', $articleid),
                    'articletype' => implode(' | ', $article_types),
                    'keywords' => $keywords
                );

        }
        return $data;
    }

    public function parse_pmids($xml)
    {
        $data = array();
        if (isset($xml->IdList)) {
            foreach ($xml->IdList->children() as $Id) {
                $data[] = (string)$Id;
            }
        }
        return $data;
    }

    public static function proxy_simplexml_load_file($url)
    {
        $xml_string = '';
        if (isset(self::$proxy_name) && !empty(self::$proxy_name)) {
            $proxy_fp = fsockopen(self::$proxy_name, self::$proxy_port);
            if ($proxy_fp) {
                fputs($proxy_fp, "GET " . $url . " HTTP/1.0\r\nHost: " . self::$proxy_name . "\r\n");
                if (isset($_SERVER['HTTP_USER_AGENT'])) {
                    fputs($proxy_fp, "User-Agent: " . $_SERVER['HTTP_USER_AGENT'] . "\r\n");
                }
                fputs($proxy_fp, "Proxy-Authorization: Basic " . base64_encode(self::$proxy_username . ":" . self::$proxy_password) . "\r\n\r\n");

                while (!feof($proxy_fp)) {
                    $xml_string .= fgets($proxy_fp, 128);
                }

                fclose($proxy_fp);
                $xml_string = strstr($xml_string, "<?xml");
                $xml = simplexml_load_string($xml_string);
                #JSTOR hack
                if (empty($xml) && strpos($url, 'jstor') !== false) {
                    $xml = new XMLReader();
                    $xml->xml($xml_string);
                }
            }
        } else {
            if (isset($_SERVER['HTTP_USER_AGENT'])) {
                ini_set('user_agent', $_SERVER['HTTP_USER_AGENT']);
            }
            $xml = self::load_xml_from_url($url);
            #JSTOR hack
            if (empty($xml) && strpos($url, 'jstor') !== false) {
                $xml = new XMLReader();
                $xml->open($url);
            }
        }
        return $xml;
    }

    public static function load_file_from_url($url)
    {
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_URL, $url);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($curl, CURLOPT_REFERER, self::$curl_site_url);
        $str = curl_exec($curl);
        curl_close($curl);
        return $str;
    }

    public static function load_xml_from_url($url)
    {
        return simplexml_load_string(self::load_file_from_url($url));
    }

}

?>
