#include <Servo.h>

Servo myservo;

int minValue = 90;
int maxValue = 160;

bool switch_active;
bool last_switch_state = LOW;
int last_servo_position = -1; // Speichert die letzte Servo-Position

int PIN_SERVO = 10;
int PIN_SWITCH_ON = 12;
int PIN_SWITCH_OFF = 11;
bool state_off = false;
int variation = 0;

void setup() {
  myservo.attach(PIN_SERVO);
  pinMode(PIN_SWITCH_ON, INPUT_PULLUP);
  pinMode(PIN_SWITCH_OFF, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIN_SWITCH_ON) == HIGH && digitalRead(PIN_SWITCH_OFF) == LOW && state_off == true) {
    state_off = false;
    variation = (variation + 1) % 3;
    Serial.println("ON");
    Serial.println(variation);
    
    switch (variation){
      case 0:
        servo_defaultMove();
        break;
      case 1:
        servo_defaultMove1();
        break;
      case 99:
        servo_defaultMove2();
        break;
      default:
      servo_defaultMove();
    }
  } 
  else if (digitalRead(PIN_SWITCH_ON) == LOW && digitalRead(PIN_SWITCH_OFF) == HIGH && state_off == false) {
    state_off = true;
    Serial.println("OFF");
    
    switch (variation){
      case 0:
        servo_backMove0();
        break;
      case 1:
        servo_backMove0();
        break;
      case 2:
        servo_backMove();
        break;
      default:
      servo_backMove();
    }
  }
}



void servo_backMove(){
  myservo.write(maxValue);
  delay(300);
  myservo.write(maxValue - 10);
}

void servo_backMove0(){
  myservo.write(maxValue);
}

void servo_backMove1(){
  myservo.write(maxValue);
}

void servo_backMove2(){
  myservo.write(maxValue);
}

void servo_defaultMove(){
  myservo.write(minValue);
}

void servo_defaultMove0(){
  myservo.write(minValue);
}

void servo_defaultMove1(){
  myservo.write(minValue);
}

void servo_defaultMove2(){
  myservo.write(minValue);
}

int ranger(int min, int max, int ratio){
  int value = min + ((max - min) / 100 ) * ratio;
  return value;
}