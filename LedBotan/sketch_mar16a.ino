int botan = 12;
int LedM =  7;
int LedK =  5;
int LedH =  3;

int botanState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(LedM, OUTPUT);
  pinMode(LedK, OUTPUT);
  pinMode(LedH, OUTPUT);
  pinMode(botan, INPUT_PULLUP);
}

void loop() {
  botanState = digitalRead(botan);

  if(botanState == LOW){
    LedM_light();
    delay(5000);
    LedK_light();
    delay(2000);
    LedH_light();
    delay(5000);

    return LedM_light();
  }
  else if (botanState == HIGH){
    digitalWrite (LedM, LOW);
    digitalWrite (LedK, LOW);
    digitalWrite (LedH, LOW);
  }
}

void LedH_light()
{
  digitalWrite(LedH, HIGH);
  digitalWrite(LedK, LOW);
  digitalWrite(LedM, LOW);
}

void LedK_light()
{
  digitalWrite(LedH, LOW);
  digitalWrite(LedK, HIGH);
  digitalWrite(LedM, LOW);
}

void LedM_light()
{
  digitalWrite(LedH, LOW);
  digitalWrite(LedK, LOW);
  digitalWrite(LedM, HIGH);
}
