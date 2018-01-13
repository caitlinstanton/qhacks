//  Student Accelerator Hackathon - 2018
//  HC-05 Basic program to send value (0 or 1) triggered by a button   
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(9,10); // Arduino RX 9 - BT TX 9  | Arduino TX 10 - BT RX 10 

//button to pin 3
int button = 3; 

void setup() 
{  
    //Serial monitor (top right icon) set to 9600 baud rate
    Serial.begin(9600);
    Serial.println("Arduino Serial Begin");

    //HC-05 communication set at 9600 baud rate
    BTserial.begin(9600);  
    Serial.println("Bluetooth Serial Begin");

    //pin 3 is set to input information from button 
    pinMode(button, INPUT); 
}
 
void loop()
{
 //read value from button(pin 3) and send via Bluetooth 
 BTserial.print(digitalRead(button)); 
 
 //read value from button(pin 3) and send to serial monitor 
 Serial.println(digitalRead(button));

 //delay 50milliseconds 
 delay(50);  
}

