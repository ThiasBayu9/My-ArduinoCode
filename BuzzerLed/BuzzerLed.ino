int pos = 00;
int buzz = 13;
int led0 = 7;
int led1 = 5;

void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  
}

void loop() {
  digitalWrite(led0, HIGH);
  digitalWrite(led1, LOW);
  delay(1000);

  for(led0 == HIGH;){
    digitalWrite(buzz, HIGH);
    delay(500);
    }
  digitalWrite(led0, LOW);
  digitalWrite(led1, HIGH);
  delay(1000);
}
