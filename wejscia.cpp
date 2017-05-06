#include "wejscia.h"



  Wejscia::Wejscia()
  {
    _przyciski[0] = 7;			//Bistabilny, normalnie nie używać 
    _przyciski[1] = 6;
    _przyciski[2] = 5;
    _przyciski[3] = 4;
    _przyciski[4] = 3;
    _trybW = 0;
    _trybZ = 0;
  }

  Wejscia::Wejscia(int p1, int p2, int p3, int p4, int p5)
   {}

  void Wejscia::InitSetup()
  {
      pinMode(_przyciski[0], INPUT);				
      pinMode(_przyciski[1], INPUT);
      pinMode(_przyciski[2], INPUT);
      pinMode(_przyciski[3], INPUT);
      pinMode(_przyciski[4], INPUT);
  }

  void Wejscia::CzytajNaSerial()
  {
    Serial.println(digitalRead(_przyciski[0])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[1])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[2])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[3])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[4])); Serial.print(" ");
  }

  void Wejscia::Sprawdz(int nr_przycisku, Pasek &obj)
  {
    if (!digitalRead(_przyciski[nr_przycisku]))
    {
      ++_liczniki[nr_przycisku];
     }

    if(_liczniki[nr_przycisku] > 100)
    {
      Wykryto(nr_przycisku, obj);
    }

    if(_liczniki[nr_przycisku] > 0 && digitalRead(_przyciski[nr_przycisku]))
    {
      --_liczniki[nr_przycisku];
    }
  }

  void Wejscia::Wykryto(int tryb,  Pasek &obj)
  {
  	Serial.println(tryb);
  	switch(tryb)
  	{
  		case 0 :
  			{
  				obj.PiszNaPasek(red); 
  				break;
  			}

  		case 1 :
  			{
  				obj.NegujStan();
  				break;
  			}
  			
  		case 2 :
  			{
  				obj.PiszNaPasek(blue);
  				break;
  			}

  		case 3 :
  			{
  				obj.PiszNaPasek(green);
  				break;
  			}

  		case 4 :
  			{
  				obj.NegujStan();
  				break;
  			}

  		default:
  			{
  				//Nie ma prawa się zdazyć
  			}	

  	}
  }

void Wejscia::SprawdzWszystkie( Pasek &obj)
  {
  	Sprawdz(0,obj);
  	Sprawdz(1,obj);
  	Sprawdz(2,obj);
  	Sprawdz(3,obj);
  	Sprawdz(4,obj);
  }

void Wejscia::ObslugaTrybow(char ktory_tryb, char czynnosc)
  {
  	 switch(ktory_tryb)
  	 {
  	 	case 'w':
  	 		{
  	 			if (czynnosc = 'i')
  	 				{
  	 					++_trybW;
  	 				}
  	 			else
  	 				{
  	 					--_trybW;
  	 				} 				
  	 		}
  	 	case 'z':
  	 		{
  	 			if (czynnosc = 'i')
  	 				{
  	 					++_trybZ;
  	 				}
  	 			else
  	 				{
  	 					--_trybZ;
  	 				} 
  	 		}
  	 }

  	 if(_trybZ > _maxZ)
  	 	{
  	 		_trybZ = 0;
  	 	}

  	 if(_trybW > _maxW)
  	 	{
  	 		_trybW = 0;
  	 	}  	 

  }
 
int Wejscia::TrybZ()
{
	return _trybZ;
}


int Wejscia::TrybW()
{
	return _trybW;
}


  
