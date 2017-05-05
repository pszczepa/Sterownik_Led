#ifndef pasek_h
#define pasek_h

#include "Arduino.h"
#include "kolor.h"


class Pasek
{
  int _czerwonyPin;
  int _zielonyPin;
  int _niebieskiPin;

  bool _stan;

public:
  Pasek();

  Pasek(int r, int g, int b); 
 
  void PiszNaPasek(Kolor & obj);
  
  void PiszNaPasek(int r, int g, int b);

  void InitSetup();
  
  bool ZwrocStan();
  
  void OdwrocStan();
  
  void PiszStan();
  
  void Fade(int czas);
  
  void Fade2(int czas);

  void Fade3(int czas);

  void test1(int czas);

 
};


#endif