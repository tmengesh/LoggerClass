#include "testclass.h"
#include "fibonacciseries.h"
#include "logger.h"
#include "assert.h"

FibonacciSeries fs;

bool TestClass::zeroAsInput()
    {
        if (fs.fib(0)==0)
            return true;
    }
bool TestClass::oneAsInput()
    {
        if (fs.fib(1)==0)
            return true;
    }
 bool TestClass::getFibResult()
    {
     if (fs.fib(10)==55)
         return true;
    }



