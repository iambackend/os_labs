#include <stdio.h>
#include <string.h>

int main(int argn, char** argc) {
    int n;
    sscanf(*(argc + 1), "%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int j = 0; j < 2 * i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
