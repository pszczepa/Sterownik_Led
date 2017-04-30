#ifndef wejscia_h
#define wejscia_h

#include "Arduino.h"

/* WEJSCIA */
class Wejscia
{
  int _przyciski[5] ;
  int _liczniki[5] = {0,0,0,0,0};


public:
  Wejscia();

  Wejscia(int p1, int p2, int p3, int p4, int p5);

  void InitSetup();

  void CzytajNaSerial();

  void Sprawdz(int nr_przycisku);

  void Wykryto(int tryb);
    
};


#endif