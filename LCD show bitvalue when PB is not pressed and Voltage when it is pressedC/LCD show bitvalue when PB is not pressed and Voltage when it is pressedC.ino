/*Connect LCD and Display bitvalue and voltage on the same screen.
This program must diplay the bit value from Analog input and its converted
voltage on LCD, as well, as printing those  values on Serial Monitor*/

#include <LiquidCrystal.h> // Include the library code

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*Since I only have 1 potentiometer available, I added a code that 
can adjust the backlight similar to potentiometer that changes it*/
int backlightPin = 9;        // Assign pin 9 (PWM) for setting brightness range
int brightness = 70;         // This is to adjust the brightness of LCD
const int buttonPin = 13;    // Assign buttonPin to 13 as const integer
int buttonState;             // Define buttonState as integer

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);      // Set buttonPin as internal pullup
  pinMode(backlightPin, OUTPUT);         // Set the backlightPin (9) as OUTPUT
  lcd.begin(16, 2);                      // LCD Commucication: Initialize the LCD object 
                                         // and sets the number of columns and rows of the LCD 
  Serial.begin(9600);                    // Serial communication at 9600 bits per second
}

void loop() {
  buttonState = digitalRead(buttonPin);       // Read the bitValue from buttonPin (pin 9)
 
   analogWrite(backlightPin, brightness);     // Adjust the brightness of LCDW
                                              // by writing the value from brightness value
  int bitValue = analogRead(A0);              // This reads the input on analog pin 0 (A0)
  float slope =5.0/1023.0;                    // Formula to find slope
  float voltage = (bitValue*slope);           // Formula to convert bit value to voltage

  if (buttonState == HIGH) {                // If button is not pressed, display bit value on LCD
      lcd.clear();                          // Clear the display before updating it
      lcd.setCursor(0, 0);                  // Set the position in LCD (Starting from left column and top row) 
      lcd.print("Bit = ");                  // Then print the bitValue
      lcd.print(bitValue);
}   
else {                                      // If button is pressed, display voltage value on LCD
      lcd.clear();                          // Clear the display before updating it
      lcd.setCursor(0, 0);                  // Set the position in LCD (Starting from left column and bottom row)
      lcd.print("Voltage = ");              // Then print the voltage 
      lcd.print(voltage);
}
// Print both bit value and voltage on Serial Monitor in an order way
  Serial.print("Bit = ");
  Serial.print(bitValue); 
  Serial.print("\t");
  Serial.print("the voltage is =");
  Serial.println(voltage);
}