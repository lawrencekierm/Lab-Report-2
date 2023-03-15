/* LCD with Arduino to work as ohmmeter with display the Ω symbol.
This program creates an ohmmeter with Arduino, measurimg the resistance 
of an unknown resistor and display the value on an LCD screen
with appropriate engineering prefix and unit.*/
        
float Va = 0;            // Initialize Va to 0
float Ra = 1000.0;       // Initialize Ra (known resistor) to 1000
float Rb = 0;            // Initialize Rb (unknown resistor) to 0
float Vin = 5;           // Initialize Vin to 5

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
int backlightPin = 9;         // Assign pin 9 (PWM) for setting range
int contrast = 70;            // This is to adjust the contrast of LCD

// Create special character from "http://omerk.github.io/lcdchargen/"
byte ohm[] = {          // This array creates a symbol of ohm unit on LCD
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

void setup() {
  pinMode(backlightPin, OUTPUT);       // Set the backlightPin (9) as OUTPUT
  analogWrite(backlightPin, contrast); // Adjust the contrast of LCD
  Serial.begin(9600);                  //serial communication at 9600 bits per second
  lcd.begin(16, 2);                    // LCD Commucication: Initialize the LCD object 
                                       // and sets the number of columns and rows of the LCD 
  lcd.createChar(0, ohm);              // Command for creating a custom character
  lcd.home();                          // Command for custom character position on LCD
}
void loop()  {
  float bitValue = analogRead(A0);    // The analogRead() function reads the bin value at pin A0.
  float slope =5.0/1023.0;            // Slope to convert bit to voltage
  float Va = (bitValue*slope);        // Formula to convert bit value to voltgae
  
  // To calculate Rb(unknown resistor) using Ohm's law:
  // Vin is the voltage from the source (5V)
  // Va is the voltage after Ra which is determined by converted voltage at A0   
  float Ia = (Vin-Va)/Ra;        // Caculate the current by dividing the voltage across Ra to Ra
  // Since the circuit is considered series, Ia is equavalent to Itotal or Ib
  float Rb = (Va-0)/Ia;          // Calculate Rb by diving Va to Ia
  
  // Print the Rb value on Serial monitor 
  Serial.print("Rb ="); 
  Serial.println(Rb);
  
  lcd.clear();                                // clear the display before updating it
  lcd.setCursor(0, 0);                        // position the lcd.print on LCD
  lcd.print("UnkownResistance");              // print on LCD

 if (Rb >= 1000) {              // If the resistance value is 1000 or above convert it with engineering prefix
  Rb = Rb/1000;                 // Converting resistane with prefix     
  lcd.clear();                  // Clear the display before updating it
  lcd.setCursor(0, 1);          // Position of lcd.print on the LCD
  lcd.print(Rb);                // Print Rb value
  lcd.print("k");               // add "k" after Rb value
  lcd.setCursor(7, 1);          // position of custom character
  lcd.write(byte(0));           // print ohm symbol 
 } else {                       // Rsistance below 1k resistance
  lcd.clear();                  // Clear the display before updating it
  lcd.setCursor(0, 1);          // Position of lcd.print on the LCD
  lcd.print(Rb);                // Print Rb value
  lcd.setCursor(7, 1);          // position of custom character
  lcd.write(byte(0));           // print ohm symbol
  }
}
