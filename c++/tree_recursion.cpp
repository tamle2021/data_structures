/*
Tree Recursion is just a phrase to describe when making a recursive call more than once in the recursive case.
Consider one solution to the above problem:

(define (count-stairs n)
  (cond [(= n 1) 1]
        [(= n 2) 2]
        [else (+ (count-stairs (- n 1))
                 (count-stairs (- n 2)) ]) ))

Breaking the procedure down, there are three parts to consider:
     1) There are two base cases, with two different outcomes.
          * If there is only one step to climb, there is only one way (by taking that step).
          * If there are two steps to climb, there is exactly two ways (1-step 1-step, or 2-step).
     2) Otherwise, the problem is made smaller by breaking it into two worlds.
          * In the first world, we take one step, and thus the number of steps is reduced by one.
          * In the second world, we take two steps, and thus the number of steps is reduced by two.
     3) Making two recursive calls to those smaller problems gives us the answer to those smaller problems, and adding up those
         gives us the answer to the original problem.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

void fun(int n) {
    if (n > 0) {
        printf("%d ",n);
        fun(n - 1);
        fun(n - 1);
    }
}

int main() {
    cout << "**** tree recursion ****" << endl;
    fun(4);

    return 0;
}
