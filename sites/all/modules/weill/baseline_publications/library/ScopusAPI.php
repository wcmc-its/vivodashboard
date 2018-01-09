<?php
/**
 * ScopusAPI
 *
 * This is a standalone PHP wrapper around the Scopus API.
 */

define('SCOPUSAPI_VERSION', '1');

class ScopusAPI extends Exception
{
    public $return_max = 1000; // Max number of results to return
    public $count = 100; // Sets to the number of search results
    public $field = 'pubmed-id,citedby-count,identifier'; //filed to search
    public $start = 0;
    public $view = "FULL";
    public $api_key = 'apikey';
    public $insttoken = 'insttoken';
    public $http_accept = 'application/xml';
    public $term = '';
    public $db = 'pubmed';
    public $return_mode = 'xml';
    public $exact_match = true; // Exact match narrows the search results by wrapping in quotes

    static public $curl_site_url = '';

    //private $scopus_query_start = "https://api.elsevier.com/content/abstract/PUBMED_ID:";

    private $scopus_query_start = "https://api.elsevier.com/content/search/scopus?query=";


    // http://api.elsevier.com/content/search/index:SCOPUS?query=pmid(23000000)&view=COMPLETE&field=citedby-count,identifier&apikey=e0fa610418a4859d24f2457e021aea60

    public function query($term)
    {
        $this->term = $term;
        $xml = $this->scopus_esearch();
        return $xml;
    }

    // Retuns an XML object
    public function scopus_esearch()
    {
        // Setup the URL for esearch
        $q = array();
        $params = array(
            //'start' => $this->start,
            //'count' => $this->count,
            'query' => str_replace(' ', '%20', trim($this->term)),
            'field' => $this->field,
            //'view' => $this->view,
            'apikey' => $this->api_key,
            'insttoken' => $this->insttoken,
            'httpAccept' => $this->http_accept,
        );

        foreach ($params as $key => $value) {
            if($key == 'query') {
                $pmid = $value;

            }
        }
        $url = $this->scopus_query_start . $pmid . '&';


        foreach ($params as $key => $value) {
            if($key != 'query') {
                $url_fields[] = $key . '=' . $value;
            }
        }
        $http_query = implode('&', $url_fields);
        $url = $url . $http_query;

        echo "\n" . $url . "\n";

        $XML = self::proxy_simplexml_load_file($url);; // results of esearch, XML formatted

        return $XML;
    }

    public function parse($xml)
    {
        $data = array();
        foreach ($xml->entry as $art) {
            if (isset($art->{'pubmed-id'})) {
                $pmid = (int)$art->{'pubmed-id'};
                $data[$pmid] = array(
                    'pmid' => (int)$art->{'pubmed-id'},
                    'citedby-count' => (int)$art->{'citedby-count'}
                );
            }
        }
        return $data;
    }

    public function parse_empty_result($xml)
    {
        $empty = false;
        $error = '';
        if (isset($xml->entry->error)) {
            $error = $xml->entry->error;
        }

        if(!empty($error) && ($error == 'Result set was empty')){
            $empty = true;
        }
        return $empty;
    }


    public function parse_pmid($xml)
    {
        $pmid = 0;
        if (isset($xml->entry->{'pubmed-id'})) {
            $pmid = (int)$xml->entry->{'pubmed-id'};
        }
        return $pmid;
    }

    public function parse_citation_count($xml)
    {
        $citation_count = 0;
        if (isset($xml->entry->{'citedby-count'})) {
            $citation_count = (int)$xml->entry->{'citedby-count'};
        }
        return $citation_count;
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
