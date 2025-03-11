<?php
$host = 'localhost';
$dbname = 'projet_web';
$user = 'etudiant';
$password = 'tssnadmin';

$mydb = new mysqli($host, $user, $password, $dbname);

if ($mydb->connect_error) {
    die('Erreur de connexion (' . $mydb->connect_errno . ') ' . $mydb->connect_error);
}
?>
