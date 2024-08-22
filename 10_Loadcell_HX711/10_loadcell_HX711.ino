#include "HX711.h"
#include <LiquidCrystal_I2C.h>

#define LOADCELL_DOUT_PIN   2
#define LOADCELL_SCK_PIN    3
#define TAB_SWITCH  13        

HX711 scale;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(TAB_SWITCH, INPUT_PULLUP);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  calibration();
}

long calibration_factor;

void loop() {
  float value;

  value = 0.4536*scale.get_units(5);

  lcd.setCursor(0,0);
  lcd.print(value);
  lcd.print(" kg                ");

  lcd.setCursor(0,1);
  lcd.print("cal : ");
  lcd.print(calibration_factor);
  lcd.print("                   ");
  delay(1000);
}


#define STEP_1  100
#define STEP_2  200
#define STEP_3  300

int state = STEP_1;

void calibration() {
  float value;
  bool done = false;

  while(!done)
  {
    switch(state)
    {
      case STEP_1:
        lcd.setCursor(0,0);
        lcd.print("STEP 1");      
        lcd.setCursor(0,1);
        lcd.print("Empty the scale");
        if(digitalRead(TAB_SWITCH) == LOW)
        {
          scale.set_scale();
          scale.tare();
          state = STEP_2;
          delay(500);
        }
        break;

      case STEP_2:
        lcd.setCursor(0,0);
        lcd.print("STEP 2");      
        lcd.setCursor(0,1);
        lcd.print("Put 3kg on the scale");
        if(digitalRead(TAB_SWITCH) == LOW)
        {
          value = 0.4536*scale.get_units(5);
          calibration_factor = value/3;
          scale.set_scale(calibration_factor);
          state = STEP_3;
          delay(500);
        }
        break;

      case STEP_3:
        lcd.setCursor(0,0);
        lcd.print("STEP 3 : ");      
        lcd.print(calibration_factor);

        value = 0.4536*scale.get_units(5);

        lcd.setCursor(0,1);
        lcd.print("After cal : ");      
        lcd.print(value);
        lcd.print(" kg         ");      

        if(digitalRead(TAB_SWITCH) == LOW)
        {
          done = true;
          delay(500);
        }
        break;
    }
  }
}


long get_eeprom(int addr)
{
  long val;
  char *p = (char*)&val;

  for(int i = 0; i < 8; i++)
    *p++ = EEPROM.read(i + addr);

  return val;
}

void set_eeprom(int addr, long val)
{
  char *p = (char*)&val;

  for(int i=0; i < 8; i++)
    EEPROM.write(i + addr, *p++);
}

