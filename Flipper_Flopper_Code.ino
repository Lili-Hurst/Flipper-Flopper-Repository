#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider
int on = 0;
int servo_1 = 9;
int servo_2 = 10;
int servo_3 = 11;
int k;
int potpin = 30;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin


void setup() {
 // myservo.attach(9);  // attaches the servo on pin 9 to the servo object
   Serial.begin(9600); 
}

void loop() {
  photocellReading = analogRead(photocellPin);  
 
  //Serial.print("Analog reading = ");
  //Serial.print(photocellReading);     // the raw analog reading
 
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 500) 
  {
    on =1;
    int k =0;
    k = servo_move(on, servo_1);
    delay (40);
    k = servo_move(on, servo_2);
    delay (40);
    k = servo_move(on, servo_3);
    delay(40);
    k = servo_move2(on);
  } 
  else 
  {
    on=0;
    Serial.println("Waiting for input");
    k = servo_move(on, servo_1);
    k = servo_move(on, servo_2);
    k = servo_move(on, servo_3);
    k = servo_move2(on);
  }
  //delay(40);
}

//function
int servo_move(int x, int y)
{
// myservo.attach(y);  // attaches the servo on pin 9 to the servo object
  if (x==1)
  {
    pinMode(6, OUTPUT);
     noTone(6);
    pinMode(8, OUTPUT);
     digitalWrite(8, LOW);
     pinMode(4, OUTPUT);
     digitalWrite(4, HIGH);
     myservo.attach(y);
      for (pos = 0; pos <= 180; pos += 10) 
      { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(40);                       // waits 15ms for the servo to reach the position
      }
  for (pos = 180; pos >= 0; pos -=10) 
      { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(40);                       // waits 15ms for the servo to reach the position
      }
  }
  else 
  {
     myservo.detach();
      pinMode(6, OUTPUT);
     tone(6, 600);
     pinMode(8, OUTPUT);
     digitalWrite(8, HIGH);
     pinMode(4, OUTPUT);
     digitalWrite(4, LOW);
  }
  return 0;
}

int servo_move2(int x)
{
  if(x==1)
  {
    pinMode(6, OUTPUT);
    noTone(6);
    pinMode(8, OUTPUT);
    digitalWrite(8, LOW);
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
 /* val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(40);   */                        // waits for the servo to get there
        for (pos = 0; pos <= 60; pos += 10) 
      { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(50);                       // waits 15ms for the servo to reach the position
      }
      delay(500);
  for (pos = 60; pos >= 0; pos -=10) 
      { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(50);                       // waits 15ms for the servo to reach the position
      }
  }
   else 
  {
     myservo.detach();
      pinMode(6, OUTPUT);
     tone(6, 600);
     pinMode(8, OUTPUT);
     digitalWrite(8, HIGH);
     pinMode(4, OUTPUT);
     digitalWrite(4, LOW);
  }
  return 0;
}
