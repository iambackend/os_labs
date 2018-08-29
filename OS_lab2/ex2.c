#include <stdio.h>
#include <string.h>

int main() {
    char s[255];
    gets(s);
    for(int i = strlen(s) - 1; i >= 0; i--){
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}