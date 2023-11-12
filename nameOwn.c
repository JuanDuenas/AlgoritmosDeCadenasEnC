#include <stdio.h>

char name[50];

char ownName(char name[]);

int main(){
    printf("Add your name: ");
    fgets(name,50,stdin);

    ownName(name);
    printf("%s",&name);



    return 0;
}

char ownName(char name[]){
    for (int i = 0; i < 50; i++)
    {
        if(i == 0 && name[i] != ' '){
            name[i] = toupper(name[i]);
        }else if(name[i] == ' '){
            name[i+1] = toupper(name[i+1]);
        }
    }
    
    return name;
}