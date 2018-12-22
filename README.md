# Freifunk-IoT-Hardware

| Hardware/Details                 | Typ  | Messungen/Sensor                                             | Stückpreis ca. | Status                | Bemerkungen                                                  |
| -------------------------------- | ---- | ------------------------------------------------------------ | -------------- | --------------------- | ------------------------------------------------------------ |
| [ESP-03 mit BME280](https://github.com/Freifunk-IoT/hardware/blob/master/esp8266/enviroment/esp03_bme280/ESP03_BME280.md)            | PCB  | BME280 (Temperatur, Luftfeuchtigkeit, Luftdruck)             | ?              | funktioniert (Rev. 2) | kann Deep Sleep, inkl. Sicherung                             |
| ESP-03 mit BME280/DHT22 (Hybrid) | PCB  | BME280 (Temperatur, Luftfeuchtigkeit, Luftdruck) oder DHT22 (Temperatur, Luftfeuchtigkeit) | ?              | Idee                  |                                                              |
| ESP-01 mit DHT11                 | Mod  | DHT22 (T)                                                    | ?              | Idee                  | Modul gibt es fertig bei Aliexpress etc., vmtl. gut für den "schnellen Einstieg". |
| [ESP-01 mit DHT*/BME280 "Workshop Board"](https://github.com/Freifunk-IoT/hardware/blob/master/esp8266/enviroment/esp01_DHT22_USB/ESP01_DHT22.md) | PCB  | BME280 (Temperatur, Luftfeuchtigkeit, Luftdruck) oder DHT22 (Temperatur, Luftfeuchtigkeit) | ?              | Hardware funktioniert und ist getestet, Software fehlt                  | Einsteigerplatine mit Linearregler (USB-Anschluss) + entsprechende Absicherung, wahlweise BME280 oder DHT*, kleinste Bauteile: 1206, alles andere THT |
| Outdoor-Full-Feature-Board       | PCB  | BME280                                                       | ?              | Idee                  | inkl. BMS für LiIon, Spannungsreglern (Buck/Boost), Absicherungen, Deep Sleep, optimiert für lange Laufzeiten |
| Wemos D1 mini mit DHT* | PCB | DHT* (Temperatur + Feuchtigkeit) | ? | Idee | Für einfachen Einstieg (5V USB Eingang) |

Wenn du Freifunk-IoT auf anderer Hardware betreibst, neue Sensoren eingebunden hast, eine praktische Platine entworfen hast oder einfach nur dein Aufbau vorstellen willst, mach einfach einen eigenen Ordner für dein Projekt auf und stelle es vor!

*Bitte beachtet: Dieses Repository ist mehr für die technische Entwicklung und Vorstellung gedacht. Reine Tutorials sind auf der [website](https://github.com/Freifunk-IoT/website) besser aufgehoben.*
