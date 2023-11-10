#include <stdio.h>
#include <stdlib.h>

#include "romanNumeral.c"

void menu();
void romanNumber();

int main() {

    menu();

    return 0;
}

void menu(){
    char optionMenu;
    do{
        printf("Ingrese el indice de la accion que desea realizar\n1. Numero Romano\n0. Salir");
        optionMenu = getchar();
        switch (optionMenu){
        case '1':
            romanNumber();
            break;
        
        default:
            break;
        }
    }while(optionMenu != '0');
}

void romanNumber(){
    int number;
    char out;
    do{
        printf("Ingrese un numero: ");
        scanf("%d", &number);
        printf("%s\n", romanNumeral(number));
        printf("Para regresar almenu principal digite 1, para convertir otro numero digite cualquier techa:  ");
        scanf("%c", &out);
        scanf("%c", &out);

    }while(out != '1');
    
}