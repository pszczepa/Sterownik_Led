//smieci
/*
 void Fade1(Kolor str[], int rozmiar, int czas)
  {
    Kolor *Tab = str;
    bool flag1 = 0;
    int i = 0;
    int j = 1;

    PiszNaPasek(Tab[0]);
    
    if(rozmiar > 1)
    {
      while(j < rozmiar)
        {
          while(Tab[i].Czerwony() != Tab[j].Czerwony() && Tab[i].Zielony() != Tab[j].Zielony() && Tab[i].Niebieski() != Tab[j].Niebieski() )
          {
            if(Tab[i].Czerwony() > Tab[j].Czerwony())
              {
                Tab[i]._czerwony--;
              }
            else if(Tab[i].Czerwony() < Tab[j].Czerwony())
              {
                Tab[i]._czerwony++;
              } 

            if(Tab[i].Zielony() > Tab[j].Zielony())
              {
                Tab[i]._zielony--;
              }
            else if(Tab[i].Zielony() < Tab[j].Zielony())
              {
                Tab[i]._zielony++;
              } 

             if(Tab[i].Niebieski() > Tab[j].Niebieski())
              {
                Tab[i]._niebieski--;
              }
            else if(Tab[i].Niebieski() < Tab[j].Niebieski())
              {
                Tab[i]._niebieski++;
              } 

            PiszNaPasek(Tab[i]);
            delay(czas);
          }
              i++;
              j++;
        }

        while(Tab[i].Czerwony() != Tab[j].Czerwony() && Tab[i].Zielony() != Tab[j].Zielony() && Tab[i].Niebieski() != Tab[j].Niebieski() )  
        {
            if(Tab[i].Czerwony() > Tab[0].Czerwony())
              {
                Tab[i]._czerwony--;
              }
            else if(Tab[i].Czerwony() < Tab[0].Czerwony())
              {
                Tab[i]._czerwony++;
              } 
            PiszNaPasek(Tab[i]);
            delay(czas);
        }

        
    }
  }*/

/*
int counter;
int counter2;
bool pin13state = false;
int czas = 100;
int indeks = 0;


void Wykryto()
{
  if(indeks < 5)
  {
    ++indeks;
  }
  else 
  {
    indeks = 0;
  }

  counter = 0;
}

void Wykryto7()
{
  if(!p1.ZwrocStan())
  {
    p1.PiszNaPasek(0,0,0); 
  }

    

  p1.OdwrocStan();
  counter = 0;
}

void Sprawdz()
{
  int test = 6;
  if (!digitalRead(test))
  {
    ++counter;
    

  }

  if(counter > 100)
  {
    Wykryto();
  }

  if(counter > 0 && digitalRead(test))
  {
    --counter;
  }
}

void Sprawdz7()
{
  if (!digitalRead(7))
  {
    ++counter2;
    

  }

  if(counter2 > 100)
  {
    Wykryto();
  }

  if(counter2 > 0 && digitalRead(7))
  {
    --counter2;
  }
}

*/