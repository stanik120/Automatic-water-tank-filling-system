#include <EEPROM.h>                     //obsluga pamieci EPROM

unsigned char przekaznik = 13;          //przekaznik pompy
unsigned char czujnikg = 4;             //czujnik gorny (brazowy)
unsigned char czujnikd = 3;             //czujnik dolny (zulto zielony)
unsigned char flowsensor = 2;           //przepływomierz

bool napelnianie = EEPROM.read(0);      //zczytanie stanu zbiornika z pamieci EEPROM

volatile int flow_frequency;            // Measures flow sensor pulses
void flow ()                            // Interrupt function
{
   flow_frequency++;
}

void setup() {
  pinMode(przekaznik, OUTPUT);          //wyjscie na przekaznik pompy
  pinMode(czujnikg, INPUT);             //wejscie z gornego czujnika
  pinMode(czujnikd, INPUT);             //wejscie z dolnego czujnika

  digitalWrite(przekaznik, HIGH);       //wylacza przekaznik

  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);       // Optional Internal Pull-Up
  attachInterrupt(0, flow, RISING);     // Setup Interrupt
  sei(); // Enable interrupts
}
void loop() {
    if(digitalRead(czujnikg) == 0)      //jezeli woda dojdzie do gornego czujnika ustaw napelnianie na false
    {
      napelnianie = false;
    }
    if(digitalRead(czujnikd) == 1)      //jezeli woda spadnie ponizej dolnego czujnika ustaw napelnianie na true
    {
      napelnianie = true;
    }
    EEPROM.update(0, napelnianie);      //zapis stanu zbiornika do pamieci EEPROM
    if(napelnianie == false)            //jezeli napelnianie jest false przekaznik pompy zostaje wylaczony oraz program robi przerwe na godzine i ponownie sprawdzi stan czujnikow
    {
      digitalWrite(przekaznik, HIGH);
      delay(3600000);                   //przerwa na godzine
    }
    if(napelnianie == true)             //jezeli napelnianie jest true wlacz pompe i sprawdz czy plynie woda
    {
      digitalWrite(przekaznik, LOW);
      flow_frequency = 0;               //wyzeruj licznik przeplywu
      delay(10000);                     //poczekaj 10 sekund (sprawdza przeplyw co 10 sekund)
      if (flow_frequency < 10)          //jezeli woda nie plynie wylacz przekaznik pompy oraz zrob przerwe na godzine i ponownie sprawdz czy plynie woda
      {
        digitalWrite(przekaznik, HIGH);
        delay(3600000);                 //przerwa na godzine
      }
      flow_frequency = 0;               //wyzeruj licznik przeplywu
    }
    
}
