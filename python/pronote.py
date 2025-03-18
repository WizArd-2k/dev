import requests
from bs4 import BeautifulSoup

# URL de la page de connexion
login_url = 'http://194.167.101.67/pronote/eleve.html?login=true'

# Informations de connexion
payload = {
    'username': 'BDEFOSSEZ',
    'password': 'Baptiste-d1611*'
}

# Créer une session pour maintenir les cookies de connexion
with requests.Session() as session:
    # Envoyer une requête GET pour obtenir les tokens CSRF si nécessaire
    response = session.get(login_url)
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # Si le site utilise un token CSRF, vous devrez l'extraire du formulaire
    # csrf_token = soup.find('input', {'name': 'csrf_token_name'})['value']
    # payload['csrf_token_name'] = csrf_token

    # Envoyer une requête POST pour se connecter
    response = session.post(login_url, data=payload)
    
    # Vérifier si la connexion a réussi
    if 'Bienvenue' in response.text:
        print("Connexion réussie!")
        # Vous pouvez maintenant accéder à d'autres pages en utilisant la session
        # Par exemple, accéder à la page d'accueil après connexion
        home_page = session.get('http://194.167.101.67/pronote/eleve.html')
        print(home_page.text)
    else:
        print("Échec de la connexion")