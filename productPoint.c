#include <stdio.h>
#include <stdlib.h>

double *productPoint(int vector1[], int vector2[], int size1, int size2) {
    if (size1 == size2) {
        double *point = (double *)malloc(sizeof(double));
        *point = 0.0;  

        for (int i = 0; i < size1; i++) {
            *point += (double)vector1[i] * vector2[i];
        }
        printf("%.2f\n", *point);
        return point;
    }

    return NULL;
}
