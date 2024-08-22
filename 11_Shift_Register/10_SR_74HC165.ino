#define HC165_DATA_PIN  2
#define HC165_LATCH_PIN 4
#define HC165_CLOCK_PIN 3

#define HC595_DATA_PIN  8
#define HC595_LATCH_PIN 9
#define HC595_CLOCK_PIN 10

bool registers[8];

void setup() {
  init_register();
}

void loop() {
  read_registers();
  write_registers();
  delay(100);
}

void init_register() {
  pinMode(HC595_DATA_PIN, OUTPUT);
  pinMode(HC595_CLOCK_PIN, OUTPUT);
  pinMode(HC595_LATCH_PIN, OUTPUT);

  pinMode(HC165_DATA_PIN, INPUT);
  pinMode(HC165_CLOCK_PIN, OUTPUT);
  pinMode(HC165_LATCH_PIN, OUTPUT);

  clear_registers();
  write_registers();
}

void clear_registers() {
  for (int i = 0; i < 8; i++) {
    registers[i] = LOW;
  }
}

void set_register(int index, int value) {
  registers[index] = value;
}

void write_registers() {
  digitalWrite(HC595_LATCH_PIN, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(HC595_CLOCK_PIN, LOW);
    digitalWrite(HC595_DATA_PIN, registers[i]);
    digitalWrite(HC595_CLOCK_PIN, HIGH);
  }
  digitalWrite(HC595_LATCH_PIN, HIGH);
}

void read_registers() {
  digitalWrite(HC165_LATCH_PIN, LOW);
  digitalWrite(HC165_LATCH_PIN, HIGH);

  for (int i = 0; i < 8; i++) {
    int bit = digitalRead(HC165_DATA_PIN);
    bit == HIGH ? registers[i] = HIGH : registers[i] = LOW;

    digitalWrite(HC165_CLOCK_PIN, HIGH);
    digitalWrite(HC165_CLOCK_PIN, LOW);
  }
}

