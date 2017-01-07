#include "Logger.h"

//Initalize static varaibles
bool Logger::singtonInitalized = false;
Logger* Logger::instanceLog = NULL;

//Log File constructor
Logger::Logger()
{
    logFile.open("../logDirectory/log.txt", ios::app); //Open log file for writing (append text to an existing content)
}

//Closing log file in de-contructor
Logger::~Logger()
{
    logFile.close(); //Close our log file
}

//Log DEBUG
void Logger::Log(string str)
{
    logFile << "~ <DEBUG> ~ : " + str;
}

//Log WARNING
void Logger::LogWarning(string str)
{
    logFile << "~ <WARNING> ~ : " + str;
}

//Log ERROR
void Logger::LogError(string str)
{
    logFile << "~ <ERROR> ~ : " + str;
}

//Log TEST
void Logger::LogUnitTest(string str)
{
    logFile << "~ <TEST> ~ : " + str;
}

//Singleton implementation returns a pointer to log class
Logger* Logger::getInstance()
{
    if( !singtonInitalized )
    {
        //Get an instance of logger
        instanceLog = new Logger();
        singtonInitalized = true;
    }

    return instanceLog;
}

//Cleanup instance
void Logger::freeSingleton()
{
    if( instanceLog != NULL )
    {
        delete instanceLog;
        instanceLog = NULL;

        singtonInitalized = false;
    }
}
