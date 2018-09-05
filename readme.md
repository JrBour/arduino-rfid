# Scanner carte RFID

## Montage

**Materiel :**

- Carte Arduino Uno

- Module RFID (RC-522)

- RFID Tag

- Plaque d'essai

- Jumper Wire

- LED


**Câblage :**

| RC-522      | 3.3v | GND  | SDA  | SCK  | MOSI | MISO | RST  |
| ----------- | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| Arduino Uno | 3.3v | gnd  | D10  | D13  | D11  | D12  |  D9  |



**Schema :**

![](https://www.memorandum.ovh/wp-content/uploads/2016/12/schema_RFID_bb.png)

[(source]: www.memorandum.ovh/

## Introduction
Nous avons voulu réaliser un prototype permettant d'identifier un utilisateur grâce à un module RFID et la technologie Arduino.

## Phase de test

- [x] Installation de la librarie MFRC522
- [x] Test détection de la carte MFRC522
- [x] Récupération des informations depuis la carte
- [ ] Test fonctionnement LED
- [ ] Test écran LCD

La librairie MDRC522 a été installée à partir d'un repo GitHub et ajoutée sur Arduino à partir de son menu.

![](https://trello-attachments.s3.amazonaws.com/5b8e517eb593be33b7eb2294/5b8e524997a4aa2d3219bbac/0309271c06b4a632894e582f1b3af46d/test01.png)

Le RFID a eu des difficultés à détecter la carte et affichait comme erreur :

> Firmware Version: 0x0 = (unknown) WARNING: Communication failure, is the MFRC522 properly connected?

Nous avons donc directement connecté les cable sur la carte RFID plutôt que sur le Breadboard.

![](https://trello-attachments.s3.amazonaws.com/5b8e517eb593be33b7eb2294/5b8e524997a4aa2d3219bbac/a7f94da2eda37267a42efa20394a4c00/test00.png)


##Code

###Initialisation des modules
`Serial.begin(9600);
 SPI.begin();      
 mfrc522.PCD_Init();`

## Lien utiles

- [Documentation Arduino](https://www.arduino.cc/) 
- [Utiliser un modfule RFID](https://www.memorandum.ovh/tuto-arduino-utiliser-un-module-rfid/)
- [Hardware Arduino](https://wiki.mdl29.net/lib/exe/fetch.php?media=elec:arduino_dossier_ressource.pdf)