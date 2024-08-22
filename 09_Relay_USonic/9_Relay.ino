#define RELAY_PIN 12

void setup(void)
{
  pinMode(RELAY_PIN, OUTPUT);
}

void loop(void)
{
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}


/*
	// How to use relay_control()


#define RELAY_1   12   // high-level-trigger 
#define RELAY_2   13   // low-level-trigger 

#define CONNECT   1
#define DISCONN   0

void setup(void)
{
  ...
}

void loop(void)
{
  ...
  relay_control(RELAY_1, CONNECT);
  ...
  relay_control(RELAY_2, DISCONN);
  ...
}

void relay_control(int relay, int value)
{
  int num;
  switch(relay)
  {
    case RELAY_1:  // high-level-trigger
      if(value == CONNECT)
        digitalWrite(relay, HIGH);
      else  
        digitalWrite(relay, LOW);
      break;

    case RELAY_2:    
      if(value == CONNECT)
        digitalWrite(relay, LOW);
      else  
        digitalWrite(relay, HIGH);
      break;
  }
}
*/