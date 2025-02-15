Ein Servo ist eine spezielle Art von Motor. Natürlich gibt es hier auch wieder ganz unterschiedliche, aber ich beziehe mich ausschließlich auf Modellbau-Servos. Ein solcher Modellbau-Servo hat eine Motorwelle, die durch ein Eingangs-Signal positioniert wird.

Um einen Servo verwenden zu können:
```
//Einbinden einer Biblithek aus Code-Stücken, die zum Verwenden eines Servos notwendig sind
#include <Servo.h>

//Erstellen eines Objektes vom Typ Servo mit dem Namen myservo.
Servo myservo;
```

Im Setup Block muss man dem Servo einen Pin zuweisen:
```
void setup() {

  //Anbinden des Servos an den Servo-Pin

  myservo.attach(PIN_SERVO);
  ...
}
```

Und nun kann man direkt den Winkel des Servos angeben.
```
  myservo.write(winkel);
```