<?php

require ("index.php");
$q="SELECT surveyID, surveyName FROM surveys";
$rs=mysqli_query($conn, $q);

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
        <div class="viewSurveys">
        <a href="administrator.html" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<a href='administrator.html'>".$rsTemp['surveyName']."</a>";
        }
        ?>
        </div>             
            
    </body>
</html>