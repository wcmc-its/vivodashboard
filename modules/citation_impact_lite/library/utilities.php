<?php
/************************************************************************************************
 * // Name:    utilities.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:   General functions
 ************************************************************************************************/

function trimToLength($l, $s) {
    $len = strlen($s);
    if ($len > $l) {
        //return $len;
        return substr($s, 0, (($l/2)-2))."....".substr($s, ($len-($l/2)+2), $len-1);
    }
    else {
        return $s;
    }
}

?>