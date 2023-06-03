#include "RideReport.h"
#include <iostream>

using namespace std;

int main()
{
    const char *fileName = "data.txt";

    // Test 0: Przekazanie konstruktorowi nazwy pliku z prawidłowym zestawem znaków
    RideReport report(fileName);
    if(report.readData())
    {
        if(report.processData())
        {
            cout << "\nPrzyspieszenia: " << report.getSpeedUpCount();
            cout << "\nHamowania: " << report.getSlowDownCount();
            cout << "\nW lewo: "  << report.getLeftTurnCount();
            cout << "\nW prawo: " << report.getRightTurnCount();

            if(report.saveCleanedData("report_working_clean_data.txt"))
                cout << "\nOczyszczone dane zapisane";

            if(report.saveAsText("report_working.txt"))
                cout << "\nRaport tekstowy zapisany";

            if(report.saveAsXML("report_working.xml"))
                cout << "\nPlik XML zapisany";
        }
    }
    

    return 0;
}

