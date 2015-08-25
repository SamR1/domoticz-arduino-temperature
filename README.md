# domoticz-arduino-temperature
Scripts to read temperature from Arduino (DS18B20 sensor), directly connected to Raspberry Pi via USB.  
The temperature is then displayed in Domoticz.  
The LCD display is optional.  
  
  
## **Hardware**  
- Raspberry pi  
- Arduino (I use an Arduino Mega)  
- DS18B20 temperature sensor  
- LCD Screen (optional)  

![Fritzing Sketch](https://raw.githubusercontent.com/SamR1/domoticz-arduino-temperature/master/images/sketch.png)
  
  
  
  
## **Arduino libraires**   
- for DS18B20 temp sensor  
-- OneWire.h  
-- DallasTemperature.h  
- and for LCD Screen (optional)  
-- LiquidCrystal.h  
  
  
  
  
## **Scripts** 
- **LCD_temperature.ino**  
  
Skecth for arduino that sends the temperature to Raspberry pi via serial.  
Tip : on linux, this error can appear during upload :  
```
avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied  
ioctl("TIOCMGET"): Inappropriate ioctl for device  
```
the fix is :  
```
$ sudo usermod -a -G dialout pi 
$ sudo chmod a+rw /dev/ttyACM0  
```
sources :   
http://www.getmicros.net/arduino-ds18b20-example.php  
http://arduino-er.blogspot.fr/2014/08/arduino-ide-error-avrdude-seropen-cant.html  
  
  
- **getArduinoTemp.py**  
  
This script save the received temperature in a file (*temperature.log*). It overwrites it.  
Place this script in */home/pi/domoticz/scripts/python*.  
To launch it at boot, add an crontab job for user pi :  
```
@reboot python /home/pi/domoticz/scripts/python/getArduinoTemp.py >> /home/pi/getArduinoTemp.log 2>&1  
```
  
  
- **script_time_temperature.lua**  
  
This script reads temperature from *temperature.log*.  
Place this script in */home/pi/domoticz/scripts/lua*.  
Domoticz executes it every minute.  
Prerequisites : create a dummy device on Domoticz, with a virtual sensor  
source : https://www.domoticz.com/forum/viewtopic.php?f=28&t=1475  
