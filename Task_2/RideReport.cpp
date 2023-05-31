#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>


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
    bool isEventCharacter(char c);

    const char *fileName_;
    char *data_;
    int dataSize_;
    int speedUpCount_;
    int slowDownCount_;
    int leftTurnCount_;
    int rightTurnCount_;
    std::string creationDate_;
    std::string creationTime_;
};

RideReport::RideReport(const char *fileName) : fileName_(fileName), data_(nullptr), dataSize_(0),
                                               speedUpCount_(0), slowDownCount_(0),
                                               leftTurnCount_(0), rightTurnCount_(0)
{
    std::time_t now = std::time(nullptr);
    std::tm *timeinfo = std::localtime(&now);

    std::ostringstream ossDate;
    ossDate << std::put_time(timeinfo, "%Y-%m-%d");
    creationDate_ = ossDate.str();

    std::ostringstream ossTime;
    ossTime << std::put_time(timeinfo, "%H:%M:%S");
    creationTime_ = ossTime.str();
}

RideReport::~RideReport()
{
    delete[] data_;
}

bool RideReport::readData()
{
    std::ifstream file(fileName_);
    if (!file)
    {
        std::cout << "Blad otwierania pliku: " << fileName_ << std::endl;
        return false;
    }

    // Get file size
    file.seekg(0, std::ios::end);
    dataSize_ = file.tellg();
    file.seekg(0, std::ios::beg);

    // Allocate memory for data
    data_ = new char[dataSize_ + 1];

    // Read file content
    file.read(data_, dataSize_);
    data_[dataSize_] = '\0';

    file.close();

    return true;
}

bool RideReport::processData()
{
    if (!data_)
    {
        std::cout << "Brak danych do przetworzenia." << std::endl;
        return false;
    }

    speedUpCount_ = 0;
    slowDownCount_ = 0;
    leftTurnCount_ = 0;
    rightTurnCount_ = 0;

    for (int i = 0; i < dataSize_; ++i)
    {
        char c = data_[i];
        if (isEventCharacter(c))
        {
            switch (c)
            {
            case 'a':
            case 'A':
                ++speedUpCount_;
                break;
            case 'b':
            case 'B':
                ++slowDownCount_;
                break;
            case 'l':
            case 'L':
                ++leftTurnCount_;
                break;
            case 'r':
            case 'R':
                ++rightTurnCount_;
                break;
            }
        }
    }

    return true;
}

int RideReport::getSpeedUpCount()
{
    return speedUpCount_;
}

int RideReport::getSlowDownCount()
{
    return slowDownCount_;
}

int RideReport::getLeftTurnCount()
{
    return leftTurnCount_;
}

int RideReport::getRightTurnCount()
{
    return rightTurnCount_;
}

bool RideReport::saveCleanedData(const char *fileName)
{
    if (!data_)
    {
        std::cout << "Brak danych do zapisu." << std::endl;
        return false;
    }

    std::ofstream file(fileName);
    if (!file)
    {
        std::cout << "Blad tworzenia pliku: " << fileName << std::endl;
        return false;
    }

    // Remove unwanted characters and save cleaned data
    for (int i = 0; i < dataSize_; ++i)
    {
        char c = data_[i];
        if (isEventCharacter(c))
        {
            file << c;
        }
    }

    file.close();

    return true;
}

bool RideReport::saveAsText(const char *fileName)
{
    if (!data_)
    {
        std::cout << "Brak danych do zapisu." << std::endl;
        return false;
    }

    std::ofstream file(fileName);
    if (!file)
    {
        std::cout << "Blad tworzenia pliku: " << fileName << std::endl;
        return false;
    }

    // Write report header
    file << "Data utworzenia: " << creationDate_ << std::endl;
    file << "Czas utworzenia: " << creationTime_ << std::endl;
    file << std::endl;

    // Write processed data
    file << "Liczba przyśpieszeń: " << speedUpCount_ << std::endl;
    file << "Liczba zwolnień: " << slowDownCount_ << std::endl;
    file << "Liczba skrętów w lewo: " << leftTurnCount_ << std::endl;
    file << "Liczba skrętów w prawo: " << rightTurnCount_ << std::endl;

    file.close();

    return true;
}

bool RideReport::saveAsXML(const char *fileName)
{
    if (!data_)
    {
        std::cout << "No data to save." << std::endl;
        return false;
    }

    std::ofstream file(fileName);
    if (!file)
    {
        std::cout << "Error creating file: " << fileName << std::endl;
        return false;
    }

    // Write XML report
    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    file << "<rideReport>" << std::endl;
    file << "  <creationDate>" << creationDate_ << "</creationDate>" << std::endl;
    file << "  <creationTime>" << creationTime_ << "</creationTime>" << std::endl;
    file << "  <data>" << std::endl;
    file << "    <speedUpCount>" << speedUpCount_ << "</speedUpCount>" << std::endl;
    file << "    <slowDownCount>" << slowDownCount_ << "</slowDownCount>" << std::endl;
    file << "    <leftTurnCount>" << leftTurnCount_ << "</leftTurnCount>" << std::endl;
    file << "    <rightTurnCount>" << rightTurnCount_ << "</rightTurnCount>" << std::endl;
    file << "  </data>" << std::endl;
    file << "</rideReport>" << std::endl;

    file.close();

    return true;
}

bool RideReport::isEventCharacter(char c)
{
    return (c == 'a' || c == 'A' || c == 'b' || c == 'B' || c == 'l' || c == 'L' || c == 'r' || c == 'R');
}
