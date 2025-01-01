<?php

$dateActuelle = getdate();
$numJourActuel = $dateActuelle['wday'];

switch ($numJourActuel){
    case 0:
        echo 'Nous sommes Dimanche, bon week-end !';
        break;
    case 1:
        echo 'Nous sommes Lundi, le début de la semaine';
        break;
    case 2:
        echo 'Nous sommes Mardi';
        break;
    case 3:
        echo 'Nous sommes Mercredi, le mileu de la semaine, encore 3 jours';
        break;
    case 4:
        echo 'Nous sommes Jeudi, plus que 2 jours';
        break;
    case 5:
        echo 'Nous sommes Vendredi, plus que 1 jour';
        break;
    case 6:
        echo 'Nous sommes Samedi, dernier jours de travail de la semaine !';
        break;
    default :
        echo 'Tiens, un nouveau jour existe?';
}
?>