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

    //Eine Zahl zwischen 0 und 2 festlegen, man halt also 3 Varianten: 0, 1, 2
    variation = (variation + 1) % 3;

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
      case 99:
        servo_forwardMove2();
        break;
      default:
      servo_forwardMove();
    }
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
  }
}


//Hier sind die verschiedenen Vor- und Zurückbewegungen definiert.
//Vorwärts
void servo_forwardMove(){
  myservo.write(minValue);
}

void servo_forwardMove0(){
  myservo.write(minValue);
}

void servo_forwardMove1(){
  myservo.write(minValue);
}

void servo_forwardMove2(){
  myservo.write(minValue);
}

//Rückwärts
void servo_backwardMove(){
  myservo.write(maxValue);
  delay(200);
  myservo.write(minValue + 20);
}

void servo_backwardMove0(){
  //Der Servo soll auf Position maxValue fahren.
  myservo.write(maxValue);
}

void servo_backwardMove1(){
  myservo.write(maxValue);
}

void servo_backwardMove2(){
  myservo.write(maxValue);
}

//Kleine Funktion zum Umrechnen von Werten.
int ranger(int min, int max, int ratio){
  //Und hier ist das, wo man Mathe braucht:
  int value = min + ((max - min) / 100 ) * ratio;
  //Das Berechnete als Integer(Ganzzahl) zurückgeben.
  return value;
}