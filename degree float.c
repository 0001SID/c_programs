#include <stdio.h>
#include <stdlib.h>
int main()
{
    float fahr, cel;
    float lower, upper, step;
    lower = -270;
    step = 10;
    upper = 270;
        fahr = lower;
        while (fahr <= upper)
            {
            cel = (5.0/9.0)*(fahr-32);
            printf("%10.0f \t %10.2f\n", fahr, cel);
            fahr = fahr + step;
            }
	system("pause");
	return(0);
}
