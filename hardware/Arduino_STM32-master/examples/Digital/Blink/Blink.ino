/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  Modified by Roger Clark. www.rogerclark.net for Maple mini 25th April 2015 , where the LED is on PB1

 */
int i = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PB1 as an output.
  pinMode(33, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);



}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(33, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5);              // wait for a second
  digitalWrite(33, LOW);    // turn the LED off by making the voltage LOW
  delay(5);              // wait for a second
  Serial1.print("Serial1!");
  Serial2.print("Serial2!");
  Serial3.print("Serial3!");
  Serial.print("Serial!");

  Serial1.println(i);
  Serial2.println(i);
  Serial3.println(i);
  Serial.println(i);

  i++;
}