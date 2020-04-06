#include <EEPROM.h>						//EPROM support

unsigned char relay = 13;				//pump activation relay
unsigned char up_sensor = 4;			//upper sensor located in the tank
unsigned char bot_sensor = 3;			//bottom sensor located in the tank
unsigned char flowsensor = 2;			//flow sensor located before the pump

bool position = EEPROM.read(0);			//reading the tank status from the EEPROM memory

volatile int flow_frequency;			// Measures flow sensor pulses
void flow ()							// Interrupt function
{
   flow_frequency++;
}

void setup() {
  pinMode(relay, OUTPUT);				//output on pump relay
  pinMode(up_sensor, INPUT);			//input from the upper sensor
  pinMode(bot_sensor, INPUT);			//input from the bottom sensor

  digitalWrite(relay, HIGH);			//Turn off pump relay

  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);		// Optional Internal Pull-Up
  attachInterrupt(0, flow, RISING);		// Setup Interrupt
  sei(); 								// Enable interrupts
}

void loop() {
    if(digitalRead(up_sensor) == 0)		//if the water rises to the upper sensor, set position to false
    {
      position = false;
    }
    if(digitalRead(bot_sensor) == 1)	//if the water drops below the bottom sensor, set position to false
    {
      position = true;
    }
    EEPROM.update(0, position);			//save tank status to EEPROM
	
	if(position == false)				//if the position is false, the pump relay is turned off and the program pauses for an hour and re-checks the sensor status
    {
      digitalWrite(relay, HIGH);
      delay(3600000);					//one hour break
    }
    if(position == true)				//if position is true turn on the pump and check if water flows
    {
      digitalWrite(relay, LOW);
      flow_frequency = 0;				//reset the flow meter
      delay(10000);						//wait 10 seconds (checks flow every 10 seconds)
      if (flow_frequency < 10)			//if the water does not flow, turn off the pump relay and take an hour break and check if water flows again
      {
        digitalWrite(relay, HIGH);
        delay(3600000);					//one hour break
      }
      flow_frequency = 0;				//reset the flow meter
    }
}
