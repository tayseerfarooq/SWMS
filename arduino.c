
#include <SoftwareSerial.h>
 #include <LiquidCrystal_I2C.h>
 SoftwareSerial mySerial(9, 10);
//SoftwareSerial mySerial(9, 10);
 LiquidCrystal_I2C lcd(0x27, 16, 2);
//int ir2 =A6;
 int ir =A1;
 int ir1 =A2;
 int temp =A3;
 int sw =A0;
void setup()
{
randomSeed(analogRead(0));
mySerial.begin(9600); // Setting the baud rate of GSM Module
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
lcd.begin(16,2);
lcd.init();
  lcd.backlight();

lcd.print ("   SWMS   ");
lcd.setCursor(0,1);
lcd.print ("    SVCE    ");
delay(3000);
lcd.clear();
}
 
void loop()
{
 
if(digitalRead(temp)==HIGH)
{
void SendMessage();
Serial.print("DUST BIN FULL IN SVCE ");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\""); 
// Replace x with mobile number
delay(1000);
mySerial.println("**WARNING ** DUST BIN FULL IN SVCE ** ");
// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    SVCE    ");
lcd.setCursor(0,1);
lcd.print("SMS Sent");
delay(1000);
}
if(digitalRead(ir)==HIGH)
{
void SendMessage();
Serial.print("**WARNING ** DUST BIN FULL IN VIDYANAGAR **");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Replace x with mobile number
delay(1000);
mySerial.println("**WARNING ** DUST BIN FULL IN VIDYANAGAR ** ");
 // The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    SVCE    ");
lcd.setCursor(0,1);
lcd.print("SMS Sent");
delay(1000);
}
if(digitalRead(ir1)==1)
{
void SendMessage();
Serial.print("**WARNING ** DUST BIN FULL IN HUNASAMARANAHALLI ** ");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Replace x with mobile number
delay(1000);
mySerial.println("DUST BIN FULL IN HUNASAMARANAHALLI");
// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    SVCE    ");
lcd.setCursor(0,1);
lcd.print("SMS Sent");
delay(1000);
}

 if(digitalRead(sw)==1)
{
void SendMessage();
Serial.print("DUST BIN FULL IN BAGALUR ");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Replace x with mobile number
delay(1000);
mySerial.println("DUST BIN FULL IN BAGALUR");  // The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SVCE");
lcd.setCursor(0,1);
lcd.print("SMS Sent");
delay(1000);
}
else
{
Serial.print("    SWMS    ");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("    SVCE    ");
delay(1000);

}


}
