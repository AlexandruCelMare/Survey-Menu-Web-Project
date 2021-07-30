<?php

if ($_SERVER['REQUEST_METHOD']=='POST'){
    require('index.php');
    require('functions.php');
    $errors=array();
    
//    if (empty($_POST['username'])){
//        
//    }
    
    $q=mysqli_query($conn, "SELECT usernameID FROM user WHERE usernameID=".$_POST['userID']);
    console_log($q);
    if (!$q || mysqli_num_rows($q)==0){
        $username= mysqli_real_escape_string($conn, trim($_POST['userID']));
    }
    else{
        $errors[]='This username already exists';
    }
//    if (rExpression($_POST['password'])){
         $password= mysqli_real_escape_string($conn, trim($_POST['password']));
//    }
//    else {
//        $error[]= 'min length 6, max length 20, and must contain: at least one digit, one lowercase letter,'
//                . 'one uppercase letter, and one special symbol(@#$%)';
//    }
        
    $firstName= mysqli_real_escape_string($conn, trim($_POST['firstName']));
    $lastName= mysqli_real_escape_string($conn, trim($_POST['lastName']));
    console_log($errors);
    if (empty($errors)){
        $q="INSERT INTO user (usernameID, password, firstName, lastName) VALUES ('$username', '$password', '$firstName', '$lastName')";
        console_log($q);
        if ($conn->query($q)===TRUE){
        redirect_user("userOptions.html");
        }
        else {
            echo "Error".$sql."<br>".$conn->error;
        }
        mysqli_close($conn);
        exit();
    }
}
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

