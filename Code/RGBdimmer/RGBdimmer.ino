/*
* Code for making one potentiometer control 3 LEDs, red, grn and blu, or one tri-color LED
* The program cross-fades from red to grn, grn to blu, and blu to red
* Clay Shirky <clay.shirky@nyu.edu> 
* 
* Adapted for common anode RGB LEDs by Luke Woodbury 
* 11th March 2016
*/

// INPUT: Potentiometer should be connected to 5V and GND
int potPin = 0; // Potentiometer output connected to analog pin 0
int potVal = 0; // Variable to store the input from the potentiometer

// OUTPUT: Use digital pins 9-11, the Pulse-width Modulation (PWM) pins
// LED's cathodes should be connected to digital GND
int redPin = 6;   // Red LED,   connected to digital pin 9
int grnPin = 7;  // Green LED, connected to digital pin 10
int bluPin = 8;  // Blue LED,  connected to digital pin 11

// Program variables
int redVal = 0;   // Variables to store the values to send to the pins
int grnVal = 0;
int bluVal = 0;

void setup()
{
  pinMode(redPin, OUTPUT);   // sets the pins as output
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT);
}

// Main program
void loop()
{
  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    potVal = (potVal * 3) / 4; // Normalize to 0-255
    redVal = potVal;  // Red from full to off
    grnVal = 255 - potVal;        // Green from off to full
    bluVal = 255;             // Blue off
  }
   else if (potVal < 682) // Middle third of potentiometer's range (341-681)
  {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255

    redVal = 255;            // Red off
    grnVal = potVal; // Green from full to off
    bluVal = 255 - potVal;       // Blue from off to full
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    potVal = ( (potVal-683) * 3) / 4; // Normalize to 0-255

    redVal = 255 - potVal;       // Red from off to full
    grnVal = 255;            // Green off
    bluVal = potVal; // Blue from full to off
  }
  analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal); 
  
}

