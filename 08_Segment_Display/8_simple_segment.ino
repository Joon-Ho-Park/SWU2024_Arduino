#define PIN_A   3
#define PIN_B   4
#define PIN_C   5
#define PIN_D   6
#define PIN_E   7
#define PIN_F   8
#define PIN_G   9
#define PIN_DP  10

bool digits[][8] = {
  {LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  HIGH, HIGH},
  {HIGH, LOW,  LOW,  HIGH, HIGH, HIGH,  HIGH, HIGH},
  {LOW,  LOW,  HIGH,  LOW,  LOW, HIGH,  LOW, HIGH},
};

int pin_order[8] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_DP};

void setup()
{
  pinMode(PIN_A, OUTPUT);  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);  pinMode(PIN_DP, OUTPUT);
}

void print_digit(int n)
{
  for(int i=0;i<8;i++)
    digitalWrite(pin_order[i], digits[n][i]);
}

void loop()
{
  print_digit(0);
  delay(1000);
  print_digit(1);
  delay(1000);
  print_digit(2);
  delay(1000);
}
