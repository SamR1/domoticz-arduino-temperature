commandArray = {}

local Num = "33" --Idx of the virtual device

print("starting temperature reading script")

file = io.open("/home/pi/temperature.log", "r")
io.input(file)
temp = io.read()
io.close(file)

temp2 = tostring(temp) .. " C"
print(temp2)

commandArray['UpdateDevice']=Num..'|0|'..temp2

print("end of temperature reading script")
return commandArray
