# Scanner carte RFID

## Montage

**Matériel**

- [Carte Arduino Uno](https://www.gotronic.fr/art-carte-arduino-uno-12420.htm)
- [Module RFID (RC-522)](https://fr.shopping.rakuten.com/offer/buy/2802988128/cnyo-10-set-crfm-522-rc522-rfid-rf-ic-module-de-capteur-de-carte-a-envoyer-la-carte-s50-fudan-porte-cles.html?t=180112&gclid=CjwKCAjw_b3cBRByEiwAdG8WqlX7mG_J3dCFA2PvHSjEpXXqnvXjIu2XHSZ8sjN8Q-Lc9P-dGNbuDhoC3BYQAvD_BwE&bbaid=3559416029&sort=0&xtatc=PUB-%5Bggp%5D-%5BInformatique%5D-%5BAccessoires%5D-%5B2802988128%5D-%5Bneuf%5D-%5BCNYO%5D&ptnrid=s24llCvmK_dc|pcrid|53434268603|pkw||pmt|&ja2=tsid:67590|cid:285670043|agid:14467128323|tid:pla-89152206803|crid:53434268603|nw:g|rnd:18354825736995777509|dvc:c|adp:1o2)
- [Cable](https://www.amazon.fr/SODIAL-Breadboard-dExperimentation-Soudure-Solderless/dp/B00JGFDKBQ/ref=sr_1_3?ie=UTF8&qid=1536141445&sr=8-3&keywords=breadboard)
- [Jumper Wire](https://www.amazon.fr/40pcs-20cm-C%C3%A2bles-pour-BreadBoard/dp/B00ENSOI5I/ref=sr_1_3?ie=UTF8&qid=1536141620&sr=8-3&keywords=wire+jumper)
- [LED](https://www.amazon.fr/SODIAL-%C3%A9mettant-lumi%C3%A8re-100-pi%C3%A8ces-couleurs/dp/B00L11KG7Y/ref=sr_1_5?ie=UTF8&qid=1536141657&sr=8-5&keywords=Led+Arduino)

**Outils**

- [IDE Arduino](https://www.arduino.cc/en/Main/Software)


**Câblage**

| RC-522      | 3.3V | GND  | SDA  | SCK  | MOSI | MISO | RST  |
| ----------- | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| Arduino Uno | 3.3V | GND  | D10  | D13  | D11  | D12  |  D8  |



**Schéma**

![](https://trello-attachments.s3.amazonaws.com/5b8e517eb593be33b7eb2294/5b8ea0d31f4a6e33a42958b2/05e277f4f42b095fe6e87e1a9a2b5906/rfid_led_bb.png)

## Introduction
Nous avons voulu réaliser un prototype permettant d'identifier un utilisateur grâce à un module RFID et la technologie Arduino. Le principe est que lorsque la personne présente sa carte sur le module, une LED lui indique si oui ou non il est autorisé. Un écran LCD lui indiquera en plus si son accès est autorisé ou non.

## Phase de test

- [x] Installation de la librarie MFRC522
- [x] Test détection de la carte MFRC522
- [x] Récupération des informations depuis la carte
- [x] Test fonctionnement LED
- [ ] Test écran LCD

La librairie MDRC522 a été installée à partir d'un repository GitHub et ajoutée sur Arduino à partir de son menu.

![](https://trello-attachments.s3.amazonaws.com/5b8e517eb593be33b7eb2294/5b8e524997a4aa2d3219bbac/0309271c06b4a632894e582f1b3af46d/test01.png)

Le RFID a eu des difficultés à détecter la carte et affichait comme erreur :

> Firmware Version: 0x0 = (unknown) WARNING: Communication failure, is the MFRC522 properly connected?

Nous avons donc directement connecté les câbles sur la carte RFID plutôt que sur le Breadboard en utilisant du scotch, ce qui remplace la soudure.

![](https://trello-attachments.s3.amazonaws.com/5b8e517eb593be33b7eb2294/5b8e524997a4aa2d3219bbac/a7f94da2eda37267a42efa20394a4c00/test00.png)

Par la suite, nous avons connecté deux LEDs sur la plaque d'essai, permettant d'indiquer si la personne est autorisée ou non, par rapport à l'UID de sa carte.
Un UID est un code hexadecimal servant à identifier la carte.


## Code

### Librairies utilisées

- [MFRC522](https://github.com/miguelbalboa/rfid)
- [SPI](https://www.arduino.cc/en/Reference/SPI)

### Initialisation des modules
```javascript 
 Serial.begin(9600);
 SPI.begin();      
 mfrc522.PCD_Init();
```

### Vérification des accès
```javascript
if (mfrc522.uid.uidByte[0] == 0x90 && 
	mfrc522.uid.uidByte[1] == 0xA1 && 
	mfrc522.uid.uidByte[2] == 0xDD && 
	mfrc522.uid.uidByte[3] == 0x2B) {
	Serial.println("Accés autorisé");
    digitalWrite(LED_GREEN, HIGH);
    delay(2000);
    digitalWrite(LED_GREEN, LOW);
 } else {
    Serial.println("Accés refusé");
    digitalWrite(LED_RED, HIGH);
    delay(2000);
    digitalWrite(LED_RED, LOW);
}
```

### Débug le UID
```javascript
mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
```
Cette fonction retourne différentes informations sur la carte. Tout d'abord son UID (Unique Identifier) en hexadécimal, le SAK indiquant le constructeur et le modèle du module RFID, et pour finir, nous obtenons le visuel des données contenu sur la carte.

## Conclusion

Au final, nous n'avons pas pu réussir à implémenter tous les élèments que nous voulions. Premièrement par manque de temps, et d'espace sur la carte, l'écran LCD nécessitant au minimum 8 pins pour le connecter, nous ne pouvions l'intégrer au prototype. Le haut-parleur n'a pas non plus été intégré, car il nous manquait ce composant lors de la création du prototype.

## Liens utiles

- [Documentation Arduino](https://www.arduino.cc/) 
- [Utiliser un modfule RFID](https://www.memorandum.ovh/tuto-arduino-utiliser-un-module-rfid/)
- [Hardware Arduino](https://wiki.mdl29.net/lib/exe/fetch.php?media=elec:arduino_dossier_ressource.pdf)

### Auteurs
[Jérémy Bourel](https://github.com/JrBour) – [Sylvie Mohammed Cassim](https://github.com/SylvieMC) – [Kévin Léonard](https://github.com/kevin95670) – [Soraya Moukaouame](https://github.com/SorayaMoka)