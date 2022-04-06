#include <Servo.h>
Servo reee;
int pos = 00;
int state = 0;
int buzz = 5; //pin buzzer
int ledG = 6; //pin LED Green
int ledR = 7; //pin LED Red
int UltraT = 8; //pin Ultrasonic Trigger
int UltraE = 9; //pin Ultrasonic Echo
long cm, duration, distance; //inisiasi data type "long" //long boii

void setup() {
  reee.attach(13);
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(UltraT, OUTPUT);
  pinMode(UltraE, INPUT);
  digitalWrite(UltraT, LOW);
  digitalWrite(UltraE, LOW);
}

void measureDistance(){//function untuk mengatur jarak ultrasonic
  digitalWrite(UltraT, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraT, LOW);
  delayMicroseconds(5);
  duration=pulseIn(UltraE, HIGH);
  distance=(duration/2)/29.1;
  cm = microsecondsToCentimeters(distance);
}

void loop() {
  measureDistance();
  Serial.print(distance);// ini untuk menampilkan jarak di serial
  Serial.println("cm");

  if(distance>200){
      tone(buzz, 500); //buzzer berbunyi♪
      digitalWrite(ledG, HIGH); //LED Green hidup
      delay(500);
      noTone(buzz); //buzzer diam
      digitalWrite(ledG, LOW); //LED Green mati(RIP)
      delay(500);

      for(pos = 00; pos < 180; pos += 1) //┐
      {                                  //║
        reee.write(pos);                 //╠═ ini untuk menggerakan motor servo 180° secara perlahan
        delay(15);                       //║
      }                                  //┘
      
      tone(buzz, 500);
      digitalWrite(ledG, HIGH);
      delay(500);
      noTone(buzz);
      digitalWrite(ledG, LOW);
      delay(500);

      for(pos = 180; pos >= 1; pos -= 1) //┐
      {                                  //║
        reee.write(pos);                 //╠═ ini untuk menggerakan balik motor servo 180° secara perlahan
        delay(15);                       //║
      }                                  //┘
      
  }else{
    digitalWrite(ledR, HIGH); //LED Red hidup
      delay(1000);

      digitalWrite(ledR, LOW); //LED Red mati(RIP)
      delay(1000);
  }
}
long microsecondsToCentimeters(long microseconds){// mereset kembali jarak sensor ultrasonic
    return microseconds/29/2;
  }
