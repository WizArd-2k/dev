<?php
if(isset($_GET['nom']) && isset($_GET['prenom']) && isset($_GET['age']))
    echo 'Vous êtes : ' .$_GET['prenom'].' '.$_GET['nom']. ' et avez ' .$_GET['age'].' ans';
else
    echo 'Il manque un ou plusieur paramètres';
?>