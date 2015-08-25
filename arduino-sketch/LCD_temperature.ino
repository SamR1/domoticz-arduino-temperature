// Librairies for LCD Screen
#include <LiquidCrystal.h> 

// and for DS18B20 sensor
#include <OneWire.h>
#include <DallasTemperature.h>


// LCD Screen connected to pins 2, 3, 4, 5, 10 and 11
LiquidCrystal lcd(11,10,5,4,3,2);

// Sensor connected to pin 7
#define DS18B20 7
OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);

void setup()
{
   lcd.begin(16,2); // 16 characters by 2 line display
   lcd.write("Init de l'ecran");

   delay(5000); 
   // start reading
   sensors.begin();

   // USB connection init
   Serial.begin(9600);
}
 
void loop() {
  
   lcd.clear();  // places the cursor in the top left
   delay(10);    
   
   // read temperature and output via serial
   sensors.requestTemperatures();
   Serial.print(sensors.getTempCByIndex(0));
   Serial.println("");
   
   // display on LCD screen
   lcd.write("La temp. est de ");
   lcd.setCursor(0, 1);
   lcd.print(sensors.getTempCByIndex(0));
   lcd.setCursor(5, 1);
   lcd.print(" degres C");
  
   // reading every 10 minutes
   delay(60000);

}
