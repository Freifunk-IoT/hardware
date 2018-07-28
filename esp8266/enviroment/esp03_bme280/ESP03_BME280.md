# ESP-03 mit BME280 

(by @margau) *Work in Progress*

![Bestückte Platine](https://github.com/Freifunk-IoT/hardware/raw/master/esp8266/enviroment/esp03_bme280/esp03_bme280_1.JPG)

Diese Platine bietet, unter Verwendung von SMD-Bauelementen, einen schnellen Aufbau eines Temperatursensors an. Nötig sind zum Betrieb nur eine externe 3,3V-Spannungsversorgung. Auf LED's etc. wurde verzichtet, um einen möglichst lange andauernden Akkubetrieb möglich zu machen. Der Aufbau dauert für geübte ca. 10-15 Minuten.

### Features

- Temperatur-, Luftfeuchtigkeits und Luftdruckmessung mit BME280
- Sicherung
- direkter Anschluss eines Programmieradapters

### Bauteile

| Bezeichnung                                                  | Quelle                                              | Anzahl               | Preis (07/2018)                                         |
| ------------------------------------------------------------ | --------------------------------------------------- | -------------------- | ------------------------------------------------------- |
| Platinen                                                     | JLCPCB                                              | 1 (10er Set)         | 10 Stück: ~10 €  inkl. Versand                          |
| ESP-03                                                       | China (Ebay, Ali...)                                | 1                    | ~ 2,20 €                                                |
| BME280 4-pin-Breakout                                        | Amazon, Ebay, Aliexpress                            | 1                    | ~ 2,20€ - 10 €/Stück                                    |
| Elektrolytkondensator (z.B. 330 µF 16V)                      | Jeder Elektronikhändler, Empf.: Sets                | 1                    | < 0,10 €                                                |
| SMD-Widerstand 1206 10kΩ                                     | Jeder Elektronikhändler, Empf.: Sets                | 2                    | ~ 1ct/Stück                                             |
| SMD-Widerstand 1206 2,2kΩ                                    | Jeder Elektronikhändler, Empf.: Sets                | 1                    | ~ 1ct/Stück                                             |
| SMD-Widerstand 1206  170Ω                                    | Jeder Elektronikhändler, Empf.: Sets                | 1                    | ~ 1ct/Stück                                             |
| Feinsicherung 1A 6*20mm                                      | Jeder Elektronikhändler, Empf.: Sets                | 1                    |                                                         |
| Sicherungshalter                                             | Conrad:  533920 - 62, Ali, einige Elektronikhändler | 2                    | ~ 14ct/Stück Conrad, ~1,20 € für 100 Stück (Aliexpress) |
| Buchsenleiste 2,54 mm                                        | Diverse Elektronikhändler, am besten als Set        | 1 * 4 pin, 1 * 6 pin | Aliexpress: 1,66 € für 10 * 40 pins                     |
| 5,08 mm Schraubklemme                                        | Ebay, Aliexpress ...                                | 1                    | ~ 1,20 € für 20 Stück                                   |
| Miniaturtaster                                        | Ebay, Aliexpress; sinnvoll im Set                               | 1                    | < 10 ct                                   |
| FT232(o.ä.) USB-Seriell Programmieradapter, **3.3V!**, auf Pinbelegung achten! | Ebay, Aliexpress, ...                               | 1                    | ~1,50 €                                                 |

Weiterhin wird für den Betrieb eine 3.3V-Spannungsversorgung benötigt, auch hier gibt es fertige Module. **Ein Betrieb mit 5V zerstört die Schaltung!**

### PCB
![Bestückte Platine](https://github.com/Freifunk-IoT/hardware/raw/master/esp8266/enviroment/esp03_bme280/esp03_bme280_2.JPG)

Die Produktionsdaten im Gerber-Format befinden sich im Ordner "Gerber". Das Design ist im Onlineeditor von EasyEDA entstanden, und kann dort auch weiterbearbeitet werden: [Zum Projekt bei EasyEDA](https://easyeda.com/margau/FreifunkIoT-BME280-ESP03)

Die im Bild dargestellte Platine wurde bei JLCPCB bestellt, bei Kosten von ca. 9$ für 10 Stück inkl. Versand und einer Lieferzeit von ca. 10-20 Tagen.

### Aufbau
Es empfiehlt sich beim Aufbau zunächst mit den SMD-Komponenten zu Beginnen, und sich dann zu den höheren Bauteilen vorzuarbeiten.
Wenn beim Programmiervorgang eine Stromversorgung über den Programmieradapter gewünscht ist, sollte die Lötbrücke Prog. VCC geschlossen werden.

Bei Verwendung des Deep Sleep muss weiterhin eine Lötbrücke auf der Platine des ESP-03 geschlossen werden, dies erfordert etwas Geschick und Vorsicht.

![Lötbrücke](https://github.com/Freifunk-IoT/hardware/raw/master/esp8266/enviroment/esp03_bme280/esp03_bme280_3.JPG)

### Programmierung
Die Programmierung erfolgt mit einem USB-Seriell-Adapter aus der Arduino-IDE. 
Hierzu ist folgender Sketch geeignet: (https://github.com/Freifunk-IoT/esp8266-examples/blob/master/bme280/esp01/esp01-bme280-sketch/esp01-bme280-sketch.ino)

Folgende Änderungen müssen noch vorgenommen werden:
- Die richtige Sensor-ID muss eingetragen werden
- ggf. den Kommentar in Zeile 143 entfernen und Zeile 145 auskommentieren, um den Deep Sleep zu nutzen

In der Arduino-IDE muss die ESP8266-Umgebung installiert sein, der richtige COM-Port ausgewählt werden und das Board "Generic ESP 8266 Module" ausgewählt sein. 

Nach korrekter Verbindung (Pin's prüfen!) und Einstellung der Spannung von **3.3 V** am USB-Seriell Adapter kann man den Upload-Knopf am Board gedrückt halten, die Verbindung herstellen und in der IDE den Upload anstoßen. 

Sieht man an den LEDs des Adapters einzelnes Aufblitzen, kann der Upload-Taster losgelassen werden; der Upload sollte nun erfolgen. Falls nicht, sind noch einmal alle Verbindungen etc. zu prüfen.

*Die Beschriftung ist 1:1, d.h., RX wird mit RX am Adapter und TX mit TX am Adapter verbunden. Die Belegung ist für übliche FTDI-Adapter - falls eine andere Reihenfolge der Pins vorliegt, einfach mit Jumper-Kabeln richtig verbinden.*

Nach dem Upload lässt sich über die Serielle Schnittstelle das Verhalten nachvollziehen, der Sensor sollte bei vorhandenem Freifunk-Netz direkt im Freifunk-IoT-Backend auftauchen.

### Changelog
Rev 1:
Initial Layout
Rev 2: 
Added missing pull-up resistors, added missing GPIO15-GND connection.
