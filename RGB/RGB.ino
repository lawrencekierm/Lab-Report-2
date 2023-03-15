/* RGB Selector
This program select a specific color to light up the RGB LED.
I have used "analogWrite" to obtain various signal from 0 to 255
(maximum) for lighting a color of my choice. I am able to easily
change the color of LED by setting a specific signal range of 
redPin, greenPin and bluePin with a use of "setColor" function .
*/
int redPin= 9;            // Assign redPin to pin 9 as integer
int greenPin = 10;        // Assign greenPin to pin 10 as integer
int bluePin = 11;         // Assign bluePin to pin 11 as integer

void setup() {
    for (int x=0 ; x<12 ; x++) {  // This loop goes through pin 9 to 11
      pinMode(x, OUTPUT);         // Each pin is assigned as an OUTPUT
       }
}

void loop() {                  // "setColor" changes the value in redPin, greenPin and bluePin
  setColor(255,255,255);       // White color

  // setColor(255, 234, 0);    Bright Yellow color
  // setColor(255, 0, 0);      Red color
  // setColor(147, 197, 114);  Pistachio color
  // setColor(255,165,0);      Orange color 
}

void setColor(int redValue, int greenValue, int blueValue) {   // It brings the written value from "setColor" in void loop
  analogWrite(redPin, redValue);        // It writes the redPin as whatever value is set in redValue
  analogWrite(greenPin, greenValue);    // It writes the greenPin as whatever value is set in greenValue
  analogWrite(bluePin, blueValue);      // It writes the bluePin as whatever value is set in blueValue
}