#include "RideReport.h"

int main()
{
    const char *fileName = "data.txt";

    // Test 2: Przekazanie konstruktorowi nazwy nieistniejącego pliku
    RideReport report2("non_existing_file.txt");
    report2.readData();
    report2.processData();
    report2.saveAsText("report2.txt");

    return 0;
}
