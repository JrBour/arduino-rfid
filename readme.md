# Scanner carte RFID

## Montage

**Materiel :**

- Carte Arduino Uno

- module RFID (RC-522)

- RFID Tag

- Breadboard

- Jumper Wire

- LED


**Câblage :**

| RC-522      | 3.3v | GND  | SDA  | SCK  | MOSI | MISO | RST  |
| ----------- | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| Arduino Uno | 3.3v | gnd  | D10  | D13  | D11  | D12  |  D9  |



**Schema :**

![](https://www.memorandum.ovh/wp-content/uploads/2016/12/schema_RFID_bb.png)

[(source]: www.memorandum.ovh/



## Phase de test

- [x] Installation de la librarie RFID
- [x] Test détection Carte
- [x] Récupération des infos depuis la carte
- [ ] Test fonctionnement LED
- [ ] Test écran

La librairie RFID a été installée à partir d'un repo GitHub et ajoutée sur Arduino à partir de son menu.

![](C:\Users\mc_sy\Desktop\test00.png)

Le RFID a eu des difficultés à détecter le carte et affichait comme erreur :

> Firmware Version: 0x0 = (unknown) WARNING: Communication failure, is the MFRC522 properly connected?

Nous avons donc directement connecté les cable sur la carte RFID plutôt que sur le Breadboard.

![](C:\Users\mc_sy\Desktop\test01.png)



## Sitographie

- [Tutoriel câblage](https://www.memorandum.ovh/tuto-arduino-utiliser-un-module-rfid/)
- [Documentation Arduino](https://www.arduino.cc/) 