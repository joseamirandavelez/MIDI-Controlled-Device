/*
 * RGB TEST
 * This is a test code to test the Arduino's capability to receive data from
 * the serial port and control an RGB LED. The idea is to be able to control
 * the divice with another MIDI device in the future. Baby steps...
 * 
 * Author: Jose Miranda
 * License: Apache 2.0, January 2004
 * 
 */

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
char inChar;
int ledTurn=1;

void setup()
{
  Serial.println("Starting MIDI communications...");
  Serial.begin(115200);
  /*
  Serial.print("Waiting response from sequencer");
  
  do
  {
    Serial.print(".");
  } while (!Serial.available());
  */
  Serial.println("");
  Serial.println("Sequencer connected!");
  Serial.println("MIDI Device Ready!");

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop()
{
  if (Serial.available())
  {
    inChar = Serial.read();
    //Serial.write(inChar);
    Serial.print(inChar);
    inChar="";
    if      (ledTurn==1) {analogWrite(redPin, 255);   ledTurn=2;}
    else if (ledTurn==2) {analogWrite(greenPin, 255); ledTurn=3;}
    else if (ledTurn==3) {analogWrite(bluePin, 255);  ledTurn=1;}
    delay(15);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
    /*
    setColor(1, 0, 0);
    */
  }
}
 
//void setColor(int red, int green, int blue)
//{
//  analogWrite(redPin, red);
//  analogWrite(greenPin, green);
//  analogWrite(bluePin, blue);  
//}
