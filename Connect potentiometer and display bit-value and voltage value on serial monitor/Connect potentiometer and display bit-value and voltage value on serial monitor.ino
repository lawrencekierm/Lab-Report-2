/*Connect potentiometer and display bit-value and voltage value on serial monitor
 This program uses potentiometer to adjust the bit value from one of the
 analog inputs. This bit value must be converted to votlage equivalent 
 (1023 = 5V). Both bit and votlage value must be displayed on the serial
 monitor.
*/
void setup() {
  Serial.begin(9600); // Serial communication at 9600 bits per second
}

// the loop routine continuously
void loop() {
  int bitValue = analogRead(A0);      // This reads the bit value on analog pin 0 (A0)
  float slope =5.0/1023.0;            // This is the formula to find slope (bit to voltage)
  float voltage = (bitValue*slope);   // This is the formula to convert bit value to voltage

// Print both bit value and voltage on Serial Monitor in an order way
Serial.print("Bits = ");
Serial.print(bitValue);         
Serial.print("\t");
Serial.print("Voltage = ");
Serial.print(voltage);
Serial.println("V");
}