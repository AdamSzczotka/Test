#include "RideReport.h"

int main()
{
    const char *fileName = "ride_data.txt";

    // Test 1: Przekazanie konstruktorowi wskaźnika pustego
    RideReport report1(nullptr);
    report1.readData();
    report1.processData();
    report1.saveAsText("report1.txt");

    return 0;
}
