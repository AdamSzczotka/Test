#include <iostream>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_kolo();

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

