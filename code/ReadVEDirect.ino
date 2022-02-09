/******************************************************************
Dit is een programma om verbinding te maken met twee MPPT's, en het voltage uit te lezen.

De waardes worden weergegeven op een LCD scherm.

We hebben elementen uit het ReadVEDirect voorbeeld van de VEDirect library gebruikt.
******************************************************************/

#include "Arduino.h"
#include "VEDirect.h" //libray to connect to the MPPT's
#include "SoftwareSerial.h"
#include <LiquidCrystal_I2C.h>  //library for te LCD Display.
LiquidCrystal_I2C lcd(0x27,16,2);  //set the LCD address to 0x27 for a 16 chars and 2 line display
 
const byte rxPin2 = 2; // (wit)
const byte txPin2 = 3; // (zwart)
const byte rxPin3 = 4; // (wit)
const byte txPin3 = 5; // (zwart)
const byte rxPin4 = 6;
const byte txPin4 = 7;

// set up two serial objects
SoftwareSerial softwareSerial2 (rxPin2, txPin2);
SoftwareSerial softwareSerial3 (rxPin3, txPin3);

// 32 bit ints to collect the data from the device
int32_t solA_soc, solA_power, solA_panel_voltage, solA_voltage, solA_current;
int32_t solB_soc, solB_power, solB_panel_voltage, solB_voltage, solB_current;
// Boolean to collect an ON/OFF value
uint8_t solA_alarm;
uint8_t solB_alarm;

// VEDirect instantiated with relevant serial object
VEDirect solA(softwareSerial2);
VEDirect solB(softwareSerial3);

void setup() {
  Serial.begin(9600);
  lcd.init(); //initialize the lcd
  lcd.backlight();
  lcd.clear();
}

void loop() {

  // Start with sol A
  lcd.setCursor(0,1);
  lcd.print("Checking sol A...");
  lcd.setCursor(0,0);
  lcd.print("        ");
  
  // Read the data
  if(solA.begin()) {                  // test connection
  //if(1){
    lcd.setCursor(0,1);
    lcd.print("Reading sol A...");
    solA_soc = solA.read(VE_SOC);
    solA_power = solA.read(VE_POWER);
    solA_voltage = solA.read(VE_VOLTAGE);
    solA_panel_voltage = solA.read(VE_PANEL_VOLTAGE);
    solA_current = solA.read(VE_CURRENT);
    solA_alarm = solA.read(VE_ALARM);
    
    // Display the voltage
    lcd.setCursor(0,0);
    lcd.print("        ");
    lcd.setCursor(0,0);
    lcd.print("UA:"+String(solA_voltage));
    lcd.setCursor(0,1);
    lcd.print("Doing nothing :)");
    delay(2000);
    
  } else {
    // Print an error message
    lcd.setCursor(0,0);
    lcd.print("Error A ");
    lcd.setCursor(0,1);
    lcd.print("Doing nothing :)");
    delay(2000);
  }

  // Start with sol B
  lcd.setCursor(0,1);
  lcd.print("Checking sol B...");
  lcd.setCursor(8,0);
  lcd.print("        ");

  // Read the data
  if(solB.begin()) {                  // test connection
    lcd.setCursor(0,1);
    lcd.print("Reading sol B...");
    //solB_soc = solB.read(VE_SOC);
    solB_power = solB.read(VE_POWER);
    solB_voltage = solB.read(VE_VOLTAGE);
    solB_panel_voltage = solB.read(VE_PANEL_VOLTAGE);
    //solB_current = solB.read(VE_CURRENT);
    //solB_alarm = solB.read(VE_ALARM);
    
    // Display the voltage
    lcd.setCursor(8,0);
    lcd.print("        ");
    lcd.setCursor(8,0);
    lcd.print("UB:"+String(solB_voltage));
    lcd.setCursor(0,1);
    lcd.print("Doing nothing :)");
    delay(2000);
  } else {
    lcd.setCursor(8,0);
    lcd.print("Error B ");
    lcd.setCursor(0,1);
    lcd.print("Doing nothing :)");
    delay(2000);
  }

}
