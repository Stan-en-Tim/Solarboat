/*
 Dit is een aangepaste versie van het sofwareserial exapmle.
  
   created back in the mists of time
   modified 25 May 2012
   by Tom Igoe
   based on Mikal Hart's example

 Ontvang data van software serial (Motor), stuur door naar hardware serial (USB, Serial Monitor).
 Dit gebruiken we om het signaal dat tussen de motor en de gashendel wordt gestuurd af te luisteren.
*/
#include <SoftwareSerial.h>

int len = 33;
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
  delay(1000);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  for(int i =0; i <= len; i++) {
    mySerial.write(packet[i]);
  }
  digitalWrite(5, LOW);
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.println(mySerial.read(),HEX  );
  }
  if (Serial.available()) {
   // mySerial.write(Serial.read());
  }
}
