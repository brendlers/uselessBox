/* Der graue Teil ist für Benutzer, zum lesen. Genau. Lesen.
  Dies ist ein kleines Arduino Projekt zum Betrieb einer Useless-Box.

  Die Useless Box besteht aus einem Servo, einem Schalter, einem Mikrocontroller und einigen Kunststoffteilen.

  Wenn der Benutzer den Schalter umlegt, ist die Maschine im Ein-Zustand. Nun betätigt der Servo den Schalter um wieder im Aus-Zustand zu sein.

  Die verwendeten PINS sind:
  
  Für den Servo:
  5V                                     an 5V
  GND                                    an GND
  Signal                                 an GPIO10

  Der Servo erhält seine Position über ein Rechtecksignal. Dieses ist wie folgt aufgebaut:

  |v
  |  _             _
  |_| |___________| |____________        O- Servowelle 180°
  |_________________________________t

  |v
  |  ______        _______               |
  |_|      |______|       |______        O  Servowelle 90°
  |_________________________________t

  |v
  |  ___________   ____________
  |_|           |_|            |_       -O  Servowelle 0°
  |_________________________________t



  Für den Taster:
  Position 2        (NO - Normal Open)   an GPIO11
  Mittlerer Kontakt (Common)             an GND
  Position 1        (NC - Normal Closed) an GPIO12

                   GND
                    o
            ________|________
          |         |       |
          |          \      |
          |           \     |
          | (NO)o      o(NC)|
          |_____|______|____|
                |      |
                o      o
              GPIO11 GPIO12

Ein Taster sollte immer mit einem PullUp-Widerstand verwendet werden.

          |        
          |      o
          |      |
          |     |-|
          |     |R|   Im Mikrocontroller
          |     |-|
          |      |
          |      o-------> GPIO-Pin
          |______|________________________
                 |
               \
       Taster   \
                 |
                 o
                GND

Andere Useless Machines verwenden andere PINs, andere Maße und andere Drehwerte, also minValue und maxValue!

WARNUNG! Je nach Einbauposition des Hebels kann Gehäuse, Arduino oder sonstiges **ZERSTÖRT** werden.
ACHTUNG! Im Programm sind aktuell die **Endpositionen** von **90 und 160** vorgesehen! wenn der **Servo** auf der **hinteren Endlage** steht, muss der **Hebel** in etwa **horizontal** angebracht werden!
ACTHUNG! Hardware-Projekte und Software-Projekte können NICHT beliebig abgeändert oder kombiniert werden!

HINWEIS: Vor dem verwenden neuer Software IMMER den Servo ausbauen! (Siehe Video)
*/

//Einbinden einer Biblithek aus Code-Stücken, die zum Verwenden eines Servos notwendig sind
#include <Servo.h>
//Erstellen eines Objektes vom Typ Servo mit dem Namen myservo.
Servo myservo;

//Festlegen von Variablen für End-Positionen
int minValue = 90;
int maxValue = 160;


//Festlegen von Variablen mit Pin-Zuweisungen
int PIN_SERVO = 10;
int PIN_SWITCH_ON = 12;
int PIN_SWITCH_OFF = 11;

//Zum 'Entprellen' des Schalters, eine Variable zum Speichern des letzten Schaltzustandes verwenden
bool last_switch_state = false;

//Variable mit der entschieden wird, wann welche Reaktion abgespielt wird.
int variation = 0;

//Code-Block, der einmal beim Anschalten des Arduinos ausgeführt wird.
void setup() {
  //Anbinden des Servos an den Servo-Pin
  myservo.attach(PIN_SERVO);
  //Anbinden des Schalted an die Schalter-Pins
  pinMode(PIN_SWITCH_ON, INPUT_PULLUP);
  pinMode(PIN_SWITCH_OFF, INPUT_PULLUP);
  //Anbinden der On-Board-LED an den Pin den Arduino dafür vorgesehen hat
  pinMode(LED_BUILTIN, OUTPUT);
  //Und weil wir sonst so gaaar nicht wissen, was der Arduino macht, lassen wir zu, dass er mit dem Computer spricht:
  //Festlegen der Geschwindigkeit (Baud) für den Serial-Port.
  Serial.begin(9600);
}

//Code-Block, der immer wieder durchlaufen wird, nachdem das Setup ausgeführt wurde.
void loop() {

  if (digitalRead(PIN_SWITCH_ON) == true && digitalRead(PIN_SWITCH_OFF) == false && last_switch_state == true) {
    //Den aktuellen Status als 'false' festlegen, wenn jetzt der Schalter wackelt, dann werden nicht alle oberen Bedingungen erfüllt und es gibt weniger Fehler
    last_switch_state = false;

    //Eine Zahl zwischen 0 und 3 festlegen, man halt also 4 Varianten: 0, 1, 2, 3
    variation = (variation + 1) % 4;

    //Dem Computer was zurufen.
    Serial.println("ON");
    Serial.println(variation);
    
    //Auswahl für Vorwärts-Bewegung
    switch (variation){
      case 0:
        servo_forwardMove0();
        break;
      case 1:
        servo_forwardMove1();
        break;
      case 2:
        servo_forwardMove2();
        break;
      default:
      servo_forwardMove();
    }
    Serial.println("DONE");
  } 
  else if (digitalRead(PIN_SWITCH_ON) == false && digitalRead(PIN_SWITCH_OFF) == true && last_switch_state == false) {
    //Den aktuellen Status als 'true' festlegen.
    last_switch_state = true;

    //Dem Computer was zurufen.
    Serial.println("OFF");
    
    //Auswahl für Rückwärts-Bewegung
    switch (variation){
      case 0:
        servo_backwardMove0();
        break;
      case 1:
        servo_backwardMove1();
        break;
      case 2:
        servo_backwardMove2();
        break;
      default:
      servo_backwardMove();
    }
    //Dem Computer was zurufen.
    Serial.println("DONE");
  }
}

//***********************************************************************
//
// Hier sind die verschiedenen Vor- und Zurückbewegungen definiert.
//
// Also wenn man was ändern möchte, am besten HIER:
//
//***********************************************************************
//Vorwärts
void servo_forwardMove(){
  myservo.write(minValue);
}

//Der Arm fährt langsam vor. So richtig langsam!
void servo_forwardMove0(){
  for (int pos = maxValue; pos > minValue; pos--){
    myservo.write(pos);
    delay(50);
  }
}

//Der Arm fährt zuerst ein Stück vor, um zu schauen was los ist, dann wartet er kurz und drückt den Taster.
void servo_forwardMove1(){
  delay(200);
  myservo.write(minValue + 30);
  delay(500);
  myservo.write(minValue);
}

//Der Arm fährt langsam vor. So richtig langsam! Aber mit Twist!
void servo_forwardMove2(){
  for (int pos = maxValue; pos > minValue + 30; pos--){
    myservo.write(pos);
    delay(80);
  }
  delay(200);
  myservo.write(minValue - 50);
  delay(200);
  myservo.write(minValue);
  
}

//Rückwärts
//Fährt zurück, wartet, und fährt dann vor um zu lauern!
void servo_backwardMove(){
  myservo.write(maxValue);
  delay(200);
  myservo.write(minValue + 20);
}

//Direkter Rückzug!
void servo_backwardMove0(){
  //Der Servo soll auf Position maxValue fahren.
  myservo.write(maxValue);
}

//In diesem Programm fährt der Arm erst zurück, dann vier Mal vor und zurück
void servo_backwardMove1(){
  myservo.write(maxValue);
  delay(200);
  myservo.write(minValue + 20);
  delay(200);
  myservo.write(minValue + 30);
  delay(200);
  myservo.write(minValue + 10);
  delay(200);
  myservo.write(minValue + 30);
}

//Hier fährt er direkt zurück.
void servo_backwardMove2(){
  myservo.write(maxValue);
}

// NICHT ANFASSEN! Bitte, bitte!
//Kleine Funktion zum Umrechnen von Werten.
int ranger(int min, int max, int ratio){
  //Und hier ist das, wo man Mathe braucht:
  int value = min + ((max - min) / 100 ) * ratio;
  //Das Berechnete als Integer(Ganzzahl) zurückgeben.
  return value;
}