#include <iostream>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_kolo();
void liczy_trojkat();


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
          std::cout << "Bledny promien! Promien musi byc wiekszy od zera." << std::endl;
          std::cout << "Podaj promien kola: ";
          std::cin >> promien;
      }

      Kolo::promien = promien;
    }

    // Metoda obliczająca pole koła
    double obliczPole() 
    {
      return 3.14159 * promien * promien;
    }

    // Destruktor
    ~Kolo()
    {
        cout << "Usunięto obiekt klasy Kolo" << endl;
    }
};

class Kwadrat {
private:
  float bok;


public:
  // Konstruktor
  Kwadrat()
  {

  }

  // Destruktor
  ~Kwadrat()
  {

  }

  // Setter dla boku
  void ustawBok(float dlugoscBoku) 
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
  float wyswietlBok() 
  {
    return Kwadrat::bok;
  }

  // Metoda do obliczania pola kwadratu
  float obliczPole()  
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
  Trojkat() 
  {

  }

  // Setter dla podstawy a
  void ustawPodstawe(double podstawa) 
  {
    while(podstawa <= 0)
    {
      std::cout << "Bledna podstawa! Podstawa musi byc wieksza od zera." << std::endl;
      std::cout << "Podaj podstawe trojkata: ";
      std::cin >> podstawa;
    }

    Trojkat:: a = podstawa;
  }

  // Getter dla boku a
  double wysiwietlPodstawe() 
  {
    return Trojkat:: a;
  }

  // Setter dla wysokości h
  void ustawWysokosc(double wysokosc) 
  {
    while(wysokosc <= 0)
    {
      std::cout << "Bledna wysokosc! Wysokosc musi byc wieksza od zera." << std::endl;
      std::cout << "Podaj wysokosc trojkata: ";
      std::cin >> wysokosc;
    }

    Trojkat:: h = wysokosc;
  }

  // Getter dla wysokości h
  double wyswietlWysokosc() 
  {
    return Trojkat:: h;
  }

  // Metoda obliczająca pole trójkąta
  double obliczPole() 
  {
    return (a * h) / 2.0;
  }

  // Destruktor
  ~Trojkat() 
  {
    std::cout << "Obiekt Trojkat zostal zniszczony." << std::endl;
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
            //wyswietla_pole_prostokat();

            break;
        case '3' :
            //wyswietla_pole_kola();
            liczy_kolo();

            break;
        case '4' :
            //wyswietla_pole_trojkat();
            liczy_trojkat();

            break;
        case '5' :
            //wyswietla_pole_trapez();

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
    std::cout << "Podaj promien kola: ";
    std::cin >> promien;

    // Tworzenie obiektu klasy Kolo
    Kolo* kolo = new Kolo();

    // Wywołanie metody ustawPromien()
    kolo->ustawPromien(promien);

    // Wywołanie metody obliczPole() i wyświetlenie wyniku
    double pole = kolo ->obliczPole();
    std::cout << "Pole kola wynosi: " << pole << std::endl;

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
    std::cout << "Podaj dlugosc boku a trojkata ";
    std::cin >> a;
    std::cout << "Podaj wysokosc h trojkata ";
    std::cin >> h;

    // Tworzenie obiektu klasy Triangle
    Trojkat* trojkat = new Trojkat();

    // Wywołanie metody ustawPodstawe()
    trojkat->ustawPodstawe(a);

    // Wywołanie metody ustawWysokosc()
    trojkat->ustawWysokosc(h);

    // Wywołanie metody obliczPole() i wyświetlenie wyniku
    double pole = trojkat->obliczPole();
    std::cout << "Pole trojkata wynosi: " << pole << std::endl;

    // Usunięcie obiektu po obliczeniu
    delete trojkat;
}
