-- -----------------------------------------------------
-- User: Prakash Adekkanattu
-- Date: 08/09/16
-- Time: 12:14 PM
-- Description: Database table defenitions
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Table `violin_excel`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_excel` ;
CREATE TABLE `violin_excel` (
  `col0` int(10) DEFAULT NULL,
  `col1` int(10) DEFAULT NULL,
  `title` varchar(5000) DEFAULT NULL,
  `col3` int(10) DEFAULT NULL,
  `col4` double DEFAULT NULL,
  `col5` double DEFAULT NULL,
  `category` varchar(1000) DEFAULT NULL,
  `issn` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_category`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_category` ;
CREATE TABLE `violin_category` (
  `category_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `category` varchar(1000) DEFAULT '',
  `comment` varchar(1000) DEFAULT NULL,
  PRIMARY KEY (`category_id`)
) ENGINE=InnoDB AUTO_INCREMENT=221 DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_journal`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_journal` ;
CREATE TABLE `violin_journal` (
  `journal_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `journal_title` varchar(1000) DEFAULT '',
  `issn` varchar(50) DEFAULT NULL,
  `impact_factor` double DEFAULT '0',
  PRIMARY KEY (`journal_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17662 DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_journal_category`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_journal_category` ;
CREATE TABLE `violin_journal_category` (
  `journal_category_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `journal_id` int(11) DEFAULT NULL,
  `category_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`journal_category_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17662 DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_pmids`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_pmids`;
CREATE TABLE `violin_pmid` (
  `pmid_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `pmid` int(10) DEFAULT '0',
  `scopus_id` int(10) DEFAULT NULL,
  `issn` varchar(5000) DEFAULT NULL,
  `category_id` int(11) DEFAULT NULL,
  `publication_year` int(4) DEFAULT NULL,
  `article_type` varchar(50) DEFAULT NULL,
  `pubmed_article_type` varchar(10000) DEFAULT NULL,
  `title` varchar(5000) DEFAULT NULL,
  `citation_count` int(11) DEFAULT '0',
  `date_of_citation_count` date DEFAULT NULL,
  `scopus_article_exist` varchar(10) NULL,
  PRIMARY KEY (`pmid_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6898 DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_baseline`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_baseline` ;
CREATE TABLE `violin_baseline` (
  `baseline_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `pmid` varchar(20) DEFAULT NULL,
  `category_id` int(10) DEFAULT NULL,
  `publication_year` year(4) DEFAULT NULL,
  `times_cited` int(11) DEFAULT NULL,
  `rank` int(11) DEFAULT NULL,
  `median_rank` double(10, 2) DEFAULT NULL,
  `percentile_rank` double(10,2) DEFAULT NULL,
  `article_type` varchar(1000) DEFAULT NULL,
  PRIMARY KEY (`baseline_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `violin_update_history`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `violin_update_history`;
CREATE TABLE `violin_update_history` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `item` varchar(1000) DEFAULT '',
  `year` int(10) DEFAULT NULL,
  `type` int(10) DEFAULT NULL,
  `category` int(10) DEFAULT NULL,
  `update_date` datetime DEFAULT NULL,
  `flag` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- -----------------------------------------------------
-- Table `article`
-- -----------------------------------------------------
CREATE TABLE `article` (
  `article_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `entity_id` int(10) DEFAULT NULL,
  `pmid` varchar(25) DEFAULT NULL,
  `scopus_id` varchar(25) DEFAULT NULL,
  `article_type` varchar(255) DEFAULT NULL,
  `journal` varchar(1000) DEFAULT NULL,
  `journal_issn` varchar(20) DEFAULT NULL,
  `journal_eissn` varchar(20) DEFAULT NULL,
  `journal_lissn` varchar(20) DEFAULT NULL,
  `citation_count` mediumint(9) DEFAULT NULL,
  `percentile_rank` float DEFAULT NULL,
  `cover_date` datetime DEFAULT NULL,
  `category` varchar(1000) DEFAULT NULL,
  `title` varchar(5000) DEFAULT NULL,
  `pages` varchar(1000) DEFAULT NULL,
  `volume` varchar(1000) DEFAULT NULL,
  `issue` varchar(1000) DEFAULT NULL,
  `nlmabbreviation` varchar(1000) DEFAULT NULL,
  `scopus_doc_id` varchar(25) DEFAULT NULL,
  `authors` text,
  `created` datetime DEFAULT NULL,
  `updated` datetime DEFAULT NULL,
  PRIMARY KEY (`article_id`),
  KEY `issn` (`journal_eissn`,`journal_issn`,`journal_lissn`,`pmid`,`cover_date`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8 COMMENT='The violin table for WCMC articles.';

-- -----------------------------------------------------
-- Table `author`
-- -----------------------------------------------------
CREATE TABLE `author` (
  `author_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `entity_id` int(10) DEFAULT NULL,
  `cwid` varchar(32) DEFAULT NULL,
  `first_name` varchar(255) DEFAULT NULL,
  `last_name` varchar(255) DEFAULT NULL,
  `created` datetime DEFAULT NULL,
  `updated` datetime DEFAULT NULL,
  PRIMARY KEY (`author_id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8 COMMENT='The violin table for WCMC authors.';

-- -----------------------------------------------------
-- Table `authro_article`
-- -----------------------------------------------------
CREATE TABLE `author_article` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `author_id` varchar(32) DEFAULT NULL,
  `article_id` varchar(32) DEFAULT NULL,
  `is_first_or_last_author` tinyint(4) DEFAULT NULL,
  `created` datetime DEFAULT NULL,
  `updated` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8 COMMENT='The violin table for WCMC author - articles relations.';