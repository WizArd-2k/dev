<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
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
    case "#blog":
        $pageId = 3;
        break;
    case "#contact":
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
            <?php
                $popup = $mydb->query('SELECT pop_content FROM popup ORDER BY pop_id ASC');
                $popup = $popup->fetch_object();
                echo ''. $popup->pop_content .  '';
                
            ?>
            <a href="?page=contact"> Lire plus</a></p>
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
         <?php
         try {
            $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            die("Could not connect to the database $dbname :" . $e->getMessage());
        }
         if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $genre = $_POST['Genre'];
            $nom = $_POST['Nom'];
            $prenom = $_POST['Prenom'];
            $telephone = $_POST['Telephone'];
            $email = $_POST['Email'];
            $sujet = $_POST['Sujet'];
            $message = $_POST['Message'];
            try {
                
                $sql = "INSERT INTO contacts (genre, nom, prenom, telephone, email, sujet, message) VALUES (?, ?, ?, ?, ?, ?, ?)";
                $stmt = $pdo->prepare($sql);
                $stmt->execute([$genre, $nom, $prenom, $telephone, $email, $sujet, $message]);
                echo "Données enregistrées avec succès!";
            } catch (PDOException $e) {
                echo "Erreur lors de l'enregistrement des données: " . $e->getMessage();
            }
        }
        $affichage_lu = null;
        if ($affichage->num_rows > 0) {
        while ($obj = $affichage->fetch_object()) {
            if ($obj->or_fk_na_id == 4) {
?>
             <section>
                <h1>Formulaire de contact</h1>
                <div>
                    <form action="contact.php" method="POST"> 
                        <p class="first-p">
                            <label for="M"><strong>Mr </strong></label>
                            <input type="radio" id="M" value="M" name="Genre" />
                            <label for="F"><strong>Mme </strong></label>
                            <input type="radio" id="F" value="F" name="Genre" />
                        </p>
                        <p>
                            <label for="Nom" class="etiquette"><strong>Nom : </strong></label>
                            <input type="text" value="" id="Nom" name="Nom" required />
                        </p>
                        <p>
                            <label for="Prenom" class="etiquette"><strong>Prénom : </strong></label>
                            <input type="text" value="" id="Prenom" name="Prenom" required />
                        </p>
                        <p>
                            <label for="Telephone" class="etiquette"><strong>Téléphone : </strong></label>
                            <input type="text" value="" id="Telephone" name="Telephone" required />
                        </p>
                        <p>
                            <label for="Email" class="etiquette"><strong>Email : </strong></label>
                            <input type="email" value="" id="Email" name="Email" required />
                        </p>
                        <p>
                            <label for="Sujet" class="etiquette"><strong>Sujet : </strong></label>
                            <input type="text" value="" id="Sujet" name="Sujet" required />
                        </p>
                        <p>
                            <label for="Message" class="etiquette"><strong>Message : </strong></label>
                            <textarea id="Message" name="Message" required></textarea>
                        </p>
                        <p>
                            <input type="submit" value="Envoyer" />
                        </p>
                    </form>
                </div>
            </section>
<?php
            }
        }
    } else {
        echo "Aucune donnée trouvée.";
    }
?>
    </main>

    <footer>Footer</footer>
</body>

</html>
