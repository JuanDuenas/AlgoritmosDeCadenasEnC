#include <stdio.h>
#include <stdlib.h>

#include "romanNumeral.c"
#include "egomaniacalNumbers.c"

void menu();
void romanNumber();
void egomaniacal();

int main() {
    
    menu();

    return 0;
}

void menu(){
    char optionMenu;
    do{
        printf("Ingrese el indice de la accion que desea realizar\n1. Numero Romano\n4. Número Ególatra\n0. Salir\n");
        optionMenu = getchar();
        switch (optionMenu){
        case '1':
            romanNumber();
            break;
        case '4':
            egomaniacal();
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
