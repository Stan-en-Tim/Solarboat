// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.,

#include <Wire.h>

int i = 0;

float data[8] = {69, 420, 4.34, 9.3456, 523.1, 21, 456.34, 34.46};
String labels[8] = {"AB", "CD", "EF", "GH", "IJ", "KL", "MN", "OP"};

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  if(i >= 8) {
    i=0;
  }
  char buffer[16];
  (labels[i] + ": " + String(data[i], 3)).toCharArray(buffer, 16);
  Wire.write(buffer);
  i+=1;
}
