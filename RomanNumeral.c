#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *romanNumeral(int number){

    char *roman = (char *)malloc(60);
    roman[0] = '\0';
    if(number < 0){
        strcpy(roman, "El numero debe ser mayor a 0");
    }else{
        int units, tens, hundreds, unitsThousands;

        units = number % 10;           number /= 10;
        tens = number % 10;            number /= 10;
        hundreds = number % 10;        number /= 10;
        unitsThousands = number % 10;  number /= 10;

        if(unitsThousands >= 3 && hundreds > 0){
            strcpy(roman, "El numero debe ser menor de 3000 para convertirlo a romano");
        }else{
            switch (unitsThousands) {
                case 1:
                    strcat(roman, "M");break;
                case 2:
                    strcat(roman, "MM");break;
                case 3:
                    strcat(roman, "MMM");break;
                default:
                    break;
            }
            switch (hundreds)
            {
                case 1:
                    strcat(roman, "C");break;
                case 2:
                    strcat(roman, "CC");break;
                case 3:
                    strcat(roman, "CCC");break;
                case 4:
                    strcat(roman, "CD");break;
                case 5:
                    strcat(roman, "D");break;
                case 6:
                    strcat(roman, "DC");break;
                case 7:
                    strcat(roman, "DCC");break;
                case 8:
                    strcat(roman, "DCCC");break;
                case 9:
                    strcat(roman, "CM");break;
                default:
                    break;
            }
            switch (tens) {
                case 1:
                    strcat(roman, "X");
                    break;
                case 2:
                    strcat(roman, "XX");
                    break;
                case 3:
                    strcat(roman, "XXX");
                    break;
                case 4:
                    strcat(roman, "XL");
                    break;
                case 5:
                    strcat(roman, "L");
                    break;
                case 6:
                    strcat(roman, "LX");
                    break;
                case 7:
                    strcat(roman, "LXX");
                    break;
                case 8:
                    strcat(roman, "LXXX");
                    break;
                case 9:
                    strcat(roman, "XC");
                    break;
                default:
                    break;
            }

            switch (units) {
                case 1:
                    strcat(roman, "I");
                    break;
                case 2:
                    strcat(roman, "II");
                    break;
                case 3:
                    strcat(roman, "III");
                    break;
                case 4:
                    strcat(roman, "IV");
                    break;
                case 5:
                    strcat(roman, "V");
                    break;
                case 6:
                    strcat(roman, "VI");
                    break;
                case 7:
                    strcat(roman, "VII");
                    break;
                case 8:
                    strcat(roman, "VIII");
                    break;
                case 9:
                    strcat(roman, "IX");
                    break;
                default:
                    break;
            }
        }
    }
    return roman;
}