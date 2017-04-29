#ifndef kolor_hh
#define kolor_hh

struct Kolor
{
  int _czerwony;
  int _zielony;
  int _niebieski;
  float  _dimmer;

  Kolor(): _czerwony(0), _zielony(0), _niebieski(0), _dimmer(1)
  { }


  Kolor(int c, int z, int n)
  {
    _dimmer = 1;
    _czerwony = _dimmer * c;
    _zielony = _dimmer * z;
    _niebieski = _dimmer * n ;
  }

   Kolor(int c, int z, int n, float d)
  {
    _dimmer = d;
    _czerwony = _dimmer * c;
    _zielony = _dimmer * z;
    _niebieski = _dimmer * n ;
  }

  int Zielony()
  {
    return _zielony;  
  }

  int Czerwony()
  {
    return _czerwony;  
  }

  int Niebieski()
  {
    return _niebieski;  
  }
  
};


#endif