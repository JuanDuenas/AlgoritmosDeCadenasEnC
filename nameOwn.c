#include <stdio.h>


void ownName(char name[]){
    for (int i = 0; i < 50; i++)
    {
        if(i == 0 && name[i] != ' '){
            name[i] = toupper(name[i]);
        }else if(name[i] == ' '){
            name[i+1] = toupper(name[i+1]);
        }
    }

}