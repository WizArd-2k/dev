<?php
/*Définition des constantes*/
define('DB_ADDRESS','localhost');
define('DB_NAME','DB_Calendrier');
define('DB_USER','etudiant');
define('DB_PASS','tssnadmin');
/*ouverture de la connexion à la base de données*/
$mydb = new mysqli(DB_ADDRESS, DB_USER, DB_PASS, DB_NAME);
$resultat = $mydb->query("SELECT * FROM Eleve");

while($obj_lu = $resultat->fetch_object())
    echo 'ligne:'.$obj_lu->id.' lue : '.$obj_lu->prenom.' '.$obj_lu->nom.' '.$obj_lu->classe."<br/>";
/*fermeture de la connexion à la base de données*/
$mydb->close();
?>