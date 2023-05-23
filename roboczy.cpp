#include <iostream>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_kolo();


class Kolo {
  private:
    double promien;

  public:
    // Konstruktor
    Kolo(double r) 
    {
      if (r > 0) 
      {
        promien = r;
      } else 
      {
        std::cout << "Błędny promień! Promień musi być większy od zera." << std::endl;
        promien = 0;
      }
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
    std::cout << "Podaj promień koła: ";
    std::cin >> promien;

    // Sprawdzenie, czy podany promień jest większy od zera
    while (promien <= 0)
    {
        std::cout << "Błędny promień! Promień musi być większy od zera." << std::endl;
        std::cout << "Podaj promień koła: ";
        std::cin >> promien;
    }

    // Tworzenie obiektu klasy Kolo
    Kolo* kolo = new Kolo(promien);

    // Wywołanie metody obliczPole() i wyświetlenie wyniku
    double pole = kolo ->obliczPole();
    std::cout << "Pole koła wynosi: " << pole << std::endl;

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
