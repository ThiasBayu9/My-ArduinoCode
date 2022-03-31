#include <Servo.h>
Servo reee;
int pos = 00;
int buzz = 8;
int ldr = 13;
int ledB = 6;
int ledR = 7;



void setup() {
  reee.attach(11);
  pinMode(buzz, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ldr, INPUT);
}


int targetState = LOW;
int counter = 0;

void loop() {
  if(digitalRead(ldr)==targetState){
    counter++;
  }else{
    targetState = digitalRead(ldr);
    counter=0;
  }

  if(counter > 100){
    if(targetState){
      tone(buzz, 500);
      delay(500);
      noTone(buzz);
      delay(500);

      for(pos = 00; pos < 180; pos += 1)
      {
        reee.write(pos);
        delay(15);
      }
      
      tone(buzz, 500);
      delay(500);
      noTone(buzz);
      delay(500);

      for(pos = 180; pos >= 1; pos -= 1)
      {
        reee.write(pos);
        delay(15);
      }
    }else{
      digitalWrite(ledR, HIGH);
      digitalWrite(ledB, LOW);
      delay(1000);

      digitalWrite(ledR, LOW);
      digitalWrite(ledB, HIGH);
      delay(1000);
      
      digitalWrite(ledR, LOW);
      digitalWrite(ledB, LOW);
      delay(1000);
    }
  }
  delay(10);
}
