#include "kolor.h"
#include "kolory.h"
#include "pasek.h"
#include "wejscia.h"


  Pasek p1;
  Wejscia w1(2,6);

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
      w1.Sprawdz(3,p1);
     
     if(!p1.Stan())
     {
      p1.PiszNaPasek(zero);
     }       
     else
     {
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
              p1.Fade();
              break;
            }
      }   
     }   
    }
    else                                //Odłączony kontroler
    {
      w1.Sprawdz(1,p1);
      w1.Sprawdz(2,p1);


      if(digitalRead(7))
      { 

        if(!p1.Stan())
        {
          p1.PiszNaPasek(zero);
        }
        else      
        {
          p1.PiszNaPasek(str[w1.TrybW()]);
        }

      }
      else
      {
        if(!p1.Stan())
        {
          p1.PiszNaPasek(zero);
        }
        else      
        {
          p1.Fade();
        }
      }

    }
    
  }

  






