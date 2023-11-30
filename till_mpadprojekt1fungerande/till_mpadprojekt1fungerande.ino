#include <Wire.h>
#include <Servo.h>


Servo myservo1;
Servo myservo2;
Servo myservo3;

int i = 0;
//int j = i;
const int trigPin = 10;
const int echoPin = 11;
// defines variables
long duration;
int distance;

void setup() {
  pinMode(4, OUTPUT);
  //pinMode(2, INPUT);

  myservo1.attach(9);
  myservo2.attach(6);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  
  for (i = 0; i < 180; i = i + 10) {
    delay(50);
    checkDist();
    if (distance < 10) {
      setLazer();
        delay(2000);
          ( i=i-10);
    }
    else{
    myservo1.write(i);
     digitalWrite(4, LOW);
    }
  }

  for (i = 180; i > 0; i = i - 10) {
     delay(50);
    checkDist();
    if (distance < 10) {
      setLazer();
      delay(2000);
      ( i=i+10);
    }
    else{
     myservo1.write(i);
      digitalWrite(4, LOW);
    }
  }
}


void checkDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Serial.print("Distance: "); Kan använda denna kod om jag vill se vad jag får ut
  // Serial.println(distance); Kan använda denna kod om jag vill se vad jag får ut


}
void setLazer() {
  
  myservo2.write(i);
   delay(20);
  digitalWrite(4, HIGH);
  delay(50);
  
}
