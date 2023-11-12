#include <stdio.h>
#include <stdlib.h>

int getSumOfDivisors(int);

int verifyFriendlyNumbers(int a, int b) {

    int additionA = getSumOfDivisors(a);
    int additionB = getSumOfDivisors(b);

    if(additionA == b && additionB == a) {
        return 1;
    } else {
        return 0;
    }
}

int getSumOfDivisors(int num) {
    int addition = 0;

    for(int i =  1; i < num; i++) {
        int res = num % i;
        if(res == 0) {
            addition += i;
        }
    }
    return addition;
}