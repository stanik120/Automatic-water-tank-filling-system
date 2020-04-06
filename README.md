# Automatic water tank filling system
I live in Gambia, the smallest African country.  And we have a little problem with water here, namely water from the city is only at night and at different times and when the water appears someone had to switch on the pump that will fill the tank on the roof of our house.  It was quite bothersome, hence my idea appeared to automate the whole process.
For this purpose, I used arduino nano, a relay, two liquid level sensor, a flow sensor, a programmable timer with time support. Behind the relay I also used a contactor to which I just connected the pump and not to the relay itself so that the relay does not work under heavy load and can work longer.

### Used parts:
* Arduino nano
* Liquid flow sensor YF-S201 30l/m
* Relay module 1 channel - 10A / 250VAC contacts - 5V coil*
* Liquid level sensor CMW55 - magnetic x 2
* 230v contactor
* multi-functional programmable electronic timer (to make the system work only at night)

### Connection diagram
* Relay module - **D13**
* Upper liquid level sensor - **D4**
* Bttom liquid level sensor - **D3**
* Flow sensor - **D2**
![Connection diagram](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/850fd99f-0562-4f27-b359-a58d1b2b81e3/Projekt.png)

### Program code for arduino
[filling-system.ino](https://github.com/stanik120/Automatic-water-tank-filling-system/blob/master/filling-system.ino)

### This is how it looks
![Tank](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/a3a79fa9-b262-4321-9e8a-dbca006d90e1/1586182276588.jpg)
![Inside](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/8ffa80e9-89d1-4870-b099-5895e4a89e0c/20200406_140104.jpg)
![Flow sensor](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/643deaec-c574-4f55-a8a5-c1504a15085f/20200406_140258.jpg)
### Version 1.1
![Version 1.1](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/4f5e33a5-397c-493e-8f80-4a1d991e4dbb/20200406_115626.jpg)
### Version 1.0
![Version 1.0](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/ae60dc1e-e17f-42a8-88d0-188162127816/1579833065635.jpg)
### The first prototype
![Prototyp](https://content.evernote.com/shard/s385/sh/c911d4f7-1466-4aef-b563-31e97de32083/8895f940a1ed3e16fccee87b8fa9ea96/res/01a2388f-2db1-42de-acb5-7c51f5b14108/1570472964516.jpg)

### Contact
If anyone would be interested in buying a ready-made solution and assembly, please contact me. I can use Signal and WhatsApp.
* Phone number: +220 741 31 78
* E-mail: [stanik@tuta.io](mailto:stanik@tuta.io)

### License
This project is licensed under the CC BY-NC 4.0 - see the [LICENSE.md](LICENSE.md) file for details.
