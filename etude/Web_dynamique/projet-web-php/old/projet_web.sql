-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mar. 21 jan. 2025 à 19:27
-- Version du serveur : 10.11.6-MariaDB-0+deb12u1
-- Version de PHP : 8.2.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `projet_web`
--

-- --------------------------------------------------------

--
-- Structure de la table `contact`
--

CREATE TABLE `contact` (
  `co_id` int(10) UNSIGNED NOT NULL,
  `co_genre` char(1) NOT NULL,
  `co_nom` varchar(100) NOT NULL,
  `co_prenom` varchar(100) NOT NULL,
  `co_telephone` varchar(20) NOT NULL,
  `co_email` tinytext NOT NULL,
  `co_sujet` varchar(100) NOT NULL,
  `co_message` tinytext NOT NULL,
  `co_datetime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Structure de la table `navigation`
--

CREATE TABLE `navigation` (
  `na_id` int(10) UNSIGNED NOT NULL,
  `na_lien` tinytext NOT NULL,
  `na_nom` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `navigation`
--

INSERT INTO `navigation` (`na_id`, `na_lien`, `na_nom`) VALUES
(1, 'index', 'Accueil'),
(2, 'a-propos', 'A propos'),
(3, 'blog', 'Blog'),
(4, 'contact', 'Contactez-nous');

-- --------------------------------------------------------

--
-- Structure de la table `organisation`
--

CREATE TABLE `organisation` (
  `or_id` int(10) UNSIGNED NOT NULL,
  `or_type` char(1) NOT NULL,
  `or_position` tinyint(3) UNSIGNED NOT NULL,
  `or_fk_id` int(10) UNSIGNED NOT NULL,
  `or_fk_na_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `organisation`
--

INSERT INTO `organisation` (`or_id`, `or_type`, `or_position`, `or_fk_id`, `or_fk_na_id`) VALUES
(1, 'T', 1, 1, 1),
(2, 'T', 2, 2, 1),
(3, 'P', 3, 1, 1),
(4, 'T', 4, 3, 1),
(5, 'T', 5, 4, 1),
(6, 'P', 6, 2, 1),
(7, 'T', 7, 5, 1),
(8, 'P', 8, 3, 1),
(9, 'T', 9, 6, 1),
(10, 'P', 10, 4, 1);

-- --------------------------------------------------------

--
-- Structure de la table `page`
--

CREATE TABLE `page` (
  `pa_id` int(10) UNSIGNED NOT NULL,
  `pa_contenu` text NOT NULL,
  `pa_datetime` datetime NOT NULL,
  `pa_fk_navigation_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `page`
--

INSERT INTO `page` (`pa_id`, `pa_contenu`, `pa_datetime`, `pa_fk_navigation_id`) VALUES
(1, ' <h2>Un titre secondaire </h2>\n            \n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>\n             <h2>Un deuxième titre secondaire </h2>\n             <h3>Un premier titre de niveau 3</h3>\n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n<h3>Un second titre de niveau 3</h3>\nLorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>\n<h2>Un dernier titre secondaire</h2>\n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.<br/>\n\nLorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>', '2024-12-11 10:34:13', 1),
(2, ' Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut quis vulputate nunc. Etiam eu tempus justo, sit amet luctus enim. Nullam ut sapien euismod, pellentesque sapien nec, molestie mi. Maecenas cursus in neque a blandit. Sed vitae nunc et felis vulputate pretium. Morbi faucibus est eget erat molestie dapibus. Donec quis vehicula mi. Ut tortor arcu, pellentesque sed accumsan vel, aliquam sed nibh. Maecenas egestas rhoncus rhoncus. In hac habitasse platea dictumst. Cras id justo eget arcu volutpat interdum et sed urna. Fusce pharetra eleifend felis, vel auctor lectus suscipit vitae. Phasellus eu enim leo. Mauris sed leo a arcu ullamcorper ullamcorper nec nec neque. Pellentesque porta fermentum leo.\r\n\r\nProin sed mattis orci, imperdiet consequat dolor. Aenean non tempus ante. Vestibulum suscipit velit odio, eu hendrerit orci dignissim ut. Maecenas maximus ornare mattis. Pellentesque turpis felis, pharetra vitae volutpat vitae, vehicula sed elit. Cras bibendum elementum imperdiet. Pellentesque commodo libero eget urna tincidunt venenatis. Aliquam erat volutpat. Proin suscipit venenatis iaculis. Etiam vitae posuere urna. ', '2024-12-11 10:38:10', 2),
(3, '<html>\r\n  <head>\r\n    <title></title>\r\n    <meta content=\"\">\r\n    <style></style>\r\n  </head>\r\n  <body></body>\r\n</html>', '2024-12-17 13:09:44', 3),
(4, '<!doctype html>\r\n<html>\r\n    <head>\r\n        <title>Projet web d\'apprentissage</title>\r\n        <meta charset=\"utf-8\" />\r\n        <link href=\"./css/style.css\" rel=\"stylesheet\" />\r\n\r\n\r\n    </head>\r\n    <body>\r\n        <header>\r\n            <div id=\"logo\"></div>\r\n            <nav>\r\n                <ul>\r\n                    <li><a href=\"index.html\">Accueil</a></li>\r\n                    <li><a href=\"a-propos.html\">A propos</a></li>\r\n                    <li><a href=\"blog.html\">Blog</a></li>\r\n                    <li><a href=\"contact.html\">Contactez-nous</a></li>                    \r\n                </ul>\r\n            </nav>\r\n        </header>\r\n        <main>\r\n            <aside>\r\n                <section>\r\n                    <h3>Dernière nouvelles</h3>\r\n					<h4>Nouveau site lancé !</h4>\r\n					<h5>Vendredi 10/09/2018</h5>\r\n					<p>Les spécificités du site. <a href=\"#\">Lire plus</a></p>\r\n                </section>            \r\n            </aside>\r\n            <section><h1>Formulaire de contact</h1>\r\n                <div>\r\n                    <form action=\"traitement.php\" method=\"GET\"> \r\n                        <p class=\"first-p\"><label for=\"M\"><strong>Mr </strong></label><input type=\"radio\" id=\"M\" value=\"M\" name=\"Genre\" />\r\n                        <label for=\"F\"><strong>Mme </strong></label><input type=\"radio\" id=\"F\" value=\"F\" name=\"Genre\" /></p>\r\n                        <p><label for=\"Nom\" class=\"etiquette\"><strong>Nom : </strong></label><input type=\"text\" value=\"\" id=\"Nom\" name=\"Nom\" /></p>\r\n                        <p><label for=\"Prenom\" class=\"etiquette\"><strong>Prénom : </strong></label><input type=\"text\" value=\"\" id=\"Prenom\" name=\"Prenom\" /></p>\r\n                        <p><label for=\"Telephone\" class=\"etiquette\"><strong>Téléphone : </strong></label><input type=\"text\" value=\"\" id=\"Telephone\" name=\"Telephone\" /></p>\r\n                        <p><label for=\"Email\" class=\"etiquette\"><strong>Email : </strong></label><input type=\"email\" value=\"\" id=\"Email\" name=\"Email\" /></p>\r\n                        <p><label for=\"Sujet\" class=\"etiquette\"><strong>Sujet : </strong></label><input type=\"text\" value=\"\" id=\"Sujet\" name=\"Sujet\" /></p>\r\n                        <p><label for=\"Message\" class=\"etiquette\"><strong>Message : </strong></label><textarea id=\"Message\" name=\"Message\"></textarea></p>\r\n                    </form>\r\n                </div>\r\n            </section>\r\n        </main>\r\n        <footer>Footer</footer>\r\n    </body>\r\n</html>\r\n', '2024-12-17 13:09:44', 4);

-- --------------------------------------------------------

--
-- Structure de la table `paragraphe`
--

CREATE TABLE `paragraphe` (
  `pa_id` int(10) UNSIGNED NOT NULL,
  `pa_content` text NOT NULL,
  `pa_datetime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `paragraphe`
--

INSERT INTO `paragraphe` (`pa_id`, `pa_content`, `pa_datetime`) VALUES
(1, 'orem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.', '2024-12-17 14:16:27'),
(2, 'Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem.', '2024-12-17 14:17:16'),
(3, 'Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?', '2024-12-17 14:19:02'),
(4, 'But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful.', '2024-12-17 14:19:24'),
(5, '<h4>Nouveau site lancé</h4>\r\n<h5>Vendredi 10/09/2018</h5>', '2025-01-21 18:53:39'),
(6, ' <p id=\"test\">Les spécificités du site.<p>', '2025-01-21 19:10:32');

-- --------------------------------------------------------

--
-- Structure de la table `titre`
--

CREATE TABLE `titre` (
  `ti_id` int(11) NOT NULL,
  `ti_content` text NOT NULL,
  `ti_type` tinyint(3) UNSIGNED NOT NULL,
  `ti_created_at` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `titre`
--

INSERT INTO `titre` (`ti_id`, `ti_content`, `ti_type`, `ti_created_at`) VALUES
(1, 'Le plus gros titre', 1, '2024-12-11 08:49:55'),
(2, 'Un titre secondaire', 2, '2024-12-11 09:21:10'),
(3, 'Un deuxième titre secondaire', 2, '2024-12-11 09:36:44'),
(4, 'Un premier titre de niveau 3', 3, '2024-12-11 09:33:47'),
(5, 'Un second titre de niveau 3', 3, '2024-12-11 09:43:38'),
(6, 'Un dernier titre secondaire', 2, '2024-12-11 09:45:13');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `contact`
--
ALTER TABLE `contact`
  ADD PRIMARY KEY (`co_id`);

--
-- Index pour la table `navigation`
--
ALTER TABLE `navigation`
  ADD PRIMARY KEY (`na_id`);

--
-- Index pour la table `organisation`
--
ALTER TABLE `organisation`
  ADD PRIMARY KEY (`or_id`),
  ADD KEY `or_fk_id` (`or_fk_id`),
  ADD KEY `or_fk_na_id` (`or_fk_na_id`);

--
-- Index pour la table `page`
--
ALTER TABLE `page`
  ADD PRIMARY KEY (`pa_id`),
  ADD KEY `pa_fk_navigation_id` (`pa_fk_navigation_id`);

--
-- Index pour la table `paragraphe`
--
ALTER TABLE `paragraphe`
  ADD PRIMARY KEY (`pa_id`);

--
-- Index pour la table `titre`
--
ALTER TABLE `titre`
  ADD PRIMARY KEY (`ti_id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `contact`
--
ALTER TABLE `contact`
  MODIFY `co_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `navigation`
--
ALTER TABLE `navigation`
  MODIFY `na_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `organisation`
--
ALTER TABLE `organisation`
  MODIFY `or_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `page`
--
ALTER TABLE `page`
  MODIFY `pa_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `paragraphe`
--
ALTER TABLE `paragraphe`
  MODIFY `pa_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `titre`
--
ALTER TABLE `titre`
  MODIFY `ti_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `page`
--
ALTER TABLE `page`
  ADD CONSTRAINT `page_ibfk_1` FOREIGN KEY (`pa_fk_navigation_id`) REFERENCES `navigation` (`na_id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
