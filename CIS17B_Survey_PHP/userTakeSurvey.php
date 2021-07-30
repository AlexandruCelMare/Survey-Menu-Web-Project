<?php
session_start();
require ("functions.php");
require ("index.php");
console_log($_SESSION['survey']);
$q="SELECT `surveys`.`surveyName` 
    AS `Survey Name`, `surveys`.`description` 
    AS `Survey Description`, `questions`.`text` 
    AS `Question text`, `answers`.`text` 
    AS `Answer text`, `answers`.`answerCounter` 
    AS `Input counter`, `answers`.`answerID` 
    FROM `survey`.`questions` 
    AS `questions`, `survey`.`surveys` 
    AS `surveys`, `survey`.`answers` 
    AS `answers` 
    WHERE `questions`.`surveyID` = `surveys`.`surveyID`"
        . "AND surveys.surveyName='".$_SESSION['survey']."'"
        . "AND `answers`.`questionID` = `questions`.`questionID`";
$rs=mysqli_query($conn, $q);
//session_close();
?>

<html>
   
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title> Admin: View Surveys</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
        <body>
            
        <div class="horizontal-menu">
        <a href="index.html" >Home</a>
        <a href="login.html" class="active">Login</a>
        <a href="about.html">About</a>
        </div>           
            
        <h1 style = "font-family:verdana;">
        SERVE-A
        </h1>
        <h2 style = "font-family:verdana;">
        Serving Before Surveying
        </h2>
<!--            <div class="vertical-menu">
            </div>-->
        <form action='submitSurvey.php' method='post'>
          
        <div class="takeReturn">
        <a href="userSurveyMenu.php" >Return</a>
        </div>
        <div class="takeSurveys">
        <?php
//        console_log($rs['Survey Name']);
//        echo '<h5> Survey: '.$_SESSION['survey']. '</h5>';
        $row=mysqli_fetch_all($rs);
        $temp='';
        foreach($row as $r){
            console_log($r);
            if ($temp!==$r[2]){
                echo '<h6> '.$r['2']. '</h6>';
//                echo '<input type="radio" value="'.$r['3']. '">"'.$r['3'].'"<br>';
            }
            else{
//                echo '<input type="radio" value="'.$r['3']. '">"'.$r['3'].'"<br>';
            }
            
            echo '<input type="radio" name="'.$r['2'].'" value="'.$r['5']. '">'.$r['3'].'<br>';
            $temp=$r['2'];
        }
        ?>
        </div>
        <div class="rSubmit">        
        <input type = 'submit'  name = 'survey' />    
        </div>
        </form>
    </body>
</html>