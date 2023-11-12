#include <stdio.h>
#include <stdlib.h>


double *productPoint(int vector1[], int vector2[], int size1, int size2) {
    if (size1 == size2) {
        double *point = (double *)malloc(sizeof(double));
        *point = 0.0;  
        printf("%.2f", (double)vector1[0] * vector2[0]);
        for (int i = 0; i < size1; i++) {
            if ((double)vector1[i] * vector2[i] == 0.00 && (vector1[i] != 0 || vector2[i] != 0)) {
                printf("entro aca");
                return NULL;
            }
            *point += (double)vector1[i] * vector2[i];
        }
        return point;
    }

    return NULL;
}
