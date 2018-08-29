#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("int size and max value:\n%d %d\n", sizeof(a), a);
    printf("float size and max value:\n%d %f\n", sizeof(b), b);
    printf("double size and max value:\n%d %lf\n", sizeof(c), c);
    return 0;
}