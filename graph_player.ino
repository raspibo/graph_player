#include <CapacitiveSensor.h>

/*
 * Simple example of interaction between Teens 3.1 and graphene film used as capacitive touch sensor
 * set uotput as serial+keyboard+mouse+joystick
 * Based on CapacitiveSensor library: http://playground.arduino.cc/Main/CapacitiveSensor
 * Set the correct number of samples to measure time
 */


CapacitiveSensor   Play_Pause = CapacitiveSensor(20,15);        
CapacitiveSensor   Inc_Volume = CapacitiveSensor(20,16);        
CapacitiveSensor   Dec_Volume = CapacitiveSensor(20,17);        

void setup()                    
{
      Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long time1 =  Play_Pause.capacitiveSensor(200);     //Tune with correct values
    long time2 =  Inc_Volume.capacitiveSensor(200);     //Tune with correct values
    long time3 =  Dec_Volume.capacitiveSensor(200);     //Tune with correct values



    Serial.print((millis() - start)/10);        
    Serial.print("\t");                    
    Serial.print(time1);                  
    Serial.print("\t");                   
    Serial.print(time2);                  
    Serial.print("\t");
    Serial.print(time3); 
    Serial.print("\t");
    if (time1>3500) {                                   //Change to detect best values
     Serial.print("p1"); 
     Keyboard.set_media(KEY_MEDIA_PLAY_PAUSE);
     Keyboard.send_now();
     Keyboard.set_media(0);
     Keyboard.send_now();
    } 
    Serial.print("\t");
    if (time2>3500) {                                   //Change to detect best values
     Serial.print("p2");
     Keyboard.set_media(KEY_MEDIA_VOLUME_DEC);
     Keyboard.send_now();
     Keyboard.set_media(0);
     Keyboard.send_now();
    } 
    Serial.print("\t");
    if (time3>10000) {                                 //Change to detect best values
     Serial.print("p3");
     Keyboard.set_media(KEY_MEDIA_VOLUME_INC);
     Keyboard.send_now();
     Keyboard.set_media(0);
     Keyboard.send_now();
    } 
    Serial.println("");
    delay(100);                             
}
