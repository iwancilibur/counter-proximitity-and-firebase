#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "uvuvuewvuew.firebaseio.com"
#define FIREBASE_AUTH "Ppe6QSHG6oHkFyhhjTpBqkC9WKqrenT8VqWsZ9ik"
#define WIFISSID "www.interactiverobotics.club" // Assign your WiFi SSID
#define PASSWORD  "cilibur2019" // Assign your WiFi password
#define id_device "001"

int ledPin = D7; // choose pin for the LED
int pinInput = D2; // choose input pin (for Infrared sensor)
int pinOutput = D3; // choose input pin (for Infrared sensor)
int sensorInput = 0; // variable for reading the pin status
int sensorOutput = 0; // variable for reading the pin status
int statusIn=0;
int statusOut=0;
int hitung=0;
int jeda=800;
void setup() 
{
Serial.begin(9600);
WiFi.begin(WIFISSID, PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(pinInput, INPUT); // declare Infrared sensor as input
  pinMode(pinOutput, INPUT); // declare Infrared sensor as input

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("id_device", id_device);
  Firebase.set("hitung", 0);
  
}

void bunyi(){
  unsigned char i, j ;
for (i = 0; i <20; i++) // When a frequency sound
    {
      digitalWrite (ledPin, HIGH) ; //send tone
      delay (1) ;
      digitalWrite (ledPin, LOW) ; //no tone
      delay (1) ;
    }
}

void loop(){
sensorInput = digitalRead(pinInput); // read input sensorInputue
sensorOutput = digitalRead(pinOutput); // read input sensorInputue   
if (sensorInput == HIGH) { // check if the input is HIGH
digitalWrite(ledPin, LOW); // turn LED OFF
} else {
bunyi();
statusIn=1;
}

if (sensorOutput == HIGH) { // check if the input is HIGH
digitalWrite(ledPin, LOW); // turn LED OFF
} else {
bunyi();
statusOut=1;
}

if (statusIn==1 && statusOut==1){
  hitung++;
  Firebase.setInt("hitung", hitung);
  Serial.println(hitung);
  delay(jeda);
  statusIn=0;
  statusOut=0;
}
}
