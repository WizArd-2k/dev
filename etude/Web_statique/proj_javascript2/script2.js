
function get_datetime(){
    var date_time = new Date();
    var jours = ["Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"];
    var hrs = date_time.getHours();
    var min = date_time.getMinutes();
    var sec = date_time.getSeconds();
    var jrs = date_time.getDate();
    var mth = date_time.getMonth()+1;
    var jour = jours[date_time.getDay()];
    document.getElementById('champTxt1').value="Jour :" + jour+"Date:"+jrs+"/"+mth+" Heures: "
    +hrs+":"+min+":"+sec;

}
function Time_update(){
    get_datetime();
    setInterval(get_datetime,1000);
}