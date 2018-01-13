//  Student Accelerator Hackathon - 2018
//  HC-06 Basic program to receive value (0 or 1) to turn an LED on/off 
 
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(9,10); // Arduino RX 9 - BT TX 10 | Arduino TX 10 - BT RX 9

//LED to pin 3
int LED = 3; 

//BTValue stores value read from Bluetooth
int BTValue = 0; 

void setup()  
{
    //Serial monitor (top right icon) set to 9600 baud rate  
    Serial.begin(9600);
    Serial.println("Arduino Serial Begin");
 
    // HC-06 default baud rate is 9600
    BTSerial.begin(9600);  
    Serial.println("Bluetooth Serial Begin");

    // pin 3 is set to output information to LED 
    pinMode(LED, OUTPUT); 
}
 
void loop()
{
 
// check HC-06, read HC-06, trigger LED, and send to Arduino Serial Monitor
if (BTSerial.available()){
  
  //Read from HC-06 and store in BTValue
  BTValue = BTSerial.read();// values received as characters, use ASCII Table
    //Compare BTValue with ASCII of '0' ('0' => 48)
    if (BTValue == 48){
      //turn LED (pin 3) on
      digitalWrite(LED,LOW);
     //Compare BTValue with ASCII of '1' ('1' => 49) 
    }else if (BTValue == 49){
      //turn LED (pin 3) off
      digitalWrite(LED,HIGH);
    }
 //print BTValue to Arduino Serial Monitor (top right icon)
 Serial.print("Value: ");
 Serial.println(BTValue);
 
}
}
