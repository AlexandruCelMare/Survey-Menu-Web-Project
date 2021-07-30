<?php
session_start();
require ("index.php");
require ("functions.php");
$q="SELECT surveyID, surveyName FROM surveys";
$rs=mysqli_query($conn, $q);
if ($_SERVER['REQUEST_METHOD']=='POST'){
    $_SESSION['survey']=$_POST['survey'];
    redirect_user('userTakeSurvey.php');
}
?>



<html>
   
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title>User: Survey Menu</title>
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
            
        <div class="viewSurveys">
        <form action = "userSurveyMenu.php" method = "post">
        <a href="userOptions.html" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<input type = 'submit' value=".$rsTemp['surveyName']." name = 'survey' />";
        }
        ?>
        </form>
        </div>       
    </body>
</html>
