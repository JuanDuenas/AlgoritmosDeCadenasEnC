#include <string.h>
#include <ctype.h>

void ownName(char name[]){
    int space = 1;
    for(int i = 0; i < strlen(name); i++) {
        if(space && isalpha(name[i])) {
            name[i] = toupper(name[i]);
            space = 0;
        } else if (isspace(name[i])) {
            space = 1;
        } else {
            name[i] = tolower(name[i]);
        }
    }
}