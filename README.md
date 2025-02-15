# Inhalt

## Was ist das alles?
Einfaches Projekt zur Veranschaulichung verschiedener Technologien.

## Was ist notwendig?
Zur Bewältigung des Projektes sind Kenntnisse in **3D-Konstruktion, Montage, Elektronik, 3D-Druck, und Softwareentwicklung** notwendig. Hört sich erst mal schlimm an, ist aber überschaubar.
### Verwendete Werkzeuge
Lötkolben
Schneidzange
Mehrzweckmesser
Feuerzeug
3D-Drucker
### Verbrauchsmaterial
Haftvermittler Haarspray
Werkstoff 3D-Drucker Filament
## Grober Ablauf
Überlegen was passieren muss.
Es wird ein Gehäuse benötigt das alle Teile aufnimmt.
Die Teile sollen mit möglichst wenig Werkzeug, Schrauben, oder andere Zusatzteile zusammengebaut werden können.
### Benötigte Kaufteile

| Anzahl | Bezeichnung   | Pinzahl | Rastermaß (mm) | Beschreibung |
| ------ | ------------- | ------- | -------------- | ------------ |
| 1      | Kippschalter  | 3       |                | 2 Stellungen |
| 1      | Servo         |         |                | 9g           |
| 1      | Arduino UNO   |         |                |              |
| 2      | Stiftleiste   | 4       | 2,54           | 90°          |
| 1      | Buchsenleiste | 3       | 2,54           |              |
### Fertigen der Teile
1. Das **3D-Modell** wurde in **Fusion 360** erstellt.
2. Das **3D-Modell** wurde in **Prusa Slicer** und/oder **Orca Slicer** in **G-Code** umgewandelt.
3. Der **G-Code** wurde mit **Octoprint** an den **3D-Drucker** gestreamt.
4. Der **3D-Drucker** nutzt **Marlin** und/oder **Klipper** und fertigt anhand des **G-Codes** und **Material** ein **Objekt**.
5. **Supports** entfernen.
6. **Nacharbeit** der **Teile**.
### Verbinden der elektronischen Bauteile
1. **Stiftleisten** aussuchen.
2. **Kabel** anlöten.
3. **Buchsenleiste** an **Schalter** anlöten.
### Verbinden der mechanischen Bauteile
1. **Deckel** an **Gehäuse** anbringen.
2. **Achsen** einschmelzen.
3. **Arduino** einsetzen.
4. **Arduino** einschrauben.
5. **Stiftleisten** mit **I/O-Pins** verbinden.
6. **Servo** in **Drehsperre** einsetzen.
7. **Hebel** an **Servo** anbringen.
8. **Drehsperre** in **Gehäuse** einsetzen.
9. **Servo** in **Drehsperre** und **Gehäuse** einschieben.
10. **Schalter** in **Deckel** einsetzen.
11. **Pins** mit **Servo** verbinden.
12. **Pins** mit **Schalter** verbinden.
### Schreiben des Programmes
13. Die **Software** für den **Mikrocontroller** der **uselessBox** wird in der **Arduino IDE** und/oder **VS-Code** mit **PlatformIO** entwickelt.
14. Die entwickelte **Software** wird durch ein **USB-Kabel** auf den **Mikrocontroller** geschrieben.
## Fehlerbehebung
- Kabel richtig gesteckt?
- Hebel in der richtigen Position/Ausrichtung angebracht?
