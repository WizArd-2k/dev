<?php
$nomFichier = 'fichierReservation.txt';
echo '<html><head></head><body>';
if(isset($_POST['nom']) && isset($_POST['prenom']) && isset($_POST['age'])) {
echo 'Vous êtes : '.htmlspecialchars($_POST['prenom']).' '.htmlspecialchars($_POST['nom']).' et avez
'.htmlspecialchars($_POST['age']).' ans';
    echo 'Il manque un ou plusieurs paramètres <br/>'."\n";
if(!$fluxFichier = fopen($nomFichier,"a"))
echo "Impossible d'ouvrir le fichier ($nomFichier)";
else{
fwrite($fluxFichier, htmlspecialchars($_POST['nom']).' '.htmlspecialchars($_POST['prenom']).'
'.htmlspecialchars($_POST['age'])."\n");
fclose($fluxFichier);
}
}
else
echo 'Il manque un ou plusieurs paramètres <br/>'."\n";
echo '<form method="post" name="formulaire">
<input type="text" name="nom" value="" placeholder="Votre nom"/>
<input type="text" name="prenom" value="" placeholder="Votre prénom"/>
<input type="number" name="age" value="" placeholder="Votre age"/>
<input type="submit" value="envoyer"/>
</form>
</body></html>';