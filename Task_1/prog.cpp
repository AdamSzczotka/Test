#include <iostream>
using namespace std;

class Kwadrat
{
private:
    float bok;
public:
    Kwadrat();
    ~Kwadrat();
    void setBok(float bok);
    float getBok();
    float pole();
};

Kwadrat::Kwadrat(/* args */)
{
    bok = 1;
}

Kwadrat::~Kwadrat()
{
}

void wyswietla_menu();
double sprawdza_czy_wieksza_od_zera();
double wczytuje_liczby(string nazwa_zmiennej);

Kwadrat * kwadrat; 

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
            kwadrat = new Kwadrat();
            kwadrat->setBok(wczytuje_liczby("Bok"));
            cout<<"Pole kwadratu wynosi: "<<kwadrat->pole()<<endl;
            delete kwadrat;
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
double sprawdza_czy_wieksza_od_zera(double liczba, string nazwa_zmiennej)
{
    while(liczba <= 0)
    {
        system("cls");
        cout<<"Blad, "<<nazwa_zmiennej<<" musi byc wieksza od 0! Sprobuj jeszcze raz."<<endl;
        cout<<"Podaj "<<nazwa_zmiennej<<"= ";
        cin>>liczba;
    }

    return liczba;
}

double wczytuje_liczby(string nazwa_zmiennej)
{
    double liczba;

    system("cls");

    cout<<"Podaj "<<nazwa_zmiennej<<"= ";
    cin>>liczba;

    liczba = sprawdza_czy_wieksza_od_zera(liczba, nazwa_zmiennej);

    return liczba;
}

void Kwadrat::setBok(float bok)
{
    Kwadrat::bok = bok;
}

float Kwadrat::getBok()
{
    return Kwadrat::bok;
}

float Kwadrat::pole()
{
    return bok * bok;
}