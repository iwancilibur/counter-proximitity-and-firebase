 var firebaseConfig = {
    apiKey: "AIzaSyCTlV5x-uF5NCT7_1sh8xju1BwdQBIMFks",
    authDomain: "uvuvuewvuew.firebaseapp.com",
    databaseURL: "https://uvuvuewvuew.firebaseio.com",
    projectId: "uvuvuewvuew",
    storageBucket: "uvuvuewvuew.appspot.com",
    messagingSenderId: "372303422902",
    appId: "1:372303422902:web:bc70c14dd5c274cd"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  

  const id_device = document.getElementById('id_device'); //mengambil data dari parameter id_device
  const dbRef = firebase.database().ref().child('id_device'); //mengambil data dari firebase database dengan nama id_device
  dbRef.on('value', snap => id_device.innerText = snap.val()); //menaruh nilai id_device kedalam kolom yang sudah disediakan
  
  const hitung = document.getElementById('hitung'); //mengambil data dari parameter hitung
  const dbRef2 = firebase.database().ref().child('hitung'); //mengambil data dari firebase database dengan nama hitung
  dbRef2.on('value', snap => hitung.innerText = snap.val()); //menaruh nilai hitung kedalam kolom yang sudah disediakan
  
  var db = firebase.database(); //membuat variabel dari firebase database dengan nama db
	  
   var relay1 = db.ref('relay1'); //membuat variabel bernama relay1 dengan berisikan relay1
      relay1.on('value', function(snapshot) { //membuat fungsi isi dari variabel relay1
        console.log("relay1: "+snapshot.val()); //mengambil nilai console log relay3
        if(snapshot.val()) document.querySelector("#relay1").style.background = 'rgb(255, 100, 100)'; //jika relay diberi inputan 1 maka akan berubah warna background menjadi biru
        if(!snapshot.val()) document.querySelector("#relay1").style.background = 'transparent'; //jika relay diberi inputan 0 maka akan berubah warna background menjadi putih transparant
        document.querySelector("#Lampu1 > input").checked = snapshot.val(); //memberikan informasi bahwa lampu1 memberikan inputan
      }); //simbol untuk menutup fungsi
	  
			
	