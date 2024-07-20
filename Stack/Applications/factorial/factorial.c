#include <stdio.h>

// using the recursion
int FactorialRercursion(int n)
{
    return n == 0 ? 1 : (n*FactorialRercursion(n-1));
}

/* why recursion while you can use just loop */
// int FactorialLoop(int n)
// {
//     int product = 1;
//     for(int i = 2 ; i <= n ; i++)
//         product*=i;
// 
//     return product;
// }

// Saving one variable iterat usingg just the paramater n
int FactorialLoop(int n)
{
    int product = 1;
    for(product=1 ; n>1 ; n--)
        product*=n;

    return product;
}
// NOTICE: the decrement n is just a copy; so don't worry (:

/*
 * in this case we don't need recursion
 * we  wast the time of function calls and returns
 * don't forget the stack built by the os to keep track of funciton calls
 * in This case, Absolutely the iterative version is faster and more
 * economic in memory utilization
 * the recursion tree is simply a chain, which mean that designin
 * the algorithm does not need recursion
 *  
  	 _
	|_|3!
	 |
	 |
	|_|2!   no branching 
	 | 
	 |
	|_|1!

Here the complexity is the same O(n) but the time of each in not the same
because the stack that is buid by the operation system take time to 
keep truck and save returning address and variable of each call

More Extreme example for un-necessary recursion, the Fibonacci function;
although many thinks that it is the best example for recursion
check the Fibonacci program ../fibonacci

*/


int main()
{
    int n = 5 ;
    printf("Factorial %d is : %d using recursion\n", n, FactorialRercursion(n));
    printf("Factorial %d is : %d using loop\n", n, FactorialLoop(n));
    return 0;
}
