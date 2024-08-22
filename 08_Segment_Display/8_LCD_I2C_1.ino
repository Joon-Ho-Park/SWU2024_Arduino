#include <LiquidCrystal_I2C.h>

// Define the I2C address for the LCD
#define LCD_COLUMNS 16
#define LCD_ROWS    2
#define LCD_ADDR    0x27

// Initialize the LCD
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup() 
{
  lcd.init();
  lcd.backlight();
}

void loop(void)
{
  lcd.setCursor(0,0);
  lcd.print("Hello World");
  lcd.setCursor(0,1);
  lcd.print("Arduino...");
}