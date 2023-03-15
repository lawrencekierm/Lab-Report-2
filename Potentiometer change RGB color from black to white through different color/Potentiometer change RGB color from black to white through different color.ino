/*Potentiometer change RGB color from black to white through different color variations
This program changes the color of LED as I adjust the potentiometer. The color must be
from white to black through different color variations. To achieve this, I have used
Analog input for variation in bit value that I will use to set range in changing LED colors.
In this case, I have used voltage range (converted from bit value) to set the range of 
each different colors.
*/

int redPin= 9;            // Assign redPin to pin 9 as integer
int greenPin = 10;        // Assign greenPin to pin 10 as integer
int bluePin = 11;         // Assign bluePin to pin 11 as integer

void setup() {
  for (int x=9 ; x<=11 ; x++) {  // This loop goes through pin 9 to 11
    pinMode(x, OUTPUT);          // Each pin is assigned as an OUTPUT
  }
    Serial.begin(9600);   // Serial communication at 9600 bits per second
}

void loop() {  
  int bitValue = analogRead(A0);      // This reads the bit value on analog pin 0 (A0)
  float slope =5.0/1023.0;            // This is the formula to find slope (bit to voltage)
  float voltage = (bitValue*slope);   // This is the formula to convert bit value to voltage

  int R = 0;  // Set R as integer
  int G = 0;  // Set G as integer
  int B = 0;  // Set B as integer
  if (voltage == 0.0 ) {                       // LED OFF
      R = 0;
      G = 0;
      B = 0;
  } else if (voltage > 0.0 && voltage <1.5 ) { // LED GREEN
      R = 0;
      G = 255;
      B = 0;
  } else if (voltage > 1.5 && voltage < 3.0) { // LED BLUE
      R = 0;
      G = 0;
      B = 255;
  } else if (voltage > 3.0 && voltage < 4.5) { // LED RED
      R = 255;
      G = 0;
      B = 0;
  } else if (voltage > 4.5 && voltage < 5.0) { // LED VIOLET
      R = 127;
      G = 0;
      B = 255;
  }  else if (voltage == 5.0) {                // LED WHITE
      R = 255;
      G = 255;
      B = 255;
  }
  analogWrite(redPin, R);     // Writes value from R for redPin
  analogWrite(greenPin, G);   // Writes value from G for greenPin
  analogWrite(bluePin, B);    // Writes value from B for bluePin

// Print both bit value and voltage on Serial Monitor in an order way
Serial.print("Bits = ");
Serial.print(bitValue);         
Serial.print("\t");
Serial.print("Voltage = ");
Serial.print(voltage);
Serial.println("V");
}
