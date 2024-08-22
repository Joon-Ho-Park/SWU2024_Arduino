
#define DATA_PIN  8
#define LATCH_PIN 9
#define CLOCK_PIN 10

bool registers[8];

void setup() {
  init_register();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    clear_registers();
    set_register(i, HIGH);
    write_registers();
    delay(100);
  }
}

void init_register() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
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
  digitalWrite(LATCH_PIN, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, registers[i]);
    digitalWrite(CLOCK_PIN, HIGH);
  }
  digitalWrite(LATCH_PIN, HIGH);
}



