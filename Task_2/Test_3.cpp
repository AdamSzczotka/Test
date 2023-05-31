#include "RideReport.h"

int main()
{
    const char *fileName = "no_data.txt";

    // Test 3: Przekazanie konstruktorowi nazwy pustego pliku
    RideReport report3("");
    report3.readData();
    report3.processData();
    report3.saveAsText("report3.txt");

    return 0;
}
