#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RomanNumeral.c"
#include "EgomaniacalNumbers.c"
#include "ProductPoint.c"
#include "Date.c"
#include "MagicMatrix.c"
#include "NameOwn.c"
#include "PrimeFactor.c"
#include "FriendlyNumbers.c"
#include "MatrixMultiplication.c"

void menu();
void romanNumber();
void egomaniacal();
void productP();
void Date();
void magicMatrix();
void nameOwn();
void managePrimeFactor();
void friendlyNumbers();
void matrixMultiplication();

int main() {
    
    menu();

    return 0;
}

void menu(){
    char optionMenu;
    do{
        printf("Ingrese el indice de la accion que desea realizar\n1. Numero Romano\n2. Factores primos\n3. Nombre propio"
        "\n4. Numero Egolatra\n5. Numeros Amigos\n6. Fecha\n7. Producto punto \n8. Multiplicacion de matrices \n9. Matriz magica\n0. Salir\n");
        optionMenu = getchar();
        switch (optionMenu){
        case '1':
            romanNumber();
            break;
        case '2':
            managePrimeFactor();
            break;
        case '3':
            nameOwn();
            break;
        case '4':
            egomaniacal();
            break;
        case '5':
            friendlyNumbers();
            break;
        case '6':
            Date();
            break;
        case '7':
            productP();
            break;
        case '8':
            matrixMultiplication();
            break;
        case '9':
            magicMatrix();
            break;
        case '0':
            printf("Ejecución terminada");
            break;
        default:
            break;
        }
        getchar();
    }while(optionMenu != '0');
}

void matrixMultiplication() {
    int ax, ay, bx, by;
    char out;

    do {
        printf("Matriz A \nEscriba las filas: ");
        if(scanf("%d", &ax) == 1) {
            printf("\nEscriba las columnas: ");
            if(scanf("%d", &ay) == 1) {
                printf("Matriz B \nEscriba las filas: ");
                if(scanf("%d", &bx) == 1) {
                    printf("\nEscriba las columnas: "); 
                    if(scanf("%d", &by)  == 1) {
                        if(ay == bx) {
                            multiplication(ax,ay,bx,by);
                        } else {
                            printf("Las matrices no se pueden multiplicar.");
                        }
                    } else {
                        printf("Entrada invalida intente nuevamente.\n");
                        scanf("%c", &out);
                    }
                } else {
                    printf("Entrada invalida intente nuevamente.\n");
                    scanf("%c", &out);
                }
            } else {
                printf("Entrada invalida intente nuevamente.\n");
                scanf("%c", &out);
            }
        } else {
            printf("Entrada invalida intente nuevamente.\n");
            scanf("%c", &out);
        }
        printf("\n1. Volver\n2. Continuar\n");
        scanf("%c", &out);
        scanf("%c", &out);
    } while (out != '1');
}

void friendlyNumbers(){
    int a,b;
    char out;

     do{
        printf("\nEscriba el primer numero: ");
        if(scanf("%d",&a) == 1) {
            printf("\nEscriba el segundo numero: ");
            if(scanf("%d",&b) == 1) {
                if(verifyFriendlyNumbers(a,b) == 1) {
                    printf("Verdadero. Los numeros %d y %d, son amigos.", a,b);
                } else {
                    printf("Falso. Los numeros %d y %d, NO amigos.", a,b);
                }
            } else {
            printf("Entrada invalida intente nuevamente.\n");
            scanf("%c", &out);
            }
        } else {
            printf("Entrada invalida intente nuevamente.\n");
            scanf("%c", &out);
        }

        printf("\n1. Volver\n2. Continuar\n");
        scanf("%c", &out);
        scanf("%c", &out);
     } while(out != '1');
}

void managePrimeFactor() {
    int num;
    char out;

     do{
        printf("\nEscriba un numero para hallar sus factores primos: ");
        if(scanf("%d",&num) == 1) {
            if(num<0){
                num = abs(num);
            }

            if(num == 0 || num == 1) {
                printf("\nEl numero %d no posee factores primos.\n",num);
            } else {
                int size;
                int** frequency = primeFactor(num, &size);
            
                printf("\nEl numero %d se conforma de los siguientes factores primos:\n",num);
                for (int i = 0; i < size; i++) {
                    if(frequency[i][1] != 0) {
                        printf("(%d^%d) ",frequency[i][0],frequency[i][1]);
                    }
                }
            }

        } else {
            printf("Entrada invalida intente nuevamente.\n");
            scanf("%c", &out);
        }

        printf("\n1. Volver\n2. Continuar\n");
        scanf("%c", &out);
        scanf("%c", &out);
     } while(out != '1');
}

void magicMatrix() {
    int order;
    char out;
    do{
        printf("Introduzca el numero de orden de la matriz: ");
        scanf("%i",&order);
        generateSquare(order);
        printf("1. Volver\n2. Continuar\n");
        scanf("%c", &out);
        scanf("%c", &out);
    }while(out != '1');
}

void nameOwn() {
    char name[50];
    char out;
    do{
        printf("Introduzca su nombre: ");
        fflush(stdin);
        fgets(name,50,stdin);
        ownName(name);
        printf("%s",&name);

        printf("1. Volver\n2. Continuar\n");
        scanf("%c", &out);
    }while(out != '1');
}

void Date() {
    char date[11];
    char out;
    do{
        printf("Introduzca una fecha (dd/mm/aaaa): ");
        scanf("%s",&date);
        dateFormat(date);
        printf("1. Volver\n2. Continuar\n");
        scanf("%c", &out);
        scanf("%c", &out);
    }while(out != '1');
}

void romanNumber() {
    int number;
    char out;
    do{
        printf("Ingrese un numero entre 1 y 3000: ");

        if(scanf("%d", &number) == 1){
            printf("%s\n", romanNumeral(number));
            printf("Para regresar al menu principal digite 1, para convertir otro numero digite cualquier tecla:  ");
            scanf("%c", &out);
            scanf("%c", &out);
        }else{
            printf("Entrada no valida intente d nuevo\n");
            scanf("%c", &out);
        }

    }while(out != '1'); 
}

void egomaniacal() {
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
            printf("Para regresar al menu principal digite 1, para ingresar otro numero digite cualquier tecla:  ");
            scanf("%c", &out);
            scanf("%c", &out);
        }else{
            printf("Entrada no valida intente d nuevo\n");
            scanf("%c", &out);
        }

    }while(out != '1'); 
}

void productP() {
    char out;
    getchar();
    do{
        
        int sizeA = 0;
        int sizeB = 0;
        char inputA[500]; 
        char inputB[500]; 

        printf("Ingrese los numeros del primer array separados por espacio: ");
        fgets(inputA, sizeof(inputA), stdin);
        fflush(stdin);
        inputA[strcspn(inputA, "\n")] = '\0';
        for (int i = 0; inputA[i] != '\0'; ++i) {
            if (inputA[i] != ' ') {
                sizeA++;
            }
        }
        
        printf("Ingrese los numeros del segundo array separados por espacio: ");
        fgets(inputB, sizeof(inputB), stdin);
        fflush(stdin);
        inputB[strcspn(inputB, "\n")] = '\0';
        for (int i = 0; inputB[i] != '\0'; ++i) {
            if (inputB[i] != ' ') {
                sizeB++;
            }
        }

        int vectorA[sizeA];
        char *number = strtok(inputA, " ");
        for(int i = 0; i < sizeA; i ++){
            vectorA[i] = strtol(number, &number, 10);
            number = strtok(NULL, " ");
        }
      
        int vectorB[sizeB];
        char *token = strtok(inputB, " ");
        for(int i = 0; i < sizeB; i ++){
            vectorB[i] = strtol(token, &token, 10);
            token = strtok(NULL, " ");
        }

        double *rta = productPoint(vectorA, vectorB, sizeA, sizeB);
        if(rta != NULL){
            printf("El producto punto de los dos vectores es: %.2f\n", *rta);
        }else{
            printf("No se puede obtener el producto punto de los dos vectores\n");
        }
        printf("Para regresar al menu principal digite 1, para realizar nuevamente la operacion producto punto digite cualquier tecla:  ");
        scanf("%c", &out);
        getchar();
    }while(out != '1'); 
}
