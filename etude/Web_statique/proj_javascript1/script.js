var cntLine = 0;
function get_mess(couleur='blue'){
document.getElementById('btnAction').style.color=couleur;
document.getElementById('champTxt1').value="Click sur le bouton : "
+ document.getElementsByTagName('input')[1].name;
}
function write_mess(){
cntLine++;var itemBr = document.createElement("br");
var itemTxt = document.createTextNode("Ligne " + cntLine + " ecrite");
document.getElementById('parTxt1').appendChild(itemTxt);document.getElementById('parTxt1').appendChild(itemBr);
}

const child = document.getElementById('parTxt1').appendChild(itemTxt);
function clear_mess(){
    var parTxt1 = document.getElementById('parTxt1');
    if (parTxt1) {
        parTxt1.innerHTML = '';
    }
}