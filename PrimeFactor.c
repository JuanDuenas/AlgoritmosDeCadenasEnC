#include <stdio.h>
#include <stdlib.h>

int* getPrimeNumber(int, int*);

int** primeFactor(int num, int* lenght) {
    

    int size;
    int* primeNumbers = getPrimeNumber(num, &size);
    int** frequency = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++){
        frequency[i] = malloc(2 * sizeof(int));
        frequency[i][0] = primeNumbers[i];
        frequency[i][1] = 0;
    }
    free(primeNumbers);
    
    for (int i = 0; i < size; i++) {
        frequency[i][1] = 0;
    }
    
    int lastNum = num;
    int aux;

    for (int i = 0; i < size; i++){
        int salir = 0;
        do {
            aux = lastNum % frequency[i][0];
            if(aux == 0) {
                frequency[i][1]++;
               
                lastNum /= frequency[i][0];

            } else {
                salir = 1;
            }
        } while (salir == 0);

        if(lastNum == 1){
                break;
        }
    }
   
    *lenght = size;
    return frequency;
}

int* getPrimeNumber(int num, int* size) {
   
    int amount = 0;
  
        for(int i = 2; i <= num; i++) {
            int count = 0;

            for(int j = 2; j <= i; j++) {
                float res = i%j;
                if(res == 0){
                    count++;
                }
            }
            if(count == 1) {
                amount++;
            }
        }
    *size = amount;
    
    int* primeList = malloc(amount*sizeof(int));
    amount = 0;

        for(int i = 2; i <= num; i++) {
            int count = 0;

            for(int j = 2; j <= i; j++) {
                float res = i%j;
                if(res == 0){
                    count++;
                }
            }
            if(count == 1) {
                primeList[amount] = i;
                amount++;
            }
        }
    return primeList;
}