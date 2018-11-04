
#include <SoftwareSerial.h>
SoftwareSerial NodeMcu(4,5);
#include<Adafruit_Fingerprint.h>
#include<Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;
char patientno=0;

long paracetamol=1000;
long cetrizine=1000;
long no_cold=1000;
int Buzzer=13;
int led1=7;
int led2= 8;
int getFingerprintID() {
  

  uint8_t p = finger.getImage();
  if (p = FINGERPRINT_OK) {};

  p = finger.image2Tz();
  if (p = FINGERPRINT_OK)  {};

  p = finger.fingerFastSearch();
  if (p = FINGERPRINT_OK) {};
  
  // found a match!
  //Serial.print("Found ID #"); Serial.print(finger.fingerID); 
 // Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
 void setup() {                                                             
  // put your setup code here, to run once:
 Serial.begin(9600);
 NodeMcu.begin(4800);
 finger.begin(57600);
 
  if (finger.verifyPassword()) {
    //Serial.println("Found fingerprint sensor!");
  } else {
    //Serial.println("Did not find fingerprint sensor :("); 
     //while (1) { delay(1); }
     }
  
  ser1.attach(9);
  ser2.attach(10);
  ser3.attach(12);
  ser1.write(0);
  ser2.write(0);
  ser3.write(0);
 
}
 void loop() {
    while(!Serial.available());
  while (Serial.available()>0)
  {
     patientno=Serial.read();
     delay(1000);
     if (patientno=='1')
     {
      fingerprintID = getFingerprintID();
      delay(500);
      fingerprintID=getFingerprintID();
      if(fingerprintID==1){
       medicine(1);
      Serial.write("T");
      }
      else
      {Serial.write("F");}
     }
     if (patientno=='2')
     {
      fingerprintID = getFingerprintID();
       delay(500);
      fingerprintID=getFingerprintID();
      if(fingerprintID==2){
      Serial.write("T");
       medicine(2);
      }
      else
      Serial.write("F");
     }
     if (patientno=='3')
     {
      fingerprintID = getFingerprintID();
       delay(500);
      fingerprintID=getFingerprintID();
      if(fingerprintID=="3"){
      Serial.write("T");
      medicine(3);
      }
      else
      Serial.write("F");
     }
  }
    patientno=0;
  delay(200);
  // while(!NodeMcu.available()){}
    NodeMcu.print(paracetamol);
   
   NodeMcu.println("\n");
    delay(17);
  if(paracetamol<=10)
     digitalWrite(Buzzer,HIGH);
  else
     digitalWrite(Buzzer,LOW);
   
   //while(!NodeMcu.available()){}
    NodeMcu.print(cetrizine);
   NodeMcu.println("\n");
  if(cetrizine<=10)
     digitalWrite(led1,HIGH);
  else
     digitalWrite(led1,LOW);
   
   delay(17);
 //  while(!NodeMcu.available()){}
   NodeMcu.print(no_cold);
   NodeMcu.println("\n");
   if(no_cold<=10)
     digitalWrite(led2,HIGH);
  else
     digitalWrite(led2,LOW);
   
   delay(17);
    delay(1300);
 }
 void medicine(int number)
{
  if (number==1)
  {
    ser1.write(90);
    delay(500);
    ser1.write(0);
    ser2.write(90);
    delay(500);
    ser2.write(0);
    paracetamol=paracetamol-2;
    cetrizine=cetrizine-2;
  }
  else if (number==2)
  {
    ser1.write(90);
    delay(500);
    ser1.write(0);
    ser2.write(90);
    delay(500);
    ser2.write(0);
    paracetamol=paracetamol-2;
    no_cold=no_cold-2;
  }
  else if(number==3)
  {
    ser2.write(90);
    delay(500);
    ser2.write(0);
    no_cold=no_cold-3;
  }
}
