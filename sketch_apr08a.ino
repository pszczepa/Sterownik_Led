#include "pasek.hh"
#include "kolor.hh"
#include "wejscia.hh"



  Pasek p1;
  Wejscia w1;
  int indeks;




void setup() 
{
  w1.InitSetup();
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);

p1.PiszNaPasek(255,0,0);

}
  int MODE = 1;




  Kolor red(255,0,0);
  Kolor green(0,255,0);
  Kolor blue(0,0,255);
  Kolor violet(149,27,186);
  Kolor pink(255,0,127);
  Kolor aqua(51,200,255);

  Kolor r1(255,51,51);
  Kolor y1(255,255,102);
  Kolor g1(102,255,102);
  Kolor a1(102,255,255);
  Kolor b1(102,102,255);
  Kolor gr1(192,192,192);



  Kolor str1[] = {red,green,blue,violet,pink,aqua};
  Kolor str2[] = {r1,y1,g1,a1,b1,gr1};


void loop() 
{
  
  if(digitalRead(7))
    {
      p1.PiszNaPasek(str1[indeks]);
    }
  else
  {
      p1.PiszNaPasek(str2[indeks]);
  }
  

}




