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
    char *dataFirstPos_;
    int dataSize_;
    int speedUpCount_;
    int slowDownCount_;
    int leftTurnCount_;
    int rightTurnCount_;
    bool proccessed_;
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

    proccessed_ = false;
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
        //std::cout << "Blad otwierania pliku: " << fileName_ << std::endl;
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
    dataFirstPos_ = data_;

    file.close();

    proccessed_ = true;

    return true;
}

bool RideReport::processData()
{
    if (!data_)
    {
        //std::cout << "Brak danych do przetworzenia." << std::endl;
        return false;
    }

    speedUpCount_ = 0;
    slowDownCount_ = 0;
    leftTurnCount_ = 0;
    rightTurnCount_ = 0;

    for (;*data_ != '\0'; data_++)
    {
        if (isEventCharacter(*data_))
        {
            switch (*data_)
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
    if(speedUpCount_ == 0 && slowDownCount_ == 0 && leftTurnCount_ == 0 && rightTurnCount_ == 0)
    {
        //std::cout<<"Brak poprawnych danych."<<std::endl;
        return false;
    }

    return true;
}

int RideReport::getSpeedUpCount()
{
    if(proccessed_)
        return speedUpCount_;

    return -1;
}

int RideReport::getSlowDownCount()
{
    if(proccessed_)
        return slowDownCount_;

    return -1;
}

int RideReport::getLeftTurnCount()
{
    if(proccessed_)
        return leftTurnCount_;

    return -1;
}

int RideReport::getRightTurnCount()
{
    if(proccessed_)
        return rightTurnCount_;

    return -1;
}

bool RideReport::saveCleanedData(const char * fileName)
{
    if (!data_)
    {
        //std::cout << "Brak danych do zapisu." << std::endl;
        return false;
    }

    std::ofstream file(fileName);
    if (!file)
    {
        //std::cout << "Blad tworzenia pliku: " << fileName << std::endl;
        return false;
    }
    // Remove unwanted characters and save cleaned data
    data_ = dataFirstPos_;
    for (;*data_ != '\0'; ++data_)
        if (isEventCharacter(*data_))
            file << *data_;
        

    file.close();

    return true;
}

bool RideReport::saveAsText(const char *fileName)
{
    if (!data_)
        return false;
        //std::cout << "Brak danych do zapisu." << std::endl;
        
    

    std::ofstream file(fileName);
    if (!file)
        return false;
     //std::cout << "Blad tworzenia pliku: " << fileName << std::endl;
        
    

    // Write report header
    file <<"Raport dla pliku:"<< std::endl;
    file << fileName_ << std::endl;
    file << "Data utworzenia:" << std::endl;
    file << creationDate_ << std::endl;
    file << "Czas utworzenia:" << std::endl;
    file << creationTime_ << std::endl;
    file << std::endl;

    // Write processed data
    file << "Przyśpieszenia: " << getSpeedUpCount() << std::endl;
    file << "Hamowania: " << getSlowDownCount() << std::endl;
    file << "Lewo: " << getLeftTurnCount() << std::endl;
    file << "Prawo: " << getRightTurnCount() << std::endl;

    file.close();

    return true;
}

bool RideReport::saveAsXML(const char *fileName)
{
    if (!data_)
    {
        //std::cout << "Brak danych do zapisu." << std::endl;
        return false;
    }

    std::ofstream file(fileName);
    if (!file)
    {
        //std::cout << "Blad tworzenia pliku: " << fileName << std::endl;
        return false;
    }

    // Write XML report
    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    file << "<report file=\"" << fileName_ <<"\" date=\""<< creationDate_ <<"\" time=\"" << creationTime_ << "\">" << std::endl;
    file << "<speed-up-count>" << getSpeedUpCount() << "</speed-up-count>" << std::endl;
    file << "<slow-down-count>" << getSlowDownCount() << "</slow-down-count>" << std::endl;
    file << "<left-turn-count>" << getLeftTurnCount() << "</left-turn-count>" << std::endl;
    file << "<right-turn-count>" << getRightTurnCount() << "</right-turn-count>" << std::endl;
    file << "</report>" << std::endl;

    file.close();

    return true;
}

bool RideReport::isEventCharacter(char c)
{
    return (c == 'a' || c == 'A' || c == 'b' || c == 'B' || c == 'l' || c == 'L' || c == 'r' || c == 'R');
}
