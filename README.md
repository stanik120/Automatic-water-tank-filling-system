# Automatic water tank filling system
I live in Gambia, the smallest African country.  And we have a little problem with water here, namely water from the city is only at night and at different times and when the water appears someone had to switch on the pump that will fill the tank on the roof of our house.  It was quite bothersome, hence my idea appeared to automate the whole process.
For this purpose, I used arduino nano, a relay, two liquid level sensor, a flow sensor, a programmable timer with time support. Behind the relay I also used a contactor to which I just connected the pump and not to the relay itself so that the relay does not work under heavy load and can work longer.

### Used parts:
* Arduino nano or other version
* Liquid flow sensor YF-S201 30l/m
* Relay module 1 channel - 10A / 250VAC contacts - 5V coil*
* Liquid level sensor CMW55 - magnetic x 2
* 230v contactor
* multi-functional programmable electronic timer (to make the system work only at night)

### Connection diagram
![Connection diagram](http://url/to/img.png)

### Program code for arduino
[filling-system.ino](https://github.com/stanik120/Automatic-water-tank-filling-system/blob/master/filling-system.ino)

### This is how it looks

### Version 1.1
![Version 1.1](http://url/to/img.png)

### Version 1.0
![Version 1.0](http://url/to/img.png)

### The first prototype
![Prototyp](http://url/to/img.png)
