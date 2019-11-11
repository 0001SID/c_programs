#include <stdio.h>
int main(){
	int value;
	printf("Program to generate random number in range 1 to 6\n");
	srand(time(0));
	for(int i = 0; i< 10; i++){
		value = (rand()%6)+1;
		printf("Round %d dice value = %d\n",i+1,value);
	}
	return 0;
}