<?php
	class AnyStyleIODTO{
		private $_author;
		private $_title;
		private $_location;
		private $_publisher;
		private $_unmatched_pages;
		private $_unmatched_publisher;
		private $_type;
		private $_language;
		private $_date;
		private $_jsonObj;
		private $_actualInput;
		private $_filteredInput;

		public function setJsonObject($jsonObj){
			$this->_jsonObj=$jsonObj;
		}
		
		public function getJsonObject(){
			return $this->_jsonObj;
		}
		
		public function getActualInput(){
			return $this->_actualInput;
		}
		
		public function setActualInput($aInput){
			$this->_actualInput=$aInput;
		}
		
		public function getFilteredInput(){
			return $this->_filteredInput;
		}
		
		public function setFilteredInput($fInput){
			$this->_filteredInput=$fInput;
		}
		
		public function getAuthor(){
			return $this->_author;
		}
		
		public function setAuthor($author){			
			$this->_author=$author;
		}
		
		public function getTitle(){
			return $this->_title;
		}
		
		public function setTitle($title){
			$this->_title=$title;
		}
		
		public function getLocation(){
			return $this->_location;
		}
		
		public function setLocation($location){
			$this->_location=$location;
		}
		
		public function getPublisher(){
			return $this->_publisher;
		}
		
		public function setPublisher($publisher){
			$this->_publisher=$publisher;
		}
		
		public function getType(){
			return $this->_type;
		}
		
		public function setType($type){
			$this->_type=$type;
		}
		
		public function getLanguage(){
			return $this->_language;
		}
		
		public function setLanguage($language){
			$this->_language=$language;
		}
		
		public function getDate(){
			return $this->_date;
		}
		
		public function setDate($date){
			$this->_date=$date;
		}
		
		public function getUnmatched_pages(){
			return $this->_unmatched_pages;
		}
		
		public function setUnmatched_pages($unmatched_pages){
			$this->_unmatched_pages=$unmatched_pages;
		}
		
		public function getUnmatched_publisher(){
			return $this->_unmatched_publisher;
		}
		
		public function setUnmatched_publisher($unmatched_publisher){
			$this->_unmatched_publisher=$unmatched_publisher;
		}
	}
?>