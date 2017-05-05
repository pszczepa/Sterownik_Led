#include "Arduino.h"




Kolor::Kolor(): _czerwony(0), _zielony(0), _niebieski(0), _dimmer(0)
  { }

Kolor::Kolor(int c, int z, int n)
  {
    _dimmer = 1;
    _czerwony = _dimmer * c;
    _zielony = _dimmer * z;
    _niebieski = _dimmer * n ;
  }

  Kolor::Kolor(int c, int z, int n, float d)
  {
    _dimmer = d;
    _czerwony = _dimmer * c;
    _zielony = _dimmer * z;
    _niebieski = _dimmer * n ;
  }

  int Kolor::Zielony()
  {
    return _zielony;  
  }

  int Kolor::Czerwony()
  {
    return _czerwony;  
  }

  int Kolor::Niebieski()
  {
    return _niebieski;  
  }