<?php
	class UserDTO {
		private $_cwid;
		private $_userName;
		private $_sequence;
		private $_title;
		private $_volume;
		private $_number;
		private $_pageEnd;
		private $_pageStart;
		private $_pmid;
		private $_evalYear;
		private $_publications;
		private $_filteredCitationArr;
		private $_citationArr;
		
		
		
		public function __construct(){
			$this->_citationArr=array();
		}
		
		public function getFilteredCitationArray(){
			return $this->_filteredCitationArr;
		}
		
		public function setFilteredCitationArray($arr){
			$this->_filteredCitationArr=$arr;
		}
		
		public function getEvalYear(){
			return $this->_evalYear;
		}
		
		public function setEvalYear($evalYear){
			$this->_evalYear=$evalYear;
		}
		
		public function setCitation($citation){
			array_push($this->_citationArr,$citation);
		}
		
		public function getCitation($pos){
			if(count($this->_citationArr)>$pos)return $this->_citationArr[$pos];
			else return null;
		}
		
		public function getCWID(){
			return $this->_cwid;
		}
		
		public function setCWID($cwid){
			$this->_cwid=$cwid;
		}
		
		public function getUserName(){
			return $this->_userName;
		}
		
		public function setUserName($userName){
			$this->_userName=$userName;
		}
		
		public function getSequence(){
			return $this->_sequence;
		}
		
		public function setSequence($seq){
			$this->_sequence=$seq;
		}
		
		public function getTitle(){
			return $this->_title;
		}
		
		public function setTitle($title){
			$this->_title=$title;
		}
		
		public function getVolume(){
			return $this->_volume;
		}
		
		public function setVolume($volume){
			$this->_volume=$volume;
		}
		
		public function getNumber(){
			return $this->_number;
		}
		
		public function setNumber($number){
			$this->_number=$number;
		}
		
		public function getPageEnd(){
			return $this->_pageEnd;
		}
		
		public function setPageEnd($pageEnd){
			$this->_pageEnd=$pageEnd;
		}
		
		public function getPageStart(){
			return $this->_pageStart;
		}
		
		public function setPageStart($pageStart){
			$this->_pageStart=$pageStart;
		}
		
		public function getPMID(){
			return $this->_pmid;
		}
		
		public function setPMID($pmid){
			$this->_pmid=$pmid;
		}
		
		public function getPublications(){
			return $this->_publications;
		}
		
		public function setPublications($publications){
			$this->_publications=$publications;
		}
		
		public function getCitationArray(){
			return $this->_citationArr;
		}
		
		public function setCitationArray($citationArr){
			$this->_citationArr=$citationArr;
		}
		
	}

?>