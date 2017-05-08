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
    _maxZ = 2;
    _maxW = 3;
  }

  Wejscia::Wejscia(int p1, int p2, int p3, int p4, int p5)
   {}

   Wejscia::Wejscia(int maxz, int maxw)
   {
   	_przyciski[0] = 7;			//Bistabilny, normalnie nie używać 
    _przyciski[1] = 6;
    _przyciski[2] = 5;
    _przyciski[3] = 4;
    _przyciski[4] = 3;
    _trybW = 0;
    _trybZ = 0;
    _maxW  = maxw;
    _maxZ  = maxz;

   }

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
  	//Serial.println(tryb);
  	switch(tryb)
  	{
  		case 0 :
  			{
  				//obj.PiszNaPasek(red); 
  				break;
  			}

  		case 1 :
  			{
  				ObslugaTrybow(1,1,tryb);
  				break;
  			}
  			
  		case 2 :
  			{
          obj.NegujStan();
          _liczniki[tryb] = 0;
  				break;
  			}

  		case 3 :
  			{
          obj.NegujStan();
          _liczniki[tryb] = 0;
   				break;
  			}

  		case 4 :
  			{
  				ObslugaTrybow(2,1,tryb);
  				break;
  			}

  		default:
  			{
  				//Nie ma prawa się zdazyć
  			}	

  	}
  }

void Wejscia::SprawdzWszystkie(Pasek &obj)
  {
  	Sprawdz(0,obj);
  	Sprawdz(1,obj);
  	Sprawdz(2,obj);
  	Sprawdz(3,obj);
  	Sprawdz(4,obj);
  }

void Wejscia::ObslugaTrybow(int ktory_tryb, int czynnosc, int przycisk)
  {

  	if(ktory_tryb == 1)
  	{
		if(czynnosc == 1)
  		{
  			++_trybW;
  		}
  		else
  		{
  	 		--_trybW;
  	 	}
  	} 				
  	else if(ktory_tryb == 2)
  	{
  		if(czynnosc == 1)
  		{
  			++_trybZ;
  	 	}
  	 	else
  	 	{
  	 		--_trybZ;
  	 	} 
  	}

  	_liczniki[przycisk] = 0;
  	 

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


  
