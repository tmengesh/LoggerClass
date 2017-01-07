#include "fibonacciseries.h"

int FibonacciSeries::fib(int n)
{
    if(1 == n || 2 == n)
       { return 1;}
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

