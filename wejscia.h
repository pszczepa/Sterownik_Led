#ifndef wejscia_h
#define wejscia_h

/*!
 *\file
 *\brief Plik zawierający definicje klasy Wejscia
 *
 *
 */

#include "Arduino.h"
#include "kolory.h"
#include "pasek.h"

/*!
 *\brief Definicja klasy Wejscia
 *
 */
class Wejscia
{
  /*!
   *\brief Pole przechowujące numery pinów wejść cyforowych
   */
  int _przyciski[5];

  /*!
   *\brief Pole liczników służących do wykrywania wcisnięcia przycisku
   */
  int _liczniki[5] = {0,0,0,0,0};

  /*!
   *
   */

  int _trybW;

  int _trybZ;

  const int _maxW;

  const int _maxZ;



public:
  /*!
   *\brief Konstruktor bezparametryczny
   */
  Wejscia();
  /*!
   *\brief Kostrukor inicjalizujący komórki pola _przyciski[]
   */
  Wejscia(int p1, int p2, int p3, int p4, int p5);

  /*!
   *\brief Uswtawia odpowiednie piny jako wyjścia
   */
  void InitSetup();

  /*!
   *\brief Wypisuje wartości wejść cyfrowych do portu szeregowego
   */
  void CzytajNaSerial();

  /*!
   *\brief Sprawdza stan przycisku
   */
  void Sprawdz(int nr_przycisku,  Pasek &obj);

  /*!
   *\brief Podejmuje odpowiednie działanie dla wykrytego pinu
   */
  void Wykryto(int tryb,  Pasek &obj);

  /*!
   *\brief Sprawdza wszystkie wejścia cyfrowe, raczej nie używać, ale działa ok
   */
  void SprawdzWszystkie( Pasek &obj);

  void ObslugaTrybow(char ktory_tryb, char czynnosc);

  int TrybZ();

  int TrybW();
    
};


#endif