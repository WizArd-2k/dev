<?php
// Connexion à la base de données
$host = "localhost"; // Remplacez par l'hôte de votre base de données
$dbname = "projet_web"; // Remplacez par votre nom de base de données
$username = "etudiant"; // Remplacez par votre utilisateur
$password = "tssnadmin"; // Remplacez par votre mot de passe

try {
    // Connexion à la base de données avec PDO
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    // Vérifier si le formulaire a été soumis
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Récupérer les données du formulaire
        $genre = $_POST['Genre'];
        $nom = $_POST['Nom'];
        $prenom = $_POST['Prenom'];
        $telephone = $_POST['Telephone'];
        $email = $_POST['Email'];
        $sujet = $_POST['Sujet'];
        $message = $_POST['Message'];

        // Préparer la requête d'insertion
        $sql = "INSERT INTO contact_form (genre, nom, prenom, telephone, email, sujet, message) 
                VALUES (:genre, :nom, :prenom, :telephone, :email, :sujet, :message)";

        $stmt = $pdo->prepare($sql);

        // Lier les paramètres à la requête SQL
        $stmt->bindParam(':genre', $genre);
        $stmt->bindParam(':nom', $nom);
        $stmt->bindParam(':prenom', $prenom);
        $stmt->bindParam(':telephone', $telephone);
        $stmt->bindParam(':email', $email);
        $stmt->bindParam(':sujet', $sujet);
        $stmt->bindParam(':message', $message);

        // Exécuter la requête d'insertion
        $stmt->execute();

        // Message de confirmation
        echo "Merci pour votre message ! Il a bien été envoyé.";
    }
} catch (PDOException $e) {
    // Gestion des erreurs de connexion à la base de données
    echo "Erreur : " . $e->getMessage();
}
?>
