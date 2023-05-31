#include "RideReport.h"

int main()
{
    const char *fileName = "data.txt";

    // Test 0: Przekazanie konstruktorowi nazwy pliku z prawidłowym zestawem znaków
    RideReport report0(fileName);
    report0.readData();
    report0.processData();
    report0.saveAsText("report_working.txt");
    report0.saveAsXML("report_working.xml");
    report0.saveCleanedData("report_working_clean_data.txt");

    return 0;
}

