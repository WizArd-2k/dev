<?php

$mydb = new mysqli('localhost', 'etudiant', 'tssnadmin', 'projet_web');

if ($mydb->connect_error) {
    die('Erreur de connexion (' . $mydb->connect_errno . ') ' . $mydb->connect_error);
}
?>
