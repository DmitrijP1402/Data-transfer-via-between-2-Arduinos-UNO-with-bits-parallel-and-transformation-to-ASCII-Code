# Data-transfer-between-2-Arduinos-UNO-by-bits-parallel-and-transformation-to-ASCII

There are two codes, one code is the sender where a letter, word or text (maximum 60 characters) can be entered into the serial monitor and then converted to binary characters and transmitted via cables 2-9 on the digital pins, the cable on digital pin 10 is used to transmit the start bit. In the receiver code, the received bits are then converted to a byte when the start bit is high and the byte is then output to the serial monitor as ASCII code previously sent from the other Arduino. The code was tested in Tinkercad with 2 Arduino Uno.

# Schematic from Tinkercad
![Funky Wolt](https://github.com/DmitrijP1402/Data-transfer-between-2-Arduinos-UNO-by-bits-parallel-and-transformation-to-ASCII/assets/118051854/35178c70-c07f-47f6-a6d9-ecb7ab1a039b)
