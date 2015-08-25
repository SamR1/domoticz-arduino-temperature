#!/usr/bin/python
# -*- coding: utf-8 -*-

# this script works with LCD_temperature.ino

import serial
import os
import time

print('==> starting getArduinoTemp.py')

# file storing temperature
Filename = 'temperature.log'

serialArduino = serial.Serial('/dev/ttyACM0', 9600)

while 1:

	# verification if data are received from serial
	while (serialArduino.inWaiting()==0):
		pass	

	valueRead = serialArduino.readline()
	print(valueRead)

	try:
		# sometimes the first value is incorrect, eg '26.26.52'
		temp = float(valueRead)
	except Exception, e:
		print('ERROR : ', e)
	else:
		# sometimes the first value is incorrect, eg '2626.52'
		if temp < 100 :
			print('OK : writing to the log file')
			FileTemp = open(Filename,'w')
			FileTemp.write(valueRead)
			FileTemp.close()		
		else:
			print('ERROR : sent value incorrect')

	time.sleep(60)