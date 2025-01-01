-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mer. 11 déc. 2024 à 11:03
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
-- Structure de la table `page`
--

CREATE TABLE `page` (
  `pa_id` int(10) UNSIGNED NOT NULL,
  `pa_titre` tinytext NOT NULL,
  `pa_contenu` text NOT NULL,
  `pa_datetime` datetime NOT NULL,
  `pa_fk_navigation_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `page`
--

INSERT INTO `page` (`pa_id`, `pa_titre`, `pa_contenu`, `pa_datetime`, `pa_fk_navigation_id`) VALUES
(1, 'Le plus gros titre', ' <h2>Un titre secondaire </h2>\r\n            \r\n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>\r\n             <h2>Un deuxième titre secondaire </h2>\r\n             <h3>Un premier titre de niveau 3</h3>\r\n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\r\n<h3>Un second titre de niveau 3</h3>\r\nLorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>\r\n<h2>Un dernier titre secondaire</h2>\r\n<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.<br/>\r\n\r\nLorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>', '2024-12-11 10:34:13', 1),
(2, 'A Propos de nous', ' Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut quis vulputate nunc. Etiam eu tempus justo, sit amet luctus enim. Nullam ut sapien euismod, pellentesque sapien nec, molestie mi. Maecenas cursus in neque a blandit. Sed vitae nunc et felis vulputate pretium. Morbi faucibus est eget erat molestie dapibus. Donec quis vehicula mi. Ut tortor arcu, pellentesque sed accumsan vel, aliquam sed nibh. Maecenas egestas rhoncus rhoncus. In hac habitasse platea dictumst. Cras id justo eget arcu volutpat interdum et sed urna. Fusce pharetra eleifend felis, vel auctor lectus suscipit vitae. Phasellus eu enim leo. Mauris sed leo a arcu ullamcorper ullamcorper nec nec neque. Pellentesque porta fermentum leo.\r\n\r\nProin sed mattis orci, imperdiet consequat dolor. Aenean non tempus ante. Vestibulum suscipit velit odio, eu hendrerit orci dignissim ut. Maecenas maximus ornare mattis. Pellentesque turpis felis, pharetra vitae volutpat vitae, vehicula sed elit. Cras bibendum elementum imperdiet. Pellentesque commodo libero eget urna tincidunt venenatis. Aliquam erat volutpat. Proin suscipit venenatis iaculis. Etiam vitae posuere urna. ', '2024-12-11 10:38:10', 2);

-- --------------------------------------------------------

--
-- Structure de la table `titre`
--

CREATE TABLE `titre` (
  `id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `content` text NOT NULL,
  `created_at` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `titre`
--

INSERT INTO `titre` (`id`, `title`, `content`, `created_at`) VALUES
(1, 'Your Article Title', 'Le plus gros titre', '2024-12-11 08:49:55'),
(2, '2eme titre', 'Un titre secondaire', '2024-12-11 09:21:10'),
(3, 'titre 3', 'Un premier titre de niveau 3', '2024-12-11 09:33:47'),
(4, 'titre 2 secondaire', 'Un deuxième titre secondaire', '2024-12-11 09:36:44'),
(5, 'titre 3 secondaire', 'Un second titre de niveau 3', '2024-12-11 09:43:38'),
(6, 'dernier titre secondaire', 'Un dernier titre secondaire', '2024-12-11 09:45:13'),
(7, 'Footer', 'Copyright 2024-2025', '2024-12-11 09:49:06');

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
-- Index pour la table `page`
--
ALTER TABLE `page`
  ADD PRIMARY KEY (`pa_id`),
  ADD KEY `pa_fk_navigation_id` (`pa_fk_navigation_id`);

--
-- Index pour la table `titre`
--
ALTER TABLE `titre`
  ADD PRIMARY KEY (`id`);

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
-- AUTO_INCREMENT pour la table `page`
--
ALTER TABLE `page`
  MODIFY `pa_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `titre`
--
ALTER TABLE `titre`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

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
