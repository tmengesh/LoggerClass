#ifndef _LOGGER_
#define _LOGGER_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Logger class

    Logger class is using singletone design pattern

*/
class Logger
{
    private:
        fstream logFile; //Log file
        static bool singtonInitalized;
        static Logger* instanceLog; //The singleton to return

    public:
        //Constructor and destructor
        Logger();
        ~Logger();

        //Get an instance of singleton
        static Logger* getInstance();

        //Free up our singleton.
        void freeSingleton();

        //Log message types
        void Log(string); //Log debug
        void LogWarning(string); // Log warning
        void LogError(string); // Log error
        void LogUnitTest(string); // Log unit test results
};

#endif
