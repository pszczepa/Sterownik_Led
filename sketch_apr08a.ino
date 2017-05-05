#include "pasek.h"
#include "kolor.h"
#include "wejscia.h"
#include "kolory.h"


  Pasek p1;
  Wejscia w1;
  int indeks;


void setup() 
{
  w1.InitSetup();
  p1.InitSetup();
  
  pinMode(13, OUTPUT);

  Serial.begin(9600);

  p1.PiszNaPasek(255,0,0);

}
   


void loop() 
{
  
  if(digitalRead(7))
    {
      p1.PiszNaPasek(str1[indeks]);
    }
  else
    {
      p1.PiszNaPasek(str2[indeks]);
    }
  

}




