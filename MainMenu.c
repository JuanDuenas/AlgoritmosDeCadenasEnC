#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "romanNumeral.c"
#include "egomaniacalNumbers.c"
#include "productPoint.c"

void menu();
void romanNumber();
void egomaniacal();
void productP();

int main() {
    
    menu();

    return 0;
}

void menu(){
    char optionMenu;
    do{
        printf("Ingrese el indice de la accion que desea realizar\n1. Numero Romano\n4. Numero Egolatra\n7.Producto punto\n0. Salir\n");
        optionMenu = getchar();
        switch (optionMenu){
        case '1':
            romanNumber();
            break;
        case '4':
            egomaniacal();
            break;
        case '7':
            productP();
            break;
        default:
            break;
        }
        getchar();
    }while(optionMenu != '0');
}

void romanNumber(){
    int number;
    char out;
    do{
        printf("Ingrese un numero entre 1 y 3000: ");

        if(scanf("%d", &number) == 1){
            printf("%s\n", romanNumeral(number));
            printf("Para regresar almenu principal digite 1, para convertir otro numero digite cualquier techa:  ");
            scanf("%c", &out);
            scanf("%c", &out);
        }else{
            printf("Entrada no valida intente d nuevo\n");
            scanf("%c", &out);
        }

    }while(out != '1'); 
}

void egomaniacal(){
    int number;
    char out;
     do{
        printf("Ingrese un numero: ");

        if(scanf("%d", &number) == 1){
            if(egomaniacalNumbers(number)){
                printf("Verdadero, el numero %d es un numero egolatra\n", number);
            }else{
                printf("Falso, el numero %d  NO es un numero egolatra\n", number);
            }
            printf("Para regresar al menu principal digite 1, para ingresar otro numero digite cualquier techa:  ");
            scanf("%c", &out);
            scanf("%c", &out);
        }else{
            printf("Entrada no valida intente d nuevo\n");
            scanf("%c", &out);
        }

    }while(out != '1'); 
}

void productP(){
    char out;
    getchar();
    do{
        
        int sizeA = 0;
        int sizeB = 0;
        char inputA[500]; 
        char inputB[500]; 

        printf("Ingrese los numeros del primer array separados por espacio: ");
        fgets(inputA, sizeof(inputA), stdin);
        inputA[strcspn(inputA, "\n")] = '\0';
        for (int i = 0; inputA[i] != '\0'; ++i) {
            if (inputA[i] != ' ') {
                sizeA++;
            }
        }
        int vectorA[sizeA];
        char *number = strtok(inputA, " ");
        for(int i = 0; i <= sizeA; i ++){
            vectorA[i] = strtol(number, &number, 10);
            number = strtok(NULL, " ");
        }
        for(int i = 0; i < sizeA; i ++){
            printf("%d", vectorA[i]);
        }
      
        printf("Ingrese los numeros del segundo array separados por espacio: ");
        fgets(inputB, sizeof(inputB), stdin);
        inputB[strcspn(inputB, "\n")] = '\0';
        for (int i = 0; inputB[i] != '\0'; ++i) {
            if (inputB[i] != ' ') {
                sizeB++;
            }
        }
        int vectorB[sizeB];
        char *token = strtok(inputB, " ");
        for(int i = 0; i <= sizeB; i ++){
            vectorB[i] = strtol(token, &token, 10);
            token = strtok(NULL, " ");
        }

        for(int i = 0; i < sizeA; i ++){
            printf("%d", vectorA[i]);
        }
        printf("\n");
        for(int i = 0; i < sizeB; i ++){
            printf("%d", vectorB[i]);
        }

        printf("El producto punto de los dos vectores es: %.2f\n", *productPoint(vectorA, vectorB, sizeA, sizeB));
        printf("Para regresar almenu principal digite 1, para realizar nuevamente la operacion producto punto digite cualquier techa:  ");
        scanf("%c", &out);
        getchar();
    }while(out != '1'); 
}
