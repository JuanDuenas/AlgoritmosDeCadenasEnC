#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** fillMatrix(int, int);
void showMatrix(int**, int, int);

void multiplication(int ax, int ay, int bx, int by) {

    if(ay == bx) {
        int** mtrxA = fillMatrix(ax, ay);
        int** mtrxB = fillMatrix(bx, by);

        printf("\n-------Matriz A-------\n");
        showMatrix(mtrxA, ax, ay);
        printf("\n-------Matriz B-------\n");
        showMatrix(mtrxB, bx, by);

        int** resultMtrx = (int**) malloc(ax * sizeof(int*));
        for(int i = 0; i < ax; i++) {
            resultMtrx[i] = (int*) malloc(by * sizeof(int));
        }


        for(int i = 0; i < ax; i++){
            for(int j = 0; j < by; j++){
                resultMtrx[i][j] = 0;
            }
        }

        for(int i = 0; i < ax; i++){
            for(int j = 0; j < by; j++){
                for(int k = 0; k < ay; k++){
                        resultMtrx[i][j] += mtrxA[i][k]*mtrxB[k][j];
                }
            }
        }
        printf("\n-------RESULTADO-------\n");
        printf("\n-------[%d * %d]-------\n",ax,by);
        showMatrix(resultMtrx, ax,by);
         
    } 
}

void showMatrix(int** mtrx, int x, int y) {
    for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++){
                printf("{ %d }",mtrx[i][j]);
            }
            printf("\n");
    }
}

int** fillMatrix(int x, int y) {
    int** mtrx = (int**) malloc(x * sizeof(int*));
    for(int i = 0; i < x; i++) {
       mtrx[i] = (int*) malloc(y * sizeof(int));
    }

    srand(time(0));

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++){
            mtrx[i][j] = rand() % 10;
        }
    }
    return mtrx;
}