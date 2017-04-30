#ifndef kolor_h
#define kolor_h

#include "Arduino.h"

struct Kolor
{
  int _czerwony;
  int _zielony;
  int _niebieski;
  float  _dimmer;

  Kolor();

  Kolor(int c, int z, int n);

  Kolor(int c, int z, int n, float d);

  int Zielony();

  int Czerwony();

  int Niebieski();
  


#endif