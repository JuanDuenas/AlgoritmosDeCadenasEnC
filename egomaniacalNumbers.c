#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int egomaniacalNumbers(int number){

    int size = 0;
    int aux = number;
    int result = 0;

    while(number != 0){
        number/= 10;
        size ++;
    }
    number = aux;

    while (aux != 0){
        int digito = aux % 10;
        aux /= 10;

        result += pow(digito, size);
    }
    

    if(result == number){
        return 1;
    }

    return 0;
}