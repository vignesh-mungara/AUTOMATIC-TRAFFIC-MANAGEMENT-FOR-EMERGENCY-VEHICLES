#include <RCSwitch.h>

RCSwitch receiver;

// Define pins for the traffic lights at each junction
const int northRedPin = 3;
const int northGreenPin = 4;
const int eastRedPin = 5;
const int eastGreenPin = 6;
const int southRedPin = 7;
const int southGreenPin = 8;
const int westRedPin = 9;
const int westGreenPin = 10;

RCSwitch mySwitch = RCSwitch();
int lastSignal = 0;  // To store the last received signal direction

void setup() {

  // Initialize the traffic light pins as outputs
  pinMode(northRedPin, OUTPUT);
  pinMode(northGreenPin, OUTPUT);
  pinMode(eastRedPin, OUTPUT);
  pinMode(eastGreenPin, OUTPUT);
  pinMode(southRedPin, OUTPUT);
  pinMode(southGreenPin, OUTPUT);
  pinMode(westRedPin, OUTPUT);
  pinMode(westGreenPin, OUTPUT);

  // Initialize the RF receiver
  receiver.enableReceive(0);  // Receiver on interrupt 0 (pin 2)
}

void loop() {
  if (receiver.available()) {
    unsigned long receivedValue = receiver.getReceivedValue();
    if (receivedValue != 0) {
      // Print the received signal value
      Serial.print("Received signal: ");
      Serial.println(receivedValue);

      // Check if the received signal matches any of the expected values
      if (receivedValue == 4071 || receivedValue == 4075 || receivedValue == 4077 || receivedValue == 4078 || receivedValue == 4079) {
        adjustTrafficLights(receivedValue);
        lastSignal = receivedValue;
      }
    }
    receiver.resetAvailable();
  }
}

void adjustTrafficLights(unsigned long signal) {
  // Turn off all lights initially
  digitalWrite(northRedPin, LOW);
  digitalWrite(northGreenPin, LOW);
  digitalWrite(eastRedPin, LOW);
  digitalWrite(eastGreenPin, LOW);
  digitalWrite(southRedPin, LOW);
  digitalWrite(southGreenPin, LOW);
  digitalWrite(westRedPin, LOW);
  digitalWrite(westGreenPin, LOW);

  // Implement logic to adjust traffic lights based on received values
  // For example, you can use a switch-case statement to determine the action
  // based on the received value.
  switch (signal) {
    
      case 4079: // Your regular traffic light control logic here for normal operation
     // For example, a simple 4-way traffic light cycle
    digitalWrite(northRedPin, HIGH);
     digitalWrite(northGreenPin, LOW);
     digitalWrite(southRedPin, HIGH);
     digitalWrite(southGreenPin, LOW);
     digitalWrite(eastRedPin, LOW);
     digitalWrite(eastGreenPin, HIGH);
     digitalWrite(westRedPin, LOW);
     digitalWrite(westGreenPin, HIGH);
     delay(2000);   
     digitalWrite(eastRedPin, HIGH);
     digitalWrite(eastGreenPin, LOW);
     digitalWrite(westRedPin, HIGH);
     digitalWrite(westGreenPin, LOW);
     digitalWrite(northRedPin, LOW);
     digitalWrite(northGreenPin, HIGH);
     digitalWrite(southRedPin, LOW);
     digitalWrite(southGreenPin, HIGH);
     delay(2000);
     break;   
    case 4071:  // Code for North direction      // Adjust traffic lights for North direction
      digitalWrite(northRedPin, LOW);
      digitalWrite(northGreenPin, HIGH);
      digitalWrite(eastRedPin, HIGH);
      digitalWrite(eastGreenPin, LOW);
      digitalWrite(southRedPin, HIGH);
      digitalWrite(southGreenPin, LOW);
      digitalWrite(westRedPin, HIGH);
      digitalWrite(westGreenPin, LOW);
      delay(4000);
      break;    
    case 4075:  // Code for East direction
      // Adjust traffic lights for East direction
      digitalWrite(eastRedPin, LOW);
      digitalWrite(eastGreenPin, HIGH);
      digitalWrite(northRedPin, HIGH);
      digitalWrite(northGreenPin, LOW);
      digitalWrite(southRedPin, HIGH);
      digitalWrite(southGreenPin, LOW);
      digitalWrite(westRedPin, HIGH);
      digitalWrite(westGreenPin, LOW);
     delay(4000);
      break;

    case 4077:  // Code for South direction
      // Adjust traffic lights for South direction
      digitalWrite(southRedPin, LOW);
      digitalWrite(southGreenPin, HIGH);
      digitalWrite(northRedPin, HIGH);
      digitalWrite(northGreenPin, LOW);
      digitalWrite(eastRedPin, HIGH);
      digitalWrite(eastGreenPin, LOW);
      digitalWrite(westRedPin, HIGH);
      digitalWrite(westGreenPin, LOW);
      delay(4000);

      break;

    case 4078:  // Code for West direction
      // Adjust traffic lights for West direction
      digitalWrite(westRedPin, LOW);
      digitalWrite(westGreenPin, HIGH);
      digitalWrite(northRedPin, HIGH);
      digitalWrite(northGreenPin, LOW);
      digitalWrite(eastRedPin, HIGH);
      digitalWrite(eastGreenPin, LOW);
      digitalWrite(southRedPin, HIGH);
      digitalWrite(southGreenPin, LOW);
      delay(4000);
      break;
  
     
    
    
   

     

     
     
    default:
      // Handle unknown values or no action needed
      // Turn off all lights
      digitalWrite(northRedPin, LOW);
      digitalWrite(northGreenPin, LOW);
      digitalWrite(eastRedPin, LOW);
      digitalWrite(eastGreenPin, LOW);
      digitalWrite(southRedPin, LOW);
      digitalWrite(southGreenPin, LOW);
      digitalWrite(westRedPin, LOW);
      digitalWrite(westGreenPin, LOW);
      break;
  }
}

