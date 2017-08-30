<?php

	function removeLessThanThreeCharacters($text){
		$words = preg_replace('!\\b\\w{1,3}\\b!', '', $text);//preg_replace('/\b\w{1,3}\s|[0-9]/gi','',$text);
		$words=str_replace(array("?","!",",",";","'"), "", $words);//preg_replace('/[^a-z]+/i', '', $words);
		return $words;
	}
	
	function anystyleIOservice($ch,$citation){
		$jsonData = array (
				'format' => 'json;charset=UTF-8',
				'access_token' => '6dc1faa8a5b85b5a707ba0d612756233',
				'references' => $citation
		);
		$jsoneData = json_encode($jsonData);
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $jsoneData);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($ch, CURLOPT_TIMEOUT, 5);
		curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
		curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json;charset=UTF-8'));
		$result = curl_exec($ch);
		$jsonResult=json_decode($result);
		
		//echo $citation;//var_dump($jsonResult);
		//echo '<br />';
		//var_dump($jsonResult);
		//echo "<br /><br /><br />";
		return $jsonResult[0];
	}
	
	function getAppliedRegularExpressionStr($citation){
		$citation=preg_replace('#^\d+[.]#', '', $citation);
		$citation=str_ireplace('Symposium','',$citation);
		$citation=str_ireplace('Symposia','',$citation);
		$citation=str_ireplace('Meeting','',$citation);
		$citation=str_ireplace('Meetings','',$citation);
		$citation=str_ireplace('Conference','',$citation);
		$citation=str_ireplace('Abstract','',$citation);
		$citation=str_ireplace('Press','',$citation);
		$citation=str_ireplace('Accept','',$citation);
		$citation=str_ireplace('Accepted','',$citation);
		return $citation;
	}
	
	function getFilteredCitaionArray($citationStr){
		//echo $citationStr.'<br /><br /><br />';
		//echo "Citation: ".preg_match_all ('/\n/',$citationStr)."<br />";
		//$citationStr=preg_replace("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", "\n", $citationStr);
		//echo "Citation: ".preg_match_all ('/\n/',$citationStr)."<br />";
		$arr=explode("\n",$citationStr);
		$prev="";
		$prevLength=0;
		$lastCall=0;
		$citationArr=array();
		// TODO - if all the rows length less than 100, all the rows are combined into one row, need to fix this issue
		foreach($arr as $citVal){
			$presentLen=strlen($citVal);
			$citVal=trim($citVal);
			$citVal = str_replace(array('"','\\'), '', $citVal); //'\''
			//$prev=$presentLen < 100 ? ($prev." ".$citVal):($prev==""?$citVal:$prev);
			if($presentLen < 100){
				$prev=$prev." ".$citVal;
				$lastCall=0;
			}else if($prev==""){
				$prev=$citVal;
				$lastCall=0;
			}else{
				array_push($citationArr,$prev);
				$prev=$citVal;
				$lastCall=1;
			}
			/*if($presentLen<100){
				if($prev=="")$prev=$citVal;
				else $prev=$prev." ".$citVal; //if($prevLength<100)
				$lastCall=0;
			}else{
				//array_push($citationArr,($prev<>""?$prev:$citVal));
				//$prev=$citVal;
				$lastCall=1;
				//if(trim($citVal)!="")$prev=$prev." ".trim($citVal);
				//array_push($citationArr,($prev<>"" && $prevLength<100?$prev:$citVal));
				//$prev="";
				//$prevLength=0;
				if($prev<>"" && $prevLength<100){
					//$prev=getAppliedRegularExpressionStr($prev);
					array_push($citationArr,$prev);
					$prev=$citVal;
					$prevLength=0;
				}else{
					//$citVal=getAppliedRegularExpressionStr($citVal);
					array_push($citationArr,$citVal);
					$prev="";
					$prevLength=0;
				}
			}*/
			$prevLength=$presentLen;
		}
		if($lastCall==0)array_push($citationArr,$prev);
		//var_dump($citationArr);
		//echo "<br/><br/><br/>";
		return $citationArr;
	}
	
	function  getUserDataObject($userData,$ch){

		$user=new UserDTO();
		//var_dump($userData);
		//echo '<br /><br /><br />';
		for($j='A';$j<='B';$j++){
			$cellVal=preg_replace("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", "\n", trim($userData[$j]));
			
			switch($j){
				case 'A': $user->setCWID($cellVal);break;
				case 'B': $user->setPublications($cellVal);
				$citations = getFilteredCitaionArray($cellVal);
				$user->setFilteredCitationArray($citations);
				$k=1;
				foreach($citations as $citRow){
					$citation=new Citation();
					$citation->setActualCitation($citRow);
					$fCitRow = getAppliedRegularExpressionStr($citRow);
					$citation->setFilteredCitation($fCitRow);
					$citation->setJsonObject(anystyleIOservice($ch,$fCitRow));
					$citation->constructQueryString();
					$citation->getPubMedResult();					
					++$k;
					$user->setCitation($citation);
				}					
				break;
			}
		}
		return $user;
	}
	
	
	function getFormattedOutput($x,$y,$z){		
		$y=$y.(strlen($y)>0?"<br />":"").$z.": ".$x;		
		return $y;
	}
?>