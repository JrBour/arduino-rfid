#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  8          // Configurable, see typical pin layout above
#define SS_PIN   10         // Configurable, see typical pin layout above
#define LED_GREEN 4 // pin LED
#define LED_REF 5 // pin LED

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  SPI.begin();  
  Serial.begin(9600);   // Initialize serial communications with the PC
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Veuillez scanner votre carte.")); // Function F(), allow to store string in flash memory instead of the RAM
}

void checkCard() {
  // Check if a card is present
  if ( !mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  if (mfrc522.uid.uidByte[0] == 0x90 && mfrc522.uid.uidByte[1] == 0xA1 && mfrc522.uid.uidByte[2] == 0xDD && mfrc522.uid.uidByte[3] == 0x2B) {
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
}

void loop() {
  checkCard();
}
