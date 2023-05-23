#include <iostream>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_prostokat();
void liczy_kolo();
void liczy_trapez();

class Kwadrat {
private:
  double bok;

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

class Prostokat {
    private:
        double dlugosc;
        double szerokosc;

    public:
        // Konstruktor
        Prostokat() {}

        // Destruktor
        ~Prostokat() {}

    // Setter dla długości
    void ustawDlugosc(double nowaDlugosc) {
        while (nowaDlugosc <= 0) 
        {
            cout << "Niepoprawna długosc, musi byc wieksza od 0! Sprobuj jeszcze raz." << endl;
            cout << "Podaj długosc: ";
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

class Trapez {
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
  double pobierzPodstawe1()  {
    return podstawa1;
  }

  // Getter dla podstawy 2
  double pobierzPodstawe2()  {
    return podstawa2;
  }

  // Getter dla wysokości
  double pobierzWysokosc()  {
    return wysokosc;
  }

  // Metoda do obliczania pola trapezu
  double obliczPole()  {
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
            //wyswietla_pole_kola();

            break;
        case '4' :
            //wyswietla_pole_trojkat();

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
