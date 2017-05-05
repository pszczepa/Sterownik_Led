#ifndef pasek_h
#define pasek_h

 /*!
  *\fo;e
  *\brief Definicja klasy Pasek
  *
  *
  *
  *
  */


#include "Arduino.h"
#include "kolor.h"

 /*!
  *\brief Definicja klasy Pasek
  *
  */ 
class Pasek
{
  /*!
   *\brief Przechowuje numer pinu dla kolou czerwonego
   *
   */
  int _czerwonyPin;

  /*!
   *\brief Przechowuje numer pinu dla kolou zielonego
   *
   */  
  int _zielonyPin;

  /*!
   *\brief Przechowuje numer pinu dla kolou niebieskiego
   *
   */
  int _niebieskiPin;

  bool _stan;

public:

  /*!
   *\brief Konstruktor bezprametryczny
   *
   */
  Pasek();

  /*!
   *\brief Konstruktor parametryczny inicjalizuje pola pinów
   *
   */
  Pasek(int r, int g, int b); 
 
  /*!
   *\brief Ustawia na odpowiadających pinach wartości z klasy wejściowej
   *
   */
  void PiszNaPasek(const Kolor & obj);
  
  /*!
   *\brief Ustawia na odpowiadających pinach wartości przekazane jak paramety wejściowe
   *
   *Zakres danych wejściowych 0-255
   */
  void PiszNaPasek(int r, int g, int b);

  /*!
   *\brief Ustawia piny paska jako wyjścia, wyłowywać w funkcji Setup()
   *
   */
  void InitSetup();
  
  bool ZwrocStan();
  
  void OdwrocStan();
  
  void PiszStan();
  
  void Fade(const int czas);
  
  void Fade2(const int czas);

  void Fade3(const int czas);

  void test1(const int czas);

 
};


#endif