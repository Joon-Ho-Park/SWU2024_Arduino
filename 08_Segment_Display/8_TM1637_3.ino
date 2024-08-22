#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(15);
}

void loop() {
  char data[] = { 0xFF, 0xFF, 0xFF, 0xFF };
  char blank[] = { 0x00, 0x00, 0x00, 0x00 };

  // All segments on
  display.setSegments(data);
  delay(1000);

  // All segments off
  display.setSegments(blank);
  delay(1000);

  // Selectively set different digits
  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(3);
  data[2] = display.encodeDigit(6);
  data[3] = display.encodeDigit(5);
  display.setSegments(data);
  delay(1000);
}
