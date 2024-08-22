#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(15);
}

void loop() {  

  display.showNumberDec(365, false); // Expect: _365
  delay(1000);

  display.showNumberDec(365, true); // Expect: 0365
  delay(1000);

  display.showNumberDec(-12, false); // Expect: _-12
  delay(1000);

  display.showNumberHexEx(0xf1af);   // Expect: f1Af
  delay(1000);

  display.showNumberHexEx(0x2c);     // Expect: __2C
  delay(1000);

  display.showNumberHexEx(0xd1, 0, true); // Expect: 00d1
  delay(1000);
}
