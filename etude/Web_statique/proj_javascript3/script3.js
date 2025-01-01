function enrCookie() {
    let prenom = document.getElementById('prenom').value
    let nom = document.getElementById('nom').value
    let age = document.getElementById('age').value
    var CookieValue = "prenom:"+  encodeURIComponent(prenom) + " "+" nom:" + encodeURIComponent(nom) + " "+ " age:" + encodeURIComponent(age);
    alert(CookieValue);
}
document.cookie = CookieValue + "domain=site.com"

function printCookie() {
    alert(document.cookie)
}