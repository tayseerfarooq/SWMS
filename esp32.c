#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

#include <DHT.h>
#define dhtpin 2
#define dhttype DHT11
DHT dht (dhtpin, dhttype);

#include "ThingSpeak.h" 
#include <WiFi.h>  
int valve=12; 

char ssid[] ="iPhone";   // your network SSID (name) 
char pass[] ="alpha123";   // your network password

int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = xxxxx;
const char * myWriteAPIKey ="XXXXXXXXXXXXX";
   
String myStatus = "";

//float t, h, val, volt, info, solar;
float t, h, val, b, info, d;
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  
  dht.begin();
  ThingSpeak.begin(client); 
  Serial.begin(115200); 
  pinMode(valve,OUTPUT);
  delay(100);
 }

void loop()
{
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);  
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
    t=dht.readTemperature();
    h=dht.readHumidity();

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\xC2\xB0");
    Serial.print("C");
    Serial.print("\t\t");
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println("%");
 
//if(mqtt.connected())

//int Gas_value = analogRead(34);
//Serial.println(Gas_value);
//Serial.print ("...") ;
//if (Gas_data.publish(Gas_value))

    val = analogRead(35);
     Serial.println(info);
    b = val*48.0/4096.0;
    Serial.print("bad smile: ");
    Serial.print(b);
    Serial.println("B");
 
    info = analogRead(34);
    Serial.println(info);
    d = info*48/4096.0;
    Serial.print("full: ");
    Serial.print(d);
    Serial.println("d");
    Serial.println();
    delay(500);

    lcd.setCursor(0,0);
    lcd.print("T: ");
    lcd.print(t);
    lcd.setCursor(9,0);
    lcd.print("H: ");
    lcd.print(h);

    lcd.setCursor(0,1);
    lcd.print("B: ");
    lcd.print(b);
    lcd.setCursor(9,1);
    lcd.print("D: ");
    lcd.print(d);
    if(t>31)
  {
   digitalWrite(valve,1);
  //   lcd.setCursor(0,1);
  //lcd.print("valve on");
 // lcd.print("     ");
  }

  
  if(t<31)
  {
    digitalWrite(valve,0);
  //   lcd.setCursor(0,1);
  //lcd.print("valve off");
  //  lcd.print("      ");
  }
  
    ThingSpeak.setField(1, t);
    ThingSpeak.setField(2, h);
    ThingSpeak.setField(3, b);
    ThingSpeak.setField(4, d);

    // write to the ThingSpeak channel
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if(x == 200)
    {
      Serial.println("Channel update successful.");
      Serial.println();
    }
    else
    {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
      Serial.println();
    }
  
    // change the values
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    delay(15000); // Wait 15 seconds to update the channel again
}
