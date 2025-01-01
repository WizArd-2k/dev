<?php
echo '<html><head></head><body>';
if(isset($_POST['nom']) && isset($_POST['prenom']) && isset($_POST['age']))
echo 'Vous êtes : '.$_POST['prenom'].' '.$_POST['nom'].' et avez '.$_POST['age']. ' ans';
else
echo 'Il manque un ou plusieurs paramètres <br/>'."\n";
echo '<form method="post" name="formulaire">
<input type="text" name="nom" value="" placeholder="Votre nom"/>
<input type="text" name="prenom" value="" placeholder="Votre prénom"/>
<input type="number" name="age" value="" placeholder="Votre age"/>
<input type="submit" value="envoyer"/>
</form>
</body></html>';
?>