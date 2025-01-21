<?php
require 'bdd.php';


if (isset($_GET['page'])) {
    $page = $_GET['page'];
} else {
    $page = '#index'; 
}


switch ($page) {
    case "#index":
        $pageId = 1;
        break;
    case "#a-propos":
        $pageId = 2;
        break;
    case "#contact":
        $pageId = 3;
        break;
    case "#blog":
        $pageId = 4;
        break;
    default:
        $pageId = 1; 
        break;
}

$pageId = (int)$pageId;
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
                    echo '<li><a href="?page=' . $obj_lu->na_lien . '">' . $obj_lu->na_nom . '</a></li>';
                }
                ?>
            </ul>
        </nav>
    </header>

    <main>
        <aside>
            <h3>Dernières nouvelles</h3>
            <h4>Nouveau site lancé</h4>
            <h5>Vendredi 10/09/2018</h5>
            <p id="test">Les spécificités du site.<a href="./a-propos.html"> Lire plus</a></p>
        </aside>

        <article>
            <?php
            $stmt = $mydb->prepare("SELECT or_type, or_fk_id FROM organisation WHERE or_fk_na_id = (SELECT na_id FROM navigation WHERE na_lien = ?) ORDER BY or_position");
            $stmt->bind_param("s", $page);
            $stmt->execute();
            $affichage = $stmt->get_result();


            if ($affichage->num_rows > 0) {
                while ($affichage_lu = $affichage->fetch_object()) {
                    if ($affichage_lu->or_type == 'T') {

                        $result = $mydb->query("SELECT ti_content, ti_type FROM titre WHERE ti_id = " . $affichage_lu->or_fk_id)->fetch_object();
                        echo '<h' . $result->ti_type . '>' . $result->ti_content . '</h' . $result->ti_type . '>';
                    }
                    if ($affichage_lu->or_type == 'P') {
 
                        $result = $mydb->query("SELECT pa_content FROM paragraphe WHERE pa_id = " . $affichage_lu->or_fk_id)->fetch_object();
                        echo '<p>' . $result->pa_content . '</p>';
                    }
                }
            } else {
                echo "Aucune donnée trouvée pour cette page.";
            }
            ?>
        </article>
    </main>

    <footer>Footer</footer>
</body>

</html>
