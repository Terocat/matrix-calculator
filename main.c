#include <stdio.h>
#include "matrixmath.h"

int main()
{
    float matrix[4][4] = {
        { 2, -2, 4, -2 },
        { 2, 1, 10, 7 },
        { -4, 4, -8, 4 },
        { 4, -1, 14, 6 }
    };

    logMatrix(4, 4, matrix);
    printf(" =>\n");
    reduce(4, 4, matrix);
    logMatrix(4, 4, matrix);

    return 0;
}
