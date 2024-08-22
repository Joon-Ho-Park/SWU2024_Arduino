#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG 9 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 8 //ECHO 핀 설정 (초음파 받는 핀)

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.init();
  lcd.backlight();
}

double sonic_read(void)
{
  unsigned long duration;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  delayMicroseconds(200);
  duration = pulseIn(ECHO, HIGH);
  return ((double)duration * 0.00034 / 2);
}

void loop(void)
{
  double distance1, distance2, speed, diff;
  unsigned long t1, t2;

  while(1)
  {
    distance1 = sonic_read();
    t1 = micros();
    distance2 = sonic_read();
    t2 = micros();

    diff = (double)(t2 - t1)/1000000.0;

    speed = (distance2 - distance1) * 1.0 / (diff);
    if(speed < 0)
      speed *= (-1);

    if(speed > 1)
    {
      lcd.setCursor(0,0);
      lcd.print("distance : ");
      lcd.print(distance2);
      lcd.print(" m");
      lcd.setCursor(0,1);
      lcd.print("speed : ");
      lcd.print(speed);
      lcd.print(" m/s");
    }
    delayMicroseconds(100);
  }
}

