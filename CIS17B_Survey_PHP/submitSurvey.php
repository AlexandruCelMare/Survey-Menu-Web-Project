<?php
require('index.php');
require('functions.php');
session_start();
$q1='SELECT `questions`.`text` FROM `survey`.`surveys` AS `surveys`, `survey`.`questions` AS `questions` '
        . 'WHERE `surveys`.`surveyID` = `questions`.`surveyID`'
        . 'AND  surveys.`surveyName` = "'.$_SESSION['survey'].'"';

console_log($q1);
$r1=mysqli_query($conn, $q1);
console_log($r1);
console_log($_POST);
if ($_SERVER['REQUEST_METHOD']=='POST'){
    while($row=mysqli_fetch_array($r1, MYSQLI_ASSOC)){
        //console_log($row);
        //console_log($row['text']);
        //console_log(str_replace(' ','_',$row['text']));
        $q= 'UPDATE `survey`.`answers` SET `answerCounter` = answerCounter+1  WHERE (`answerID` = "'.$_POST[str_replace(' ','_',$row['text'])].'")';
        $r=mysqli_query($conn, $q);
        console_log($r);
    }
    redirect_user('userSurveyMenu.php');
}