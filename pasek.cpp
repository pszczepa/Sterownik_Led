#include "pasek.h"
#include "kolory.h"

Pasek::Pasek()
  {
    _czerwonyPin = 10 ;
    _zielonyPin = 9;
    _niebieskiPin = 11;

    _stan = true;
  }

 Pasek::Pasek(int r, int g, int b) : _czerwonyPin(r), _zielonyPin(g), _niebieskiPin(b), _stan(true)
  {}

  
void Pasek::PiszNaPasek(const Kolor & obj)
  {
    PiszNaPasek(obj.Czerwony(), obj.Zielony(), obj.Niebieski());
  }  

void Pasek::PiszNaPasek(int r, int g, int b)
  {
    if(_stan)
    {
      analogWrite(_zielonyPin, g);
      analogWrite(_czerwonyPin, r);  
      analogWrite(_niebieskiPin, b); 
    }
    else
    {
      PiszStan();
    }

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

bool Pasek::ZwrocStan()
  {
    return _stan;
  }

void Pasek::OdwrocStan()
  {
    _stan = !_stan;
  }

void Pasek::PiszStan()
  {
    if(!_stan)
    {
      PiszNaPasek(0,0,0);
    }
  }

void Pasek::Fade(const int czas)
  {
    int j = 255;
    int i = 0;



    for(int i = 0; i < 255; ++i )
    {
    PiszNaPasek(i,0,j);
    --j;
    delay(czas);
    }

     for(int i = 255; i > 0; --i )
    {
    PiszNaPasek(j,0,i);
    ++j;
    --i;
    delay(czas);
    }

  j = 255;
    for(int i = 0; i < 255; ++i )
    {
    PiszNaPasek(j,i,0);
    --j;
    delay(czas);
    }

    for(int i = 255; i > 0; --i )
    {
    PiszNaPasek(0,j,i);
    ++j;
    --i;
    delay(czas);
    }
      
  }

void Pasek::Fade2(const int czas)
  {
    int r = 0;
    int g = 0;
    int b = 0;
    
    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,0,0);
      ++r;
      delay(czas);
    }  

    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,0);
      ++g;
      delay(czas);
    }  

    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,b);
      --r;
      ++b;
      delay(czas);
    } 

    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,b);
      --b;
      delay(czas);
    } 

    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,b);
      --r;
      delay(czas);
    } 

    
  }


void Pasek::Fade3(const int czas)
  {
      int r = 0;
      int g = 0;
      int b = 0;
    
    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,0);
      ++r;
      ++g;
      delay(czas);
    } 

    for(int i = 0; i < 255; ++i )
    {
      PiszNaPasek(r,g,0);
      --r;
      --g;
      delay(czas);
    } 
  }

void Pasek::test1(const int czas)
  {
    PiszNaPasek(random(0,255),random(0,199),random(0,145));
    delay(czas);
  }

