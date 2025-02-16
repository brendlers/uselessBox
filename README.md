# UselessBox

## Was ist das alles?
Einfaches Projekt zur Veranschaulichung verschiedener Technologien.

Da [nichts einen Sinn hat und es auch keinen Wert gibt](https://de.wikipedia.org/wiki/Nihilismus), habe ich auch ein sinnloses Projekt ausgewählt. Die **[uselessBox](https://de.wikipedia.org/wiki/Leave-Me-Alone-Box)** . Manche nennen es auch die **Leave-Me-Alone-Box**.
## Was ist notwendig?
Zur Bewältigung des Projektes sind Kenntnisse in 3D-Konstruktion, Montage, Elektronik, 3D-Druck, und Softwareentwicklung notwendig. Hört sich erst mal schlimm an, ist aber überschaubar.
### Verwendete Software
#### CAD-Programm
[FreeCAD](https://www.freecad.org/index.php?lang=de), [Autodesk Fusion 360](https://www.autodesk.com/de/products/fusion-360/)
#### Slicer
[Prusa Slicer][https://www.prusa3d.com/] oder [Orca Slicer](https://orca-slicer.com/)
#### Entwicklungsumgebung
[Arduino IDE](https://de.wikipedia.org/wiki/Arduino_IDE) oder [VS Code](https://code.visualstudio.com/) mit [Platform IO](https://platformio.org/)
### Verwendete Werkzeuge
- Lötkolben
- Schneidzange
- Mehrzweckmesser
- Feuerzeug
- [3D-Drucker](https://de.wikipedia.org/wiki/3D-Druck) nach dem [FDM-Prinzip](https://de.wikipedia.org/wiki/Fused_Deposition_Modeling)
### Verbrauchsmaterial
- [Haftvermittler](https://de.wikipedia.org/wiki/Haftvermittler) Haarspray (da [PVA](https://de.wikipedia.org/wiki/Polyvinylacetat)-basiert)
- [Werkstoff]([Material](https://de.wikipedia.org/wiki/Werkstoff)) 3D-Drucker [Filament](https://de.wikipedia.org/wiki/Filament_(3D-Druck))
- [Lötzinn](https://de.wikipedia.org/wiki/Lot_(Metall))
- [Flussmittel](https://de.wikipedia.org/wiki/Flussmittel_(L%C3%B6ten))
### Benötigte Kaufteile

| Anzahl | Bezeichnung                                                             | Pinzahl | Rastermaß (mm) | Beschreibung |
| ------ | ----------------------------------------------------------------------- | ------- | -------------- | ------------ |
| 1      | [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik)) | 3       |                | 2 Stellungen |
| 1      | [Servo](https://de.wikipedia.org/wiki/Servo)                            |         |                | 9g           |
| 1      | [Arduino UNO](https://de.wikipedia.org/wiki/Arduino_(Plattform))        |         |                |              |
| 2      | [Stiftleiste](https://de.wikipedia.org/wiki/Stiftleiste)                | 4       | 2,54           | 90°          |
| 1      | [Buchsenleiste](https://de.wikipedia.org/wiki/Stiftleiste)              | 3       | 2,54           |              |
### Benötigte 3D-Druck-Teile

| Anzahl | Bezeichnung |
| ------ | ----------- |
| 1      | Dose        |
| 1      | Deckel_1    |
| 1      | Deckel_2    |
| 1      | Hebel       |
| 1      | Drehsperre  |
## Grober Ablauf
- Überlegen was passieren muss.
- Es wird ein Gehäuse benötigt das alle Teile aufnimmt.
- Die Teile sollen mit möglichst wenig Werkzeug, Schrauben, oder andere Zusatzteile zusammengebaut werden können.
## Fertigen der Bauteile
### Fertigen der Teile auf dem Drucker
1. Das 3D-Modell wurde in einem [CAD](https://de.wikipedia.org/wiki/CAD)-Programm erstellt.
2. Das 3D-Modell wurde in einem [CAM](https://de.wikipedia.org/wiki/Computer-aided_manufacturing)-Programm, dem [Slicer](https://de.wikipedia.org/wiki/Slicer-Software), in [G-Code](https://de.wikipedia.org/wiki/Computerized_Numerical_Control#DIN/ISO-Programmierung_bzw._G-Code) umgewandelt. Das kann in Prusa Slicer oder Orca Slicer erfolgen.
3. Der 3D-Drucker ist eine [CNC](https://de.wikipedia.org/wiki/Computerized_Numerical_Control)-Maschine, die Anweisungen (CNC-Programm) in Form von  [G-Code](https://de.wikipedia.org/wiki/Computerized_Numerical_Control#DIN/ISO-Programmierung_bzw._G-Code) empfängt.
4. Der [G-Code](https://de.wikipedia.org/wiki/Computerized_Numerical_Control#DIN/ISO-Programmierung_bzw._G-Code) wurde mit [Octoprint](https://de.wikipedia.org/wiki/OctoPrint) an den [3D-Drucker](https://de.wikipedia.org/wiki/3D-Druck) übertragen.
5. Der [3D-Drucker](https://de.wikipedia.org/wiki/3D-Druck) nutzt als Betriebssystem oft [Marlin](https://marlinfw.org/) oder [Klipper](https://www.klipper3d.org/) und fertigt anhand des [G-Code](https://de.wikipedia.org/wiki/Computerized_Numerical_Control#DIN/ISO-Programmierung_bzw._G-Code)s und [Material](https://de.wikipedia.org/wiki/Werkstoff) ein Objekt.
6. [Supports](https://help.prusa3d.com/de/article/stutzstrukturen_1698) entfernen.
7. [Nacharbeit](https://de.wikipedia.org/wiki/Rework) der Teile.
### Fertigen der elektronischen Bauteile
Die [elektronischen Bauteile](https://de.wikipedia.org/wiki/Liste_elektrischer_Bauelemente) werden durch [Steckverbinder](https://de.wikipedia.org/wiki/Steckverbinder) und [Löten](https://de.wikipedia.org/wiki/L%C3%B6ten) verbunden. 
1. [Stiftleisten](https://de.wikipedia.org/wiki/Stiftleiste) aussuchen.
2. Kabel anlöten.
3. [Buchsenleiste](https://de.wikipedia.org/wiki/Stiftleiste) an [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik) anlöten.
## Zusammenbau der Bauteile
1. Deckel an Gehäuse anbringen.
2. Achsen einschmelzen.
3. [Arduino UNO](https://de.wikipedia.org/wiki/Arduino_(Plattform)) einsetzen.
4. [Arduino UNO](https://de.wikipedia.org/wiki/Arduino_(Plattform)) einschrauben.
5. [Stiftleisten](https://de.wikipedia.org/wiki/Stiftleiste)  mit [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) verbinden.
6. [[Servo]] in Drehsperre einsetzen.
7. Hebel an [[Servo]] anbringen.
8. Drehsperre in Gehäuse einsetzen.
9. [[Servo]] in Drehsperre und Gehäuse einschieben.
10. [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik)) in Deckel einsetzen.
11. [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) mit [[Servo]] verbinden.
12. [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) mit [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik)) verbinden.
## Schreiben des Programmes
1. Die Software für den [Mikrocontroller](https://de.wikipedia.org/wiki/Mikrocontroller) der **[uselessBox](https://de.wikipedia.org/wiki/Leave-Me-Alone-Box)** wird in der [Arduino IDE](https://de.wikipedia.org/wiki/Arduino_IDE) und/oder [VS-Code](https://de.wikipedia.org/wiki/Visual_Studio_Code) mit [PlatformIO](https://de.wikipedia.org/wiki/PlatformIO) entwickelt.
2. Die entwickelte Software wird durch ein [USB-Kabel](https://de.wikipedia.org/wiki/Universal_Serial_Bus) auf den [Mikrocontroller](https://de.wikipedia.org/wiki/Mikrocontroller) geschrieben.

HINWEIS! Das Diagramm ist weder vollständig noch komplett korrekt!
WARNUNG! Je nach Einbauposition des Hebels kann Gehäuse, Arduino oder sonstiges **ZERSTÖRT** werden.
ACHTUNG! Im Programm sind aktuell die **Endpositionen** von **90 und 160** vorgesehen! wenn der **Servo** auf der **hinteren Endlage** steht, muss der **Hebel** in etwa **horizontal** angebracht werden!
ACTHUNG! Hardware-Projekte und Software-Projekte können NICHT beliebig abgeändert oder kombiniert werden!

HINWEIS: Vor dem verwenden neuer Software IMMER den Servo ausbauen! (Siehe Video)
![[https://github.com/brendlers/uselessBox/blob/main/vid/useless%20box%20v10.mp4]]


```mermaid
graph TD;
%%{init: {"themeVariables": {"fontSize": "8pt"}}}%%

    A[Start] -->|Setup Block| B[Servo an Pin binden];
    B --> C[Schalter-Pins initialisieren];
    C --> D[LED-Pin initialisieren];
    D --> E[Serielle Kommunikation starten];
    E --> |Main Loop Block| F[Wurde Taste gedrückt?];
    
    F -->|Schalter ON gedrückt| G{Variationen durchlaufen};
    G -->|0| H-->servo_forwardMove0;
    G -->|1| I-->servo_forwardMove1;
    G -->|2| J-->servo_forwardMove2;
    G -->|Default| K-->servo_forwardMove;

    
    F -->|Schalter OFF gedrückt| M{Variationen durchlaufen};
    M -->|0| N-->servo_backwardMove0;
    M -->|1| O-->servo_backwardMove1;
    M -->|2| P-->servo_backwardMove2;
    M -->|Default| Q-->servo_backwardMove;

	servo_forwardMove0 --> R;
	servo_forwardMove1 --> R;
	servo_forwardMove2 --> R;
    servo_forwardMove --> R;

	servo_backwardMove0 --> R;
	servo_backwardMove1 --> R;
	servo_backwardMove2 --> R;
	servo_backwardMove --> R;
	
	R --> L[Serial.println];
	L --> F
```
## Fehlerbehebung
Die üblichen Verdächtigen:
- Kabel richtig gesteckt?
- Hebel in der richtigen Position/Ausrichtung angebracht?