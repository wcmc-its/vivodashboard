<?php
	class Citation {
		private $_actualCitation;
		private $_filteredCitation;
		private $_jsonObj;
		private $_pubMedQry;
		private $_pubMedResultArr;
		
		public function constructQueryString(){
			$authors=array();
			$qryStr="";
			
			if(isset($this->_jsonObj->author) || isset($this->_jsonObj->editor)){
				$authorObj = isset($this->_jsonObj->author)?$this->_jsonObj->author:$this->_jsonObj->editor;
				if(strpos($authorObj," and ") === false){
					if(strpos($authorObj,", ") === false){
						array_push($authors,$authorObj);
					}else{
						$authors=split(", ",$authorObj);
					}
				}else{
					$authors=split(" and ",$authorObj);
				}
				//var_dump($authors);
				//$df='';
				
				$l=0;
				foreach ($authors as $a){
					$author=preg_replace('#^\w+[.],#', '',trim($a));
					if($l<2){$qryStr=$qryStr." ".trim($author);}
					++$l;					
				}
				//echo $df."<br />";
			}	
			$qryStr=trim($qryStr);
			if(isset($this->_jsonObj->title)){
				$x=split(" ",$this->_jsonObj->title);
				usort($x, function($a, $b) {
					return strlen($b) - strlen($a);
				});
				$l=0;
				foreach ($x as $a){
					if($l<4)$qryStr=$qryStr." ".trim($a);
					++$l;
				}
			}
			$this->_pubMedQry=preg_replace('!\\b\\w{1,2}\\b!', '',$qryStr);
			$this->_pubMedQry=str_replace(array("?","!",",",";","'","."), "", $this->_pubMedQry);
			 
			return $this->_pubMedQry;
		}
		
		public function getPubMedResult(){
			//sleep(3);
			$term = $this->_pubMedQry;
			$pubMedAPI = new PubMedAPI();
			$this->_pubMedResultArr = $pubMedAPI->query($term);
			//echo var_dump($this->_pubMedResultArr).'<br />Hanumantha<br /><br />';
		}
		
		public function getActualCitation(){
			return $this->_actualCitation;
		}
		
		public function setActualCitation($actualCitation){
			$this->_actualCitation=$actualCitation;
		}
		
		public function getFilteredCitation(){
			return $this->_filteredCitation;
		}
		
		public function setFilteredCitation($filteredCitation){
			$this->_filteredCitation=$filteredCitation;
		}
		
		public function getJsonObject(){
			return $this->_jsonObj;
		}
		
		public function setJsonObject($jsonObj){
			$this->_jsonObj=$jsonObj;			
		}
		
		public function getPubMedQry(){
			return $this->_pubMedQry;
		}
		
		public function setPubMedQry($pubMedQry){
			$this->_pubMedQry=$pubMedQry;
		}
		
		public function getPubMedResultArray(){
			return $this->_pubMedResultArr;
		}
		
		public function setPubMedResultArray($pubMedRsltArr){
			$this->_pubMedResultArr=$pubMedRsltArr;
		}		
	}

?>