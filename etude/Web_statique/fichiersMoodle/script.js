/******************************************************************
 * 
 * déclaration et initialisation des variables globales utilisées
 * 
 ******************************************************************/
var compteur = 0;   // compteur d'animation
var compteurMax = 0; // nombre maximale d'animation dans une séquence
var idAnimation;    // identificateur du timer de l'animation
var etatOnOff = 0;  // état "allumé" ou "éteint" des couleurs
var sequence = [];  // tableau contenant la séquence de l'animation
sequence[0] = 0;    // initialisation de la case 0 du tableau à 0 pour indiquer le début de l'animation

/******************************************************************
 * 
 * déclaration et définition des fonctions utilisées pour réaliser le jeu
 * 
 ******************************************************************/
function on_off(idTouche, etat) {
    if (etat == 1) {
        switch (idTouche) {
            case 1: document.getElementById('couleur1').style.backgroundColor = "#ff0000"; break;
            case 2: document.getElementById('couleur2').style.backgroundColor = "#00ff00"; break;
            case 3: document.getElementById('couleur3').style.backgroundColor = "#0000ff"; break;
            case 4: document.getElementById('couleur4').style.backgroundColor = "#ffff00"; break;
            case 5: document.getElementById('couleur5').style.backgroundColor = "#00d9ff"; break;
            case 6: document.getElementById('couleur6').style.backgroundColor = "#747272"; break;
        }
    } else {
        document.getElementById('couleur1').style.backgroundColor = "#5f0000";
        document.getElementById('couleur2').style.backgroundColor = "#005f00";
        document.getElementById('couleur3').style.backgroundColor = "#00005f";
        document.getElementById('couleur4').style.backgroundColor = "#5f5f00";
        document.getElementById('couleur5').style.backgroundColor = "#28b0c8";
        document.getElementById('couleur6').style.backgroundColor = "#b1b189";
    }
}

function readClicOnTouche(idTouche) {
    if (sequence[0] == 0) {
        document.getElementById('message').value = "C'est parti !";
        initSequence();
    } else {
        if (idTouche == sequence[compteur]) {
            compteur++;
            if (compteur > compteurMax) {
                initSequence();
            }
        } else {
            document.getElementById('message').value = "Erreur !! Appuyer sur une couleur pour recommencer";
            sequence[0] = 0;
            compteur = 0;
        }
    }
}

function initSequence() {
    compteurMax = compteur; 
    compteur = 0;           
    sequence[compteurMax] = getNbreAleatoire(); 
    animSequence();         
}

function getNbreAleatoire() {
    var nbreAleatoire;
    do {
        nbreAleatoire = Math.floor((Math.random() * 6000) + 1); 
    } while (nbreAleatoire > 6);
    return nbreAleatoire;
}

function animSequence() {
    clearInterval(idAnimation); 
    idAnimation = setInterval(function() {
        if (etatOnOff == 0) {
            on_off(sequence[compteur], 1); 
            etatOnOff = 1;                  
        } else {
            on_off(sequence[compteur], 0); 
            etatOnOff = 0;                  
            compteur++;                     
            if (compteur > compteurMax) {
                clearInterval(idAnimation); 
                compteur = 0;               
                document.getElementById('message').value = "Séquence terminée. Appuyer sur une couleur pour continuer.";
            }
        }
    }, 150); 
}