<?php

require ("index.php");
$q="SELECT usernameID, usernameID FROM user";
$rs=mysqli_query($conn, $q);

?>

<html>
   
    <head>
        <link rel="stylesheet" href="StyleSheet.css">
        <title> User: View Users</title>
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
        <h5> 
            Select a user to view.
        </h5>     
        <div class="viewSurveys">
        <a href="administrator.html" >Return</a>
        <?php
        while ($rsTemp=mysqli_fetch_array($rs)){
            echo "<a href='administrator.html'>".$rsTemp['usernameID']."</a>";
        }
        ?>
        </div>             
            
    </body>
</html>