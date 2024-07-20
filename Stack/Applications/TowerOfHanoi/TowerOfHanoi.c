#include <stdio.h>

/*
         # The Great importance of Stack in OS

 * program main start, then calls function A, which calls B, the then B calls
   itself[recursion], which ends then A calls C which endn and return
   to a then a ends then return to the main

 * The OS saves all the parameters of every function and the return
   address in a stack, so that it returns in LIFO order
   the stack size is the depth of the recursion

 * All local paramaters and return address of each function has to be
   stored..[to keep track]

 * Return is LIFO order.
 * Space require is the hight of this tree it's the depth of the stack
   for ex: a call b which calls c and then c call its self 
	this is depth of four

 * When a function calls itself, this is recursion.
 * Still Stack is need , no difference between A call B, or B calls itsself

*/

/*  
 * Towers Of Hanoi it's a game of 19th Century
 * we're gonna write a funtion that writes down the steps needed
 * to move the disks from twoer 1 to tower 3 using tower 2 
 * with this rules:
 *  1 - only one disk should be moved at a time
 *  2 - No Disk should be placed on top of a smaller disk
 * 
 * using recursion to see how the operation system uses stack
*/

/* Solution Steps:
    1- To move the largest disk from 1 to 3, we have to move first 
       all others from 1 to 2!!
    2- move the largest from 1 to 3 .
    3- Move all others from 2 to 3 .
    
    moveDisks(count, start, finish, temp)

    in case of 7 disks:
     moveDisks(6, 1, 2, 3);
    "Move disk 7 from 1 to 3"
    MoveDisks (6, 2, 3, 1);

# Every recursive process consists of two parts:
    1- A smallest, base case that is processed without recursion
    2- A general method that reduces a particular case to one or more of the
    smaller cases, by making progress toward  reducing the 
    problem all the way to base  case.

    the number of the function calls is(steps) :
    1 + 2 + 4 + 8 = 1 + 2 + 2^count-1 = 2^count -1 geomatrice series
    can we write the function Move iteratively, not recursively?

in this case , we will find that we really need to build a stack, We will
find that the nature of the problem neccessitates that we first solve the 
problem at size count -1 then return back to the original problem, To 
return back we had to save it in a stack!

In such cases defining the problem recursivly is much better, since you
let the OS build the stack itslef which is much more efficient then your
stack.

However , there are some cases in which soling the problem iterativly is 
better if the eiterative alogrithm does not need a stack, Hence, solving
it recursively build an unnecessarily stack, which wastes memory and time
consumed in function return.  Example is the factorial.
check the factorial program ../factorial


*/


 void MoveDisks(int count, int start, int finish, int temp)
 {
     if(count > 0)
     {
         MoveDisks(count-1, start, temp,finish);
         printf("Move Disk %d from %d to %d\n", count, start, finish);
         MoveDisks(count-1, temp, finish, start);
     }
 }

// the same code but taking just 3 variable and the fourth is counted
// void MoveDisks(int count, int start, int finish)
// {
//    int other; 
//    if(count > 0)
//    {
//        other = 6 - (start + finish);
//        MoveDisks(count-1, start, other);
//        printf("Move Disk %d from %d to %d\n", count, start, finish);
//        MoveDisks(count-1, other, finish);
//    }
//}

// Using While Loop Instaed of If statment


//void MoveDisks(int count, int start, int finish, int temp)
// {
//     while(count>0)
//     {
//         MoveDisks(count-1, start, temp,finish);
//         printf("Move Disk %d from %d to %d\n", count, start, finish);
//         count--;
//         start = temp + start; 
//         temp = start - temp;
//         start = start - temp;
//     }
// }



int main()
{
    MoveDisks(5, 1, 3, 2);
    return 0;
}
