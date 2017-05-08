#ifndef pasek_h
#define pasek_h

 /*!
  *\file
  *\brief Plik zawierający definicję klasy Pasek
  *
  *
  *
  *
  */


#include "Arduino.h"
#include "kolor.h"
#include "kolory.h"


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

  /*!
   *\brief Przechowuje stan
   *
   */
  bool _stan;

  /*!
   *\brief Przechowuje wartość koloru czerwonego dla funkcji Fade()
   *
   */
  int _fade_czerwony;

    /*!
   *\brief Przechowuje wartość koloru czerwonego dla funkcji Fade()
   *
   */
  int _fade_zielony;

    /*!
   *\brief Przechowuje wartość koloru czerwonego dla funkcji Fade()
   *
   */
  int _fade_niebieski;

    /*!
   *\brief Przechowuje licznik dla funkcji Fade()
   *
   */
  int _licznik;

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
  
  /*!
   *\brief 
   *
   */
  void Potencjometry();

  /*!
   *\brief Ustawia piny paska jako wyjścia, wyłowywać w funkcji Setup()
   *
   */
  void PotencjometryMatrix();
  
  bool Stan();

  void NegujStan();

  void Fade();
  
  void test1(const int czas);

 
};


#endif