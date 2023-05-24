/********************************************
date:      "24.05.2023"
author:    "DmitrijP1402"
filename:  "Receiver.ino"
********************************************/

void setup() {
  Serial.begin(9600);
  
  pinMode (2, INPUT);
  pinMode (3, INPUT);
  pinMode (4, INPUT);
  pinMode (5, INPUT);
  pinMode (6, INPUT);
  pinMode (7, INPUT);
  pinMode (8, INPUT);
  pinMode (9, INPUT);
  pinMode (10, INPUT);
}

void loop() {
  byte startbit = digitalRead(10); 

  if (startbit == 1) {
    byte receivedByte = 0;

    receivedByte |= digitalRead(9);
    receivedByte |= digitalRead(8) << 1;
    receivedByte |= digitalRead(7) << 2;
    receivedByte |= digitalRead(6) << 3;
    receivedByte |= digitalRead(5) << 4;
    receivedByte |= digitalRead(4) << 5;
    receivedByte |= digitalRead(3) << 6;
    receivedByte |= digitalRead(2) << 7;

    char receivedChar = (char)receivedByte;

    Serial.print(receivedChar);
    delay(1000);
  } 
}
