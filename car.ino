#include <IRremote.hpp>

// Remote pin
const int remotePin = 8;

// Motor pins
const int in1 = 3;
const int in2 = 5;
const int in3 = 6;
const int in4 = 9;
const int enA = 10;
const int enB = 11;

int speed = 100;

// LED pins 
const int ledPin1 = 12;
const int ledPin2 = 7;
const int ledPin3 = 4;
const int ledPin4 = 2;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(remotePin, ENABLE_LED_FEEDBACK); // Initialize the IR receiver

  // Setting the motor pins to output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Setting the LED pins to output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void goLeft(){
    // Insert code to move car to the left
}

void goRight(){
    // Insert code to move car to the right
}

void goForward(){
    // Insert code to move car forward
}

void goBackward(){
    // Insert code to move car backward
}

void stop(){
    // Insert code to stop the car
}

void changeLEDS(){
    // Insert code to change the tail/head lights
}

void loop() {
  if(IrReceiver.decode()){
    Serial.print("Received: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch(IrReceiver.decodedIRData.command){
      case 0x44:    // Left button pressed 0xBB44FF00
        goLeft();
        break;
      case 0x43:    // Right button pressed 0xBC43FF00
        goRight();
        break;
      case 0x9:    // Forawrds button pressed 0xF609FF00
        goForward();
        break;
      case 0x7:    // Backwards button pressed 0xF807FF00
        goBackward();
        break;
      case 0x40:    // Stop button pressed 0xBF40FF00
        stop();
        break;
    }

    IrReceiver.resume();  // Enabling the IR receiver to listen again
  }
}