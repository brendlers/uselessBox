# uselessBox
Another version of the useless box or most useless machine.

## Was ist das alles?
Einfaches Projekt zur Veranschaulichung verschiedener Technologien.

## Was ist notwendig?
Zur Bewältigung des Projektes sind Kenntnisse in **3D-Konstruktion, Montage, Elektronik, 3D-Druck, und Softwareentwicklung** notwendig. Hört sich erst mal schlimm an, ist aber überschaubar.

## Grober Ablauf

### Fertigen der Teile
1. Das **3D-Modell** wurde in **Fusion 360** erstellt.
2. Das **3D-Modell** wurde in **Prusa Slicer** und/oder **Orca Slicer** in **G-Code** umgewandelt.
3. Der **G-Code** wurde mit **Octoprint** an den **3D-Drucker** gestreamt.
4. Der **3D-Drucker** nutzt **Marlin** und/oder **Klipper** und fertigt anhand des **G-Codes** und **Material** ein **Objekt**.

### Verbinden der elektronischen Bauteile
- Stiftleisten aussuchen
- Kabel anlöten
- Einstecken
### Schreiben des Programmes
Die **Software** für den **Mikrocontroller** der uselessBox wird in der **Arduino IDE** und/oder **VS-Code** mit **PlatformIO** entwickelt.
