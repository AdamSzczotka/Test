#include "RideReport.h"

int main()
{
    const char *fileName = "wrong_data.txt";

    // Test 4: Przekazanie konstruktorowi nazwy pliku nie zawierającego żadnego ze znaków z zestawu aAbBlLrR
    RideReport report4(fileName);
    report4.readData();
    report4.processData();
    report4.saveAsText("report4_text.txt");


    return 0;
}
