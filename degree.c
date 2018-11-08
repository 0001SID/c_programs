#include <stdio.h>
void main()
{

    int fahr, cel;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 10;
    fahr = lower;
    printf("CONVERSION OF TEMPETURE\n");
    printf("\n");
    while(fahr <= upper) {
    cel = 5 * ( fahr - 32 ) / 9;
    printf("%d\t%d\n", fahr, cel);
    fahr = fahr + step;
    }
 }
