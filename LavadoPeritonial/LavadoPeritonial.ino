#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin
int led = 13;

int in1 = 7;
int in2 = 8;
int in3 = 9;
int in4 = 10;

int sensorValue = 0;
const long interval = 750;
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(0, INPUT); 
  pinMode(in1, INPUT);
  digitalWrite(in1, HIGH);
  delay(2);
  pinMode(in2, INPUT);
  digitalWrite(in2, HIGH);
  delay(2);
  pinMode(in3, INPUT);
  digitalWrite(in3, HIGH);
  delay(2);
  pinMode(in4, INPUT);
  digitalWrite(in4, HIGH);
  delay(2);
  pinMode(led, OUTPUT);
  myservo.attach(5);
  //myservo.write(90);
  Serial.begin(9600);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(50);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);
}

int d1=1;
int d2=1;
int d3=1;
int d4=1;

void loop() {
  //input your main code here, to run repeatedly:
  int sensorValue = analogRead(0);
  delay(10);
  digitalWrite(led, HIGH);
  delay(10);
  if (sensorValue < 600) {
    digitalWrite(led, LOW);
    delay(100);
  }

  d1 = digitalRead(in1);
  delay(10);
  d2 = digitalRead(in2);
  delay(10);
  d3 = digitalRead(in3);
  delay(10);
  d4 = digitalRead(in4);                                                                                                                                d4 = digitalRead(in4);
  delay(10);

  unsigned long currentMillis = millis();

  if (d1 == 0)
  {
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    val = 30;
    }
  }
  else if (d2 == 0)
  {
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    val = 85;
    }
  }
  else if (d3 == 0)
  {
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    val = 125;
    }
  }
  else if (d4 == 0)
  {
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    val = 165;
    }
  }

  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);
  Serial.print(d1);
  Serial.print(",");
  Serial.print(d2);
  Serial.print(",");
  Serial.print(d3);
  Serial.print(",");
  Serial.print(d4);
  Serial.print(", ");
  Serial.print(val);
  Serial.print(", ");
  Serial.println(sensorValue);
}
