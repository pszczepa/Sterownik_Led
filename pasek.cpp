#include "pasek.h"
#include "kolory.h"

Pasek::Pasek()
  {
    _czerwonyPin = 10 ;
    _zielonyPin = 9;
    _niebieskiPin = 11;
    _stan = true;

    _fade_czerwony = 0;
    _fade_niebieski = 0;
    _fade_zielony = 0;
    _licznik = 0;
    
  }

 Pasek::Pasek(int r, int g, int b) : _czerwonyPin(r), _zielonyPin(g), _niebieskiPin(b), _stan(true)
  {}

  
void Pasek::PiszNaPasek(const Kolor & obj)
  {
    PiszNaPasek(obj.Czerwony(), obj.Zielony(), obj.Niebieski());
  }  

void Pasek::PiszNaPasek(int r, int g, int b)
  {

    analogWrite(_zielonyPin, g);
    analogWrite(_czerwonyPin, r);  
    analogWrite(_niebieskiPin, b); 

    Serial.write(r);
    Serial.write(g);
    Serial.write(b);
    Serial.println();
  } 

void Pasek::InitSetup()
  {
  	pinMode(_czerwonyPin, OUTPUT);
  	pinMode(_zielonyPin, OUTPUT);
  	pinMode(_niebieskiPin, OUTPUT);
  }

void Pasek::Potencjometry()
  {
  	int x  = analogRead(A1);
  	int ind = map(x,0,1023,0,3);
  	int y  = analogRead(A2); 
  	int wartosc = map(y,0,1023,0,255);
  	

  	if(x < 128)
  	{
  		PiszNaPasek(wartosc,wartosc,0);
  	}

  	else if(x > 127 && x < 256)
  	{
  		PiszNaPasek(wartosc,0,0);
  	}

  	else if(x > 255 && x < 512)
  	{
  		PiszNaPasek(0,wartosc,0);
  	} 

  	else if(x > 511 && x < 640)
  	{
  		PiszNaPasek(0,0,wartosc);
  	} 

  	else if(x > 639 && x < 768)
  	{
  		PiszNaPasek(wartosc,0,wartosc);
  	} 

  	else 
  	{
  		PiszNaPasek(wartosc,wartosc,wartosc);
  	}
  	

  }

void Pasek::PotencjometryMatrix()
{
 	int x  = analogRead(A1);
 	int xx = map(x,0,1023,0,3);
 	int y  = analogRead(A2); 
 	int yy = map(y,0,1023,0,4);

 	PiszNaPasek(matrix1[xx][yy]);
}


bool Pasek::Stan()
{
	return _stan;
}

void Pasek::NegujStan()
{
	_stan = !_stan;
}

void Pasek::Fade()
  {
    ++_licznik;

    if(_licznik < 255)
    {
      ++_fade_czerwony;
      PiszNaPasek(_fade_czerwony,0,0);
    }
    if(_licznik > 255 && _licznik < 510)
    {
      ++_fade_niebieski;
      PiszNaPasek(255,0,_fade_niebieski);
    }

    if(_licznik > 510 && _licznik < 765)
    {
      ++_fade_zielony;
      PiszNaPasek(255,_fade_zielony,255);
    }

    if(_licznik > 765 && _licznik < 1020)
    {
      --_fade_zielony;
      --_fade_czerwony;
      PiszNaPasek(_fade_czerwony,_fade_zielony,255);
    }

    if(_licznik > 1020 && _licznik < 1275)
    {
      ++_fade_zielony;
      PiszNaPasek(0,_fade_zielony,255);
    }

    if(_licznik > 1275 && _licznik < 1530)
    {
      --_fade_niebieski;
      PiszNaPasek(0,255,_fade_niebieski);
    }

    if(_licznik > 1530 && _licznik < 1785)
    {
      --_fade_zielony;
      PiszNaPasek(0,_fade_zielony,0);
    }

    if(_licznik > 1785)
    {
      _licznik = 0;  
    }
      
  }

void Pasek::test1(const int czas)
  {
    PiszNaPasek(random(0,255),random(0,199),random(0,145));
    delay(czas);
  }

