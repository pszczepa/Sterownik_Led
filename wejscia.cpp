#include "wejscia.h"



  Wejscia::Wejscia()
  {
    _przyciski[0] = 7;
    _przyciski[1] = 6;
    _przyciski[2] = 5;
  }

  Wejscia::Wejscia(int p1, int p2, int p3, int p4, int p5)
   {}

  void Wejscia::InitSetup()
  {
      pinMode(_przyciski[0], INPUT);
      pinMode(_przyciski[1], INPUT);
      pinMode(_przyciski[2], INPUT);
  }

  void Wejscia::CzytajNaSerial()
  {
    Serial.println(digitalRead(_przyciski[0])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[1])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[2])); Serial.print(" ");
  }

  void Wejscia::Sprawdz(int nr_przycisku)
  {
    if (!digitalRead(_przyciski[nr_przycisku]))
    {
      ++_liczniki[nr_przycisku];
     }

    if(_liczniki[nr_przycisku] > 100)
    {
      Wykryto(nr_przycisku);
    }

    if(_liczniki[nr_przycisku] > 0 && digitalRead(_przyciski[nr_przycisku]))
    {
      --_liczniki[nr_przycisku];
    }
  }

  void Wejscia::Wykryto(int tryb)
  {
  	switch(tryb)
  	{
  		case'0':
  			{
  				//fun 
  				break;
  			}

  		case'1':
  			{
  				//fun 
  				break;
  			}
  			
  		case'2':
  			{
  				//fun 
  				break;
  			}

  		case'3':
  			{
  				//fun 
  				break;
  			}

  		case'4':
  			{
  				//fun 
  				break;
  			}

  		default:
  			{
  				//Nie ma prawa się zdazyć
  			}	

  	}
  }