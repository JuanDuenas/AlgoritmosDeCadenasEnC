#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dateFormat (char date[]) {
    int day, month, year;
    char *months[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio","Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    int dateFormat (char date[]);

    day = atoi(strtok(date, "/"));
    month = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, "/"));

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        printf("Invalid date.\n");
        return 1;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11 && day == 31){
        printf("Invalid date.\n");
        return 1;
    }
    if(day > 28 && month == 2){
        printf("Invalid date.\n");
        return 1;
    }

    printf("\n\n%d de %s de %d\n\n", day, months[month - 1], year);
    return 0;
}

