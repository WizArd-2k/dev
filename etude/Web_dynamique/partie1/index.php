<?php
define("TXT_CONSTANTE","<br/><br/>Voici un premier programmme en php");

$txtBonjour = "Bonjour à tous <br/>";
$varQuestion = "Comment allez-vous ?";
$nbrePi = 3.14159;
$age = 19;
$tableauJour = array('Dimanche','Lundi','Mardi','Mercredi','Jeudi','Vendredi','Samedi');
$dateActuelle = getdate();
$numJourActuel = $dateActuelle['wday'];
echo "Une suite de phrase : ".$varTexte." ".$varQuestion.TXT_CONSTANTE;
echo ' Ajout de nombre dans une phrase : Pi ='.$nbrePi.' et votre age est probablement '.$age." ans... <br/>";
echo 'Aujourd\'hui nous sommes '.$tableauJour[$numJourActuel].' '.date("D M Y");
?>