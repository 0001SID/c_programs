#include <stdio.h>
int main()
{
	int farh, cel;
	int upper, lower, step;
	upper = 300;
	lower = 0;
	step = 10;
	farh = 0;
	while(farh <= 300)
	{
		cel = (5*(farh - 32)/9);
		printf("%d\t%d\n", farh, cel);
		farh = farh + 1;
	}
	//system("pause");
	return(0);
}
