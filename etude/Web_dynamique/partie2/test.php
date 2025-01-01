<?php
/*Définition des constantes*/
define('DB_ADDRESS','localhost');
define('DB_NAME','DB_Calendrier');
define('DB_USER','etudiant');
define('DB_PASS','tssnadmin');
/*ouverture de la connexion à la base de données*/
$mydb = new mysqli(DB_ADDRESS, DB_USER, DB_PASS, DB_NAME);
/*lecture du contenu de la table*/
$resultat = $mydb->query("SELECT id, prenom, nom, classe FROM Eleve ORDER BY prenom");
while($obj_lu=$resultat->fetch_object())
echo 'Ligne : '.$obj_lu->id.' lue : '.$obj_lu->prenom.' '.$obj_lu->nom.' '.$obj_lu->classe.'<br/>';
/*fermeture de la connexion à la base de données*/
$mydb->close();
?>