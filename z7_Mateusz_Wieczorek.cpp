#include <iostream>
#include <math.h>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_prostokat();
void liczy_kolo();
void liczy_trojkat();
void liczy_trapez();


class Kolo {
  private:
    double promien;

  public:
    // Konstruktor
    Kolo() 
    {

    }

    // Setter dla promienia
    void ustawPromien(double promien)
    {
      // Sprawdzenie, czy podany promień jest większy od zera
      while (promien <= 0)
      {
        cout << "Bledny promien! Promien musi byc wiekszy od zera." << endl;
        cout << "Podaj promien kola: ";
        cin >> promien;
      }

      Kolo::promien = promien;
    }

    // Metoda obliczająca pole koła
    double obliczPole() 
    {
      return M_PI * pow(promien, 2);
    }

    // Destruktor
    ~Kolo() {}
};

class Kwadrat {
private:
  double bok;

public:
  // Konstruktor
  Kwadrat() {}

  // Destruktor
  ~Kwadrat() {}

  // Setter dla boku
  void ustawBok(double dlugoscBoku) 
  {
    while (dlugoscBoku <= 0)
    {
        cout<< endl << "Nieporawne dane, bok musi byc wiekszy od 0! Sprobuj jeszcze raz"<< endl;
        cout<<"Podaj bok: ";
        cin>>dlugoscBoku;
    }

    Kwadrat::bok = dlugoscBoku;
    
  }

  // Getter dla boku
  double wyswietlBok() 
  {
    return Kwadrat::bok;
  }

  // Metoda do obliczania pola kwadratu
  double obliczPole()  
  {
    return bok * bok;
  }
};


class Trojkat 
{
  private:
    double a;
    double h;

  public:
    // Konstruktor
    Trojkat() {}

    // Setter dla podstawy a
    void ustawPodstawe(double podstawa) 
    {
      while(podstawa <= 0)
      {
        cout << "Bledna podstawa! Podstawa musi byc wieksza od zera." << endl;
        cout << "Podaj podstawe trojkata: ";
        cin >> podstawa;
      }

      Trojkat::a = podstawa;

    }

    // Getter dla boku a
    double wysiwietlPodstawe() 
    {
      return Trojkat::a;
    }

    // Setter dla wysokości h
    void ustawWysokosc(double wysokosc) 
    {
      while(wysokosc <= 0)
      {
        cout << "Bledna wysokosc! Wysokosc musi byc wieksza od zera." << endl;
        cout << "Podaj wysokosc trojkata: ";
        cin >> wysokosc;
      }

      Trojkat::h = wysokosc;
    }

    // Getter dla wysokości h
    double wyswietlWysokosc() 
    {
      return Trojkat::h;
    }

    // Metoda obliczająca pole trójkąta
    double obliczPole() 
    {
      return (a * h) / 2;
    }

    // Destruktor
    ~Trojkat() {}
};

class Prostokat 
{
  private:
    double dlugosc;
    double szerokosc;

  public:
    // Konstruktor
    Prostokat() {}

    // Destruktor
    ~Prostokat() {}

    // Setter dla długości
    void ustawDlugosc(double nowaDlugosc) 
    {
      while (nowaDlugosc <= 0) 
      {
        cout << "Niepoprawna dlugosc, musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
        cout << "Podaj dlugosc: ";
        cin >> nowaDlugosc;
      }

      Prostokat::dlugosc = nowaDlugosc;
    }

    // Setter dla szerokości
    void ustawSzerokosc(double nowaSzerokosc) {
      while (nowaSzerokosc <= 0) 
      {
        cout << "Niepoprawna szerokosc, musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
        cout << "Podaj szerokosc: ";
        cin >> nowaSzerokosc;
      }

      szerokosc = nowaSzerokosc;
    }

    // Getter dla długości
    double pobierzDlugosc()  
    {
      return dlugosc;
    }

    // Getter dla szerokości
    double pobierzSzerokosc()  
    {
      return szerokosc;
    }

    // Metoda do obliczania pola prostokąta
    double obliczPole()  
    {
      return dlugosc * szerokosc;
    }
};

class Trapez 
{
private:
  double podstawa1;
  double podstawa2;
  double wysokosc;

public:
  // Konstruktor
  Trapez() {}

  // Destruktor
  ~Trapez() {}

  // Setter dla podstawy 1
  void ustawPodstawe1(double nowaPodstawa1) {
    while (nowaPodstawa1 <= 0) {
      cout << "Niepoprawna wartosc dla podstawyA. Musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
      cout << "Podaj wartosc podstawyA: ";
      cin >> nowaPodstawa1;
    }

    podstawa1 = nowaPodstawa1;
  }

  // Setter dla podstawy 2
  void ustawPodstawe2(double nowaPodstawa2) {
    while (nowaPodstawa2 <= 0) {
      cout << "Niepoprawna wartosc dla podstawyB. Musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
      cout << "Podaj wartosc podstawyB: ";
      cin >> nowaPodstawa2;
    }

    podstawa2 = nowaPodstawa2;
  }

  // Setter dla wysokości
  void ustawWysokosc(double nowaWysokosc) {
    while (nowaWysokosc <= 0) {
      cout << "Niepoprawna wartosc dla wysokosciH. Musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
      cout << "Podaj wartosc wysokosciH: ";
      cin >> nowaWysokosc;
    }

    wysokosc = nowaWysokosc;
  }

  // Getter dla podstawy 1
  double pobierzPodstawe1()  
  {
    return podstawa1;
  }

  // Getter dla podstawy 2
  double pobierzPodstawe2()  
  {
    return podstawa2;
  }

  // Getter dla wysokości
  double pobierzWysokosc()  
  {
    return wysokosc;
  }

  // Metoda do obliczania pola trapezu
  double obliczPole()  
  {
    return (podstawa1 + podstawa2) * wysokosc / 2;
  }
};

int main(int argc, char const *argv[])
{
  wyswietla_menu();

  return 0;
}

void wyswietla_menu()
{
  bool warunek = true;
  do
  {
    char odp;

    system("cls");

    cout<<"Program FIGURY"<<endl;
    cout<<"\n1. Pole kwadratu"<<endl;
    cout<<"2. Pole prostokata"<<endl;
    cout<<"3. Pole kola"<<endl;
    cout<<"4. Pole trojkata"<<endl;
    cout<<"5. Pole trapezu"<<endl;
    cout<<"\n0. Koniec programu"<<endl;
    cout<<"\nWybierz [0-5] co chcesz zrobic: ";

    cin>>odp;

    switch (odp)
    {
      case '0' :
        warunek = false;
        cout<<"Koniec programu. Autor: Mateusz Wieczorek"<<endl;
        break;
      case '1' :
        liczy_kwadrat();
        break;
      case '2' :
        liczy_prostokat();
        break;
      case '3' :
        liczy_kolo();

        break;
      case '4' :
        liczy_trojkat();

        break;
      case '5' :
        liczy_trapez();

        break;
      default:
        system("cls");
        cout<<"Nierozpoznano znaku. Sprobuj ponownie."<<endl;
        break;
    }
    system("pause");

  }while (warunek);
}

void liczy_kolo()
{
  double promien;
  cout << "Podaj promien kola: ";
  cin >> promien;

  // Tworzenie obiektu klasy Kolo
  Kolo * kolo = new Kolo();

  // Wywołanie metody ustawPromien()
  kolo->ustawPromien(promien);

  // Wywołanie metody obliczPole() i wyświetlenie wyniku
  double pole = kolo ->obliczPole();
  cout << "Pole kola wynosi: " << pole << endl;

  delete kolo;
}

void liczy_kwadrat()
{
  float bok;

  Kwadrat * kwadrat = new Kwadrat();
  cout<< endl <<"Podaj bok: ";
  cin>>bok;
  kwadrat->ustawBok(bok);
  cout<<endl<<"Pole kwadratu wynosi: " <<kwadrat->obliczPole() << endl;
  delete kwadrat;

}


void liczy_trojkat()
{
    double a, h;
    cout << "Podaj dlugosc boku a trojkata: ";
    cin >> a;


    // Tworzenie obiektu klasy Triangle
    Trojkat * trojkat = new Trojkat();

    // Wywołanie metody ustawPodstawe()
    trojkat->ustawPodstawe(a);
    
    cout << "Podaj wysokosc h trojkata: ";
    cin >> h;
    // Wywołanie metody ustawWysokosc()
    trojkat->ustawWysokosc(h);

    // Wywołanie metody obliczPole() i wyświetlenie wyniku
    double pole = trojkat->obliczPole();
    cout << "Pole trojkata wynosi: " << pole << endl;

    // Usunięcie obiektu po obliczeniu
    delete trojkat;
}

void liczy_prostokat()
{
    float dlugosc, szerokosc;

    Prostokat * prostokat = new Prostokat();
    cout<< endl <<"Podaj dlugosc: ";
    cin>>dlugosc;
    prostokat->ustawDlugosc(dlugosc);
    cout<< endl <<"Podaj szerokosc: ";
    cin>>szerokosc;
    prostokat->ustawSzerokosc(szerokosc);
    cout<<endl<<"Pole prostokatu wynosi: " <<prostokat->obliczPole() << endl;
    delete prostokat;

}

void liczy_trapez()
{
    float podstawaA, podstawaB, wysokoscH;

    Trapez * trapez = new Trapez();
    cout<< endl <<"Podaj PodstawaA: ";
    cin>>podstawaA;
    trapez->ustawPodstawe1(podstawaA);
    cout<< endl <<"Podaj PodstawaB: ";
    cin>>podstawaB;
    trapez->ustawPodstawe2(podstawaB);
    cout<< endl <<"Podaj wysokoscH: ";
    cin>>wysokoscH;
    trapez->ustawWysokosc(wysokoscH);
    cout<<endl<<"Pole trapezu wynosi: " <<trapez->obliczPole() << endl;
    delete trapez;
}
