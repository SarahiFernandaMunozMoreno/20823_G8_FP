#include "mimath.h"
#include <stdio.h>

float division(float a, float b) {
    if (b == 0) {
        printf("Error: Division por cero\n");
        return 0;
    }
    return a / b;
}
