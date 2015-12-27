#include <SPI.h>
#include "Matrix_CoProcessor.h"

/*
 * First Attempts at driving 45x7 Flip Dot Matrix
 * HLS 2015-12-20
 *
 * Using Arduino UNO
 */

/*
UNO's hardware SPI pins:
11, MOSI, SER on my board
12, MISO, Not used for me.
13, SCK (Shift Reg Clock)
Any GPIO:
10, Shift Reg Latching Clock, RCK
*/

const byte rckPin = 10;
unsigned int onPulseLengthMicros = 75;  // 1000 = 1ms         75
unsigned int offPulseLengthMicros = 50; // 1000 = 1ms         50 
unsigned int onRecoverTime = 8;           //                  5
unsigned int offRecoverTime = 8;        //                    5   seems to work great!
mcp mcp(rckPin); // Create a new Matrix CoProcessor and tell it that pin 10 is the latching clock pin.

int testDelay = 250;


void setup()
{
  delay(1000);
  //  Serial.begin(9600);
  //fix for weird backwards dot on my display.
  mcp.dotOn(45, 7, offPulseLengthMicros, offRecoverTime);
}

void loop()
{
  testPattern5();
}

void testPattern2()
{
  mcp.dotOn(1, 1, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 1, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);

  mcp.dotOn(1, 2, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 2, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);

  mcp.dotOn(1, 3, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 3, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);


  mcp.dotOn(1, 4, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 4, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);


  mcp.dotOn(1, 5, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 5, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);


  mcp.dotOn(1, 6, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 6, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);


  mcp.dotOn(1, 7, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);

  mcp.dotOff(1, 7, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);
}

void testPattern3() {
  mcp.dotOn(1, 1, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 2, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 3, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 4, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 5, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 6, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(1, 7, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);
  mcp.dotOff(1, 1, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 2, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 3, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 4, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 5, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 6, onPulseLengthMicros, onRecoverTime);
  mcp.dotOff(1, 7, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);
}

void testPattern4() {
  mcp.dotOn(1, 1, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(2, 2, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(3, 3, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(4, 4, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(5, 5, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(6, 6, onPulseLengthMicros, onRecoverTime);
  mcp.dotOn(7, 7, onPulseLengthMicros, onRecoverTime);
  delay(testDelay);
  mcp.dotOff(1, 1, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(2, 2, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(3, 3, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(4, 4, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(5, 5, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(6, 6, offPulseLengthMicros, offRecoverTime);
  mcp.dotOff(7, 7, offPulseLengthMicros, offRecoverTime);
  delay(testDelay);
}

void testPattern5() {

  for (int x = 1; x < 46; x++) {
    for (int y = 1; y < 8; y++) {
      mcp.dotOn(x, y, onPulseLengthMicros, onRecoverTime);
      delay(testDelay/4);
    }
  }

  for (int x = 1; x < 46; x++) {
    for (int y = 1; y < 8; y++) {
      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
      delay(testDelay/4);
    }
  }

  delay(2000);

}

void testPattern6() {
  for (int x = 1; x < 46; x++) {
    for (int y = 1; y < 8; y++) {
      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
    }
  }

  for (int i = 0; i < 250; i++) {
    mcp.dotOn(random(1, 46), random(1, 8), offPulseLengthMicros, offRecoverTime);
    delay(testDelay);
  }

}

void testPattern8() {
  // Cycle through characters, maybe.
  // char myChar = 'A';

  for (int x = 1; x < 12; x++) {
    for (int y = 1; y < 8; y++) {
      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
    }
  }

  for (char blah = '0'; blah < 127; blah++) {
    mcp.drawChar(1, 1, blah, onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 3, 3);
    delay(150);
    mcp.drawCharInverse(1, 1, blah, onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 3, 3);
    delay(50);
  }




  delay(10000);
}

void testPattern9() {

  mcp.drawChar(1, 1, 'H', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, true, 2, 1);
  mcp.drawChar(1 + 6, 1, 'e', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, true, 2, 1);
  mcp.drawChar(1 + 6 + 6, 1, 'l', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, true, 2, 1);
  mcp.drawChar(1 + 6 + 6 + 6, 1, 'l', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, true, 2, 1);
  mcp.drawChar(1 + 6 + 6 + 6 + 5, 1, 'o', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, true, 2, 1);
  delay(10000);
}

void testPattern10() {
  for (int x = 1; x < 45; x++) {
    for (int y = 1; y < 8; y++) {
      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
    }
  }
  mcp.drawChar(1, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6 + 6, 1, ':', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6 + 6 + 6, 1, '2', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6 + 6 + 6 + 6, 1, '7', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6 + 6 + 6 + 6 + 5, 1, 'a', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawChar(1 + 6 + 6 + 6 + 6 + 6 + 6, 1, ' ', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);

  delay(10000);
}


void testPattern11() {
  //    for (int x = 1; x < 45; x++) {
  //    for (int y = 1; y < 8; y++) {
  //      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
  //      mcp.dotOff(x, y, offPulseLengthMicros, offRecoverTime);
  //    }
  //  }
  mcp.drawCharInverse(1, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawCharInverse(1 + 6, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawCharInverse(1 + 6 + 6, 1, ':', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawCharInverse(1 + 6 + 6 + 6, 1, '2', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawCharInverse(1 + 6 + 6 + 6 + 6, 1, '7', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  mcp.drawCharInverse(1 + 6 + 6 + 6 + 6 + 6, 1, 'p', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 2, 2);
  delay(500);

  mcp.drawChar(1, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6, 1, ':', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6, 1, '2', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6 + 6, 1, '7', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6 + 6 + 6, 1, 'p', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6, 1, '1', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6, 1, ':', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6, 1, '2', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6 + 6, 1, '7', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);
  mcp.drawChar(1 + 6 + 6 + 6 + 6 + 6, 1, 'p', onPulseLengthMicros, offPulseLengthMicros, onRecoverTime, offRecoverTime, false, 1, 1);

  delay(5000);
}
