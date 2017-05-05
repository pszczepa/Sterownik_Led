#ifndef kolor_h
#define kolor_h

/*!
 *\file
 *\brief Definicja klasy Kolor
 *
 *
 *
 *
 */

#include "Arduino.h"
#include "kolor.h"

/*!
 *\brief Definicja klasy Kolor
 *
 *
 */
class Kolor
{
  /*!
   *\brief Pole przechowywujące wartość koloru czerwonego
   */
  int _czerwony;

  /*!
   *\brief Pole przechowywujące wartość koloru zielonego
   */
  int _zielony;

  /*!
   *\brief Pole przechowywujące wartość koloru niebieskiego
   */
  int _niebieski;

  /*!
   *\brief Pole przechowywujące wartość mnożnika 
   */
  float  _dimmer;

public:
  /*!
   *\brief Konstruktor bezparametryczny
   *
   * Inicjalizuje pola zerowymi wartościami 
   */
  Kolor();

  /*!
   *\brief Konstruktor 
   *
   * Inicjalizuje pola podanymi wartosciami od 0-255
   */
  Kolor(int c, int z, int n);

  /*!
   *\brief Konstruktor 
   *
   * Inicjalizuje pola podanymi wartosciami od 0-255 oraz _dimmer od 0-1
   */
  Kolor(int c, int z, int n, float d);

  /*!
   *\brief Zwraca wartość pola _zielony 
   */
  int Zielony();

  /*!
   *\brief Zwraca wartość pola _czerwony 
   */
  int Czerwony();

  /*!
   *\brief Zwraca wartość pola _niebieski
   */
  int Niebieski();
};


#endif