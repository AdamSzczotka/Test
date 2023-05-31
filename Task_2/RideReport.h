#ifndef RIDE_REPORT_H
#define RIDE_REPORT_H

class RideReport
{
public:
    RideReport(const char *fileName);
    ~RideReport();
    bool readData();
    bool processData();
    int getSpeedUpCount();
    int getSlowDownCount();
    int getLeftTurnCount();
    int getRightTurnCount();
    bool saveCleanedData(const char *fileName);
    bool saveAsText(const char *fileName);
    bool saveAsXML(const char *fileName);

private:
    char *data;
    int length;
    int speedUpCount;
    int slowDownCount;
    int leftTurnCount;
    int rightTurnCount;
};

#endif
