#define DATA_PIN  8
#define LATCH_PIN 9
#define CLOCK_PIN 10

#define NUM_SHIFT_REGS 2
#define TOTAL_SIZE (NUM_SHIFT_REGS * 8)

bool registers[TOTAL_SIZE];

void setup() {
  init_register();
}

void loop() {
  for (int i=0;i<16;i++)
  {
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
  for (int i = TOTAL_SIZE - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}

void set_register(int index, int value) {
  registers[index] = value;
}

void write_registers() {
  digitalWrite(LATCH_PIN, LOW);
  for (int i = TOTAL_SIZE - 1; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, registers[i]);
    digitalWrite(CLOCK_PIN, HIGH);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

