/*Connect LCD and Display bitvalue and voltage on the same screen.
This program must diplay the bit value from Analog input and its converted
voltage on LCD, as well, as printing those on Serial Monitor*/

#include <LiquidCrystal.h> // Include the library code

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*Since I only have 1 potentiometer available, I added a code that 
can adjust the contrast similar to potentiometer that changes it*/
int backlightPin = 9;     // Assign pin 9 (PWM) for setting range
int contrast = 70;      // This is to adjust the contrast of LCD

void setup() {
  pinMode(backlightPin, OUTPUT);   // Set the backlightPin (9) as OUTPUT
  lcd.begin(16, 2);
  Serial.begin(9600);       //serial communication at 9600 bits per second
}

void loop() {
   analogWrite(backlightPin, contrast);       // Adjust the contrast of LCD
                                              // by writing the value from contrast value
  int bitValue = analogRead(A0);              // This reads the input on analog pin 0 (A0)
  float slope =5.0/1023.0;                    // Formula to find slope
  float voltage = (bitValue*slope);           // Formula to convert bit value to voltage
  lcd.clear();                                // clear the display before updating it
  lcd.setCursor(0, 0);                        // Set the position in LCD (Starting from left column and top row) 
  lcd.print("Bit = ");                        // Then print the bitValue
  lcd.print(bitValue);

  lcd.setCursor(0, 1);                        // Set the position in LCD (Starting from left column and bottom row)
  lcd.print("Voltage = ");                    // Then print the voltage 
  lcd.print(voltage); 
  
// Print both bit value and voltage on Serial Monitor in an order way
  Serial.print("Bit = ");
  Serial.print(bitValue); 
  Serial.print("\t");
  Serial.print("the voltage is =");
  Serial.println(voltage);
}