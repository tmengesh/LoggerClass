/*
      Tewodros Mengesha
      teddy1496@yahoo.com
      0445487579
      01 Jan 2017
      C++ Looger Class example. The console program calculates and display FibonacciSeries
      of a given number on console output window for users at the same time it  logs debug,
      warning and error messages along with time stamp to given txt file.

  */


#include <iostream>
#include "Logger.h"
#include "fibonacciseries.h"
#include "testclass.h"
#include <string>
#include <ctime>
using namespace std;

/*
    FibonacciSeries class have one function "fib" which accepts int as user input and return
*/

int main()
{

    FibonacciSeries fSeries;
    TestClass t;
    // current date/time based on current system
    time_t now = time(0);

    // convert date/time to string
    string dt = ctime(&now);

    //Log() is fuction used to log DEBUG info
    Logger::getInstance()->Log(" ----------------------------------------------------- \n");
    Logger::getInstance()->Log(dt + " Starting the application....\n");

    int n,i=1,result=0;

        cout<<"Enter positive integer  ";
        cin>>n;
        if(n<0)
        {
            cout<<"Error please enter positive integer \n";

            //LogError() is fuction used to log ERROR message
            Logger::getInstance()->LogError(dt + " Wrong input!!! user has entered " + std::to_string(n) + " while expecting positive integer\n");
        }
        else
        {
            if(t.zeroAsInput())
                Logger::getInstance()->LogUnitTest(dt + " 0 as Input test - PASS \n");
            if(t.oneAsInput())
                Logger::getInstance()->LogUnitTest(dt + " 1 as Input test - PASS \n");
            if(t.getFibResult())
                Logger::getInstance()->LogUnitTest(dt + " 10 as Input test - PASS \n");

            Logger::getInstance()->Log(dt + " User input was " +  std::to_string(n) + "\n");

             cout<<"\nFibonacci Series is as follows\n";
             while(i<=n)
             {
                 cout<<" "<<fSeries.fib(i);
                 result =  fSeries.fib(i);
                 i++;
              }

            cout<<"\n n(" + std::to_string(n) + ") is " + std::to_string(result) + " \n ";
            Logger::getInstance()->Log(dt + "Result is " +  std::to_string(result) + "\n");

            //LogWarning() is fuction used to log WARNING message
            Logger::getInstance()->LogWarning(dt + " Calculation is over \n");
        }


    //Clean things up
    Logger::getInstance()->freeSingleton();

    return 0;
}
