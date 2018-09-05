#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  8          // Configurable, see typical pin layout above
#define SS_PIN   10         // Configurable, see typical pin layout above
#define LED 4 // pin LED

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  pinMode(LED, OUTPUT);
  Serial.println(F("Veuillez scanner votre carte.")); // Function F(), allow to store string in flash memory instead of the RAM
}

void checkCard() {
  // Check if a card is present
  if ( !mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  if (mfrc522.uid.uidByte[0] == 0x90 && mfrc522.uid.uidByte[1] == 0xA1 && mfrc522.uid.uidByte[2] == 0xDD && mfrc522.uid.uidByte[3] == 0x2B) {
    Serial.println("Accés autorisé");
    digitalWrite(LED, HIGH);
    delay(3000);
    digitalWrite(LED, LOW);
  } else {
    Serial.println("Accés refusé");
  }
}

void loop() {
  checkCard();
}
