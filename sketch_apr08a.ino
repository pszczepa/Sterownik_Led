#include "kolor.h"
#include "kolory.h"
#include "pasek.h"
#include "wejscia.h"


  Pasek p1;
  Wejscia w1;

void setup() 
{
  w1.InitSetup();
  p1.InitSetup();
  
  pinMode(13, OUTPUT);

  Serial.begin(9600);

  p1.PiszNaPasek(20,20,20);

}
   
void loop() 
{
  


  if(!p1.Stan())
  {
    w1.Sprawdz(4,p1);
    p1.PiszNaPasek(zero);
  }
  else
  {
    if(analogRead(A0) < 500)            //Podałączono zewnętrzyn kontroler
    {
      p1.PiszNaPasek(red);
      switch(w1.TrybZ())
        {

        }
      
    }
    else                                //Odłączony kontroler
    {
      w1.Sprawdz(1,p1);
      p1.PiszNaPasek(green);
      switch(w1.TrybW())
        {

        }
    }
  }


}



