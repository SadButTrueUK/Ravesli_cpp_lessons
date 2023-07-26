#include <iostream>
#include <cmath>

class IErrorLog
{
public:
    virtual void writeError(const char *errorMessage) = 0;
    virtual ~IErrorLog() {}; 
};

class FileErrorLog : public IErrorLog
{
    public:
        virtual void writeError(const char *errorMessage)
        {
            std::cout << "FileErrorLog::writeError\n";
        }
        virtual ~FileErrorLog() {std::cout << "FileErrorLog::~FileErrorLog()\n";}
};

class ScreenErrorLog : public IErrorLog
{
    public:
        virtual void writeError(const char *errorMessage)
        {
            std::cout << "ScreenErrorLog::writeError\n";
        }
        virtual ~ScreenErrorLog() {std::cout << "ScreenErrorLog::~ScreenErrorLog()\n";}
};

double mySqrt(double value, IErrorLog &log)
{
    if (value < 0.0)
    {
        log.writeError("Tried to take square root of value less than 0\n");
        return 0.0;
    }
    else
        return sqrt(value);
}

int main()
{
    ScreenErrorLog s;
    FileErrorLog f;
    IErrorLog& rS = s;
    IErrorLog& rF = f;
    
    mySqrt(-125.32, rS);
    mySqrt(-1356.32, rF);
    return 0;
}
