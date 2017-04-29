#ifndef wejscia_hh
#define wejscia_hh

/* WEJSCIA */
class Wejscia
{
  int _przyciski[5] ;
  int _liczniki[5] = {0,0,0,0,0};


public:
  Wejscia()
  {
    _przyciski[0] = 7;
    _przyciski[1] = 6;
    _przyciski[2] = 5;
  }

  Wejscia(int p1, int p2, int p3, int p4, int p5)
   {}

  void InitSetup()
  {
      pinMode(_przyciski[0], INPUT);
      pinMode(_przyciski[1], INPUT);
      pinMode(_przyciski[2], INPUT);
  }

  void CzytajNaSerial()
  {
    Serial.println(digitalRead(_przyciski[0])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[1])); Serial.print(" ");
    Serial.print(digitalRead(_przyciski[2])); Serial.print(" ");
  }

  void Sprawdz(int przycisk)
  {
    if (!digitalRead(_przyciski[przycisk]))
    {
      ++liczniki[przycisk];
     }

    if(liczniki[przycisk] > 100)
    {
      Wykryto(przycisk);
    }

    if(liczniki[przycisk] > 0 && digitalRead(_przyciski[przycisk]))
    {
      --liczniki[przycisk];
    }
  }

  void Wykryto(int tryb)
  {}
    
};


#endif