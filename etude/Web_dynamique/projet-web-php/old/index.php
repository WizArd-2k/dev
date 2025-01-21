<?php
define('DB_ADDRESS', 'localhost');
define('DB_NAME', 'server_web');
define('DB_USER', 'etudiant');
define('DB_PASS', 'admin');
$mydb =  new mysqli(DB_ADDRESS, DB_USER, DB_PASS, DB_NAME);
$affichage = $mydb->query("SELECT or_type, or_fk_id FROM organisation WHERE or_fk_na_id=1 ORDER BY or_position");
$affichage_lu = $affichage->fetch_object();

?>


<!doctype html>
<html lang="fr-FR">

<head>
    <title>Projet web d'apprentissage</title>
    <meta charset="utf-8" />
    <link href="./css/style.css" rel="stylesheet" />
</head>

<body>
    <header>
        <div id="logo"></div>
        <nav>
            <ul>
                <?php
                $navigation = $mydb->query("SELECT na_id, na_lien, na_nom FROM navigation ORDER BY na_id ASC");
                while ($obj_lu = $navigation->fetch_object()) {
                    echo '<li><a href="' . $obj_lu->na_lien . '.php">' . $obj_lu->na_nom . '</a></li>';
                }
                ?>
            </ul>
        </nav>
    </header>
    <main>
        <aside>
            <h3>Dernière nouvelles</h3>
            <h4>Nouveau site lancé</h4>
            <h5>Vendredi 10/09/2018</h5>
            <p id="test">Les spécificités du site.<a href="./a-propos.html"> Lire plus</a></p>
        </aside>
        <article>
            <?php
            while ($affichage_lu = $affichage->fetch_object()) {
                if ($affichage_lu->or_type == 'T') {
                    $result = $mydb->query("SELECT ti_content, ti_type FROM titre WHERE ti_id=$affichage_lu->or_fk_id")->fetch_object();
                    echo '<h' . $result->ti_type . '>' . $result->ti_content . '</h' . $result->ti_type . '>';
                }
                if ($affichage_lu->or_type == 'P') {
                    $result = $mydb->query("SELECT pa_content FROM paragraphe WHERE pa_id=$affichage_lu->or_fk_id")->fetch_object();
                    echo '<p>' . $result->pa_content . '<p>';
                }
            }

            ?>
        </article>

    </main>
    <footer>Footer</footer>
</body>

</html>