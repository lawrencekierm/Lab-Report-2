/*PB value displayed on serial monitor and blink (without using Delay) 
This program will blink one of the 2 LEDs continuously without using
delay function. So, the other code can run at the same time without 
being interrupted by the LED code. While this LED blinks, the other 
LED keeps ON unless button is pressed; internal pull-up resistor is used. 
Also, the value ofpush button must show on the Serial monitor: 1 when 
unpressed and 0 when pressed.
*/

const int ledPin = 4;     // Assign ledPin to 4 as integer
const int ledPin2 = 5;    // Assign ledPin2 to 5 as integer
const int buttonPin = 2;  // Assign buttonPin to 2 as integer
int buttonState = 0;      // buttonState used to set the button
int ledState = LOW;       // ledState used to set the LED

// "unsigned long" is used to hold time as the value becomes too large for "int"
unsigned long previousMillis = 0;  // This stores last time LED was updated

// To keep certain value, "const long" will keep it constant
const long interval = 1000;  // This is the interval at which to blink in milliseconds

void setup() {
  Serial.begin(9600);                 //serial communication at 9600 bits per second
  pinMode(ledPin, OUTPUT);            // Assign ledPin as an OUTPUT
  pinMode(ledPin2, OUTPUT);           // Assign ledPin2 as an OUTPUT
  pinMode(buttonPin, INPUT_PULLUP);   // Assign buttonPin an an INPUT_PULLUP or internal pull up
}

void loop() {        // Code here will run all the time

  unsigned long currentMillis = millis();

/* Determine whether it's necessary to activate the LED blinking function
 by comparing the time elapsed since the last LED blink with the desired interval 
 for LED blinking. If the elapsed time is greater than the specified interval, 
 then it's time to blink the LED again.
*/
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);  // Set the LED with the ledState of the variable
  }

buttonState = digitalRead(buttonPin); // Read the buttonPin value and store it to buttonState

if (buttonState == HIGH) {            // If button is HIGH or unpressed     
    digitalWrite(ledPin2, HIGH);      // turn LED ON
  } else {                            // If button is pressed 
    digitalWrite(ledPin2, LOW);       // turn LED OFF
  }
Serial.print("PB value = ");          // Print "PB Value =" on serial monitor
Serial.println(buttonState);          //Then the value from buttonState
}
