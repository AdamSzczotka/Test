#include <iostream>

using namespace std;

void wyswietla_menu();
void liczy_kwadrat();
void liczy_kolo();



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

