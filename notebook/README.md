## Was ist das alles?
Einfaches Projekt zur Veranschaulichung verschiedener Technologien.

Da [es keinen Sinn und keinen Wert gibt](https://de.wikipedia.org/wiki/Nihilismus), habe ich auch ein sinnloses Projekt ausgewählt. Die **[uselessBox](https://de.wikipedia.org/wiki/Leave-Me-Alone-Box)** .
## Was ist notwendig?
Zur Bewältigung des Projektes sind Kenntnisse in 3D-Konstruktion, Montage, Elektronik, 3D-Druck, und Softwareentwicklung notwendig. Hört sich erst mal schlimm an, ist aber überschaubar.
### Verwendete Werkzeuge
- Lötkolben
- Schneidzange
- Mehrzweckmesser
- Feuerzeug
- [3D-Drucker](https://de.wikipedia.org/wiki/3D-Druck) nach dem [FDM-Prinzip](https://de.wikipedia.org/wiki/Fused_Deposition_Modeling)
### Verbrauchsmaterial
- [Haftvermittler](https://de.wikipedia.org/wiki/Haftvermittler) Haarspray (da [PVA](https://de.wikipedia.org/wiki/Polyvinylacetat)-basiert
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
8. [Stiftleisten](https://de.wikipedia.org/wiki/Stiftleiste) aussuchen.
9. Kabel anlöten.
10. [Buchsenleiste](https://de.wikipedia.org/wiki/Stiftleiste) an [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik) anlöten.
## Zusammenbau der Bauteile
11. Deckel an Gehäuse anbringen.
12. Achsen einschmelzen.
13. [Arduino UNO](https://de.wikipedia.org/wiki/Arduino_(Plattform)) einsetzen.
14. [Arduino UNO](https://de.wikipedia.org/wiki/Arduino_(Plattform)) einschrauben.
15. [Stiftleisten](https://de.wikipedia.org/wiki/Stiftleiste)  mit [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) verbinden.
16. [[Servo]] in Drehsperre einsetzen.
17. Hebel an [[Servo]] anbringen.
18. Drehsperre in Gehäuse einsetzen.
19. [[Servo]] in Drehsperre und Gehäuse einschieben.
20. [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik)) in Deckel einsetzen.
21. [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) mit [[Servo]] verbinden.
22. [I/O-Pins](https://de.wikipedia.org/wiki/GPIO) mit [Kippschalter](https://de.wikipedia.org/wiki/Schalter_(Elektrotechnik)) verbinden.
## Schreiben des Programmes
1. Die Software für den [Mikrocontroller](https://de.wikipedia.org/wiki/Mikrocontroller) der **[uselessBox](https://de.wikipedia.org/wiki/Leave-Me-Alone-Box)** wird in der [Arduino IDE](https://de.wikipedia.org/wiki/Arduino_IDE) und/oder [VS-Code](https://de.wikipedia.org/wiki/Visual_Studio_Code) mit [PlatformIO](https://de.wikipedia.org/wiki/PlatformIO) entwickelt.
2. Die entwickelte Software wird durch ein [USB-Kabel](https://de.wikipedia.org/wiki/Universal_Serial_Bus) auf den [Mikrocontroller](https://de.wikipedia.org/wiki/Mikrocontroller) geschrieben.
## Fehlerbehebung
Die üblichen Verdächtigen:
- Kabel richtig gesteckt?
- Hebel in der richtigen Position/Ausrichtung angebracht?


