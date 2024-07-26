#include <stdio.h>

/* 
# the Mathematical definition of the fibonacci sequence
*
*           | 0                     if n = 0 (base condition)
*   f(n) =  | 1                     if n = 1 (base condition)
*           | f(n-1) + f(n-2)       if n >=2 
*
*   Ahthough the mathematical form of the function itself is 
*   recursive ( this is what tempts some people to code it recursively)
*   However ther is an iterative algorithm for solving it
*
*   The common problems with unnessarily stack build by the os are:
*   - waste of time
*   - wase of memory
*   for this case we have another seriouse problem
*   which is needlessly repeating the Fibonnacci of many numbers
*   for example fib(10) will caluclate fib(9) fib(8)
*   and when we caluclate fib(9) we caluclate fib(8) and so on
*   this make the complexity exponential O(e^n)
*   
*   let's make the complexity just  O(n)
*
*
*
*/ 

// Recursion Solution With complexity O(e^n)
int fibonacciRecursion(int n)
{
    if(n <= 0)
        return 0;
    else if(n ==1)
        return 1;
    else
        return (fibonacciRecursion(n-1) + fibonacciRecursion(n-2));
}

// Iterative and simple Solution and faster
// here the complexity is O(n)

// int fibonacciLoop(int n)
// {
//     if(n <=0)
//         return 0;
//     else if(n ==1)
//         return 1;
//     int secondPrevious= 0;
//     int previous = 1;
//     int current;
//     for(int i = 2 ; i <=n; i++)
//     {
//         current = secondPrevious + previous;
//         secondPrevious = previous;
//         previous = current;
//     }
//     return current;
// }


// smarter solution remove one varialbe
int fibonacciLoop(int n)
{
    if(n <=0)
        return 0;
    else if(n ==1)
        return 1;
    int secondPrevious= 0;
    int previous = 1;
    for(int i = 2 ; i <=n; i++)
    {
        previous = previous + secondPrevious;
        secondPrevious = previous - secondPrevious;
    }
    return previous;
}

int main()
{
    int n = 7;
    printf("fibonacciLoop(%d) = %d\n",n,fibonacciLoop(n));
    printf("fibonacciRecursion(%d) = %d\n",n,fibonacciRecursion(n));
    return 0;
}
