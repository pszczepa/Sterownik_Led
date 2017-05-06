#include "kolor.h"
#include "kolory.h"
#include "pasek.h"
#include "wejscia.h"


  Pasek p1;
  Wejscia w1(4,6);

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


    if(analogRead(A0) < 500)            //Podałączono zewnętrzyn kontroler
    {
      w1.Sprawdz(4,p1);
      //Serial.println(w1.TrybZ());
      
      switch(w1.TrybZ())
      {
          case 0 :
            {
              p1.Potencjometry();
              break;
            }
          case 1 :
            {
              p1.PotencjometryMatrix();
              break;
            }
          case 2 :
            {
              p1.PiszNaPasek(zero);
              break;
            }
          case 3 : 
            {
              p1.PiszNaPasek(green);
              break;
            }
      }      
    }
    else                                //Odłączony kontroler
    {
      w1.Sprawdz(1,p1);

      if(digitalRead(7))
      {
        p1.PiszNaPasek(strOliwia[w1.TrybW()]);
      }
      else
      {
        p1.PiszNaPasek(str1[w1.TrybW()]);
      }

    }
    
  }

  






