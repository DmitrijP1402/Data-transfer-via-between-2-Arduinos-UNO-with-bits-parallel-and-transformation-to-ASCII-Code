/********************************************
date:      "24.05.2023"
author:    "DmitrijP1402"
filename:  "Transmitter.ino"
********************************************/

// max. 60 characters possible --> 480 bits

void setup() {
  Serial.begin(9600); // Start the Serial Monitor

  pinMode(2, OUTPUT); // Set digital pins 2-10 as OUTPUT
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

byte startbit = 0; // State of the start bit
int count = 0;

void loop() {
  if (Serial.available()) {
    char text = Serial.read(); // Read input text and store it in 'text'
    delay(10);
    count = count + 1;
    startbit = 1;

    if (startbit == 1 && count == 2) { // Send start bit
      digitalWrite(10, HIGH);
      startbit = 0;
      delay(10);
    }

    bool bit0 = bitRead(text, 7); // Convert ASCII to bits
    bool bit1 = bitRead(text, 6);
    bool bit2 = bitRead(text, 5);
    bool bit3 = bitRead(text, 4);
    bool bit4 = bitRead(text, 3);
    bool bit5 = bitRead(text, 2);
    bool bit6 = bitRead(text, 1);
    bool bit7 = bitRead(text, 0);

    digitalWrite(2, bit0); // Transmit bits through pins 2-9
    digitalWrite(3, bit1);
    digitalWrite(4, bit2);
    digitalWrite(5, bit3);
    digitalWrite(6, bit4);
    digitalWrite(7, bit5);
    digitalWrite(8, bit6);
    digitalWrite(9, bit7);

    delay(90);

    Serial.println(""); // Output bits and ASCII on the Serial Monitor
    Serial.print(text);
    Serial.print(" --> ");
    Serial.print(bit0);
    Serial.print(bit1);
    Serial.print(bit2);
    Serial.print(bit3);
    Serial.print(bit4);
    Serial.print(bit5);
    Serial.print(bit6);
    Serial.print(bit7);
  } else {
    startbit = 0;
    count = 0;
    digitalWrite(10, LOW); // Don't send start bit
  }
}
