#include<stdio.h>
main()
{
	int c, nc, nl, nw, state;
	#define IN 1
	#define OUT 0
	state = OUT;
	nc = nl = nw = 0;
	while( (c = getchar()) !=EOF)
	{
		++nc;
		if( c == '\n')
			++nl;
		if(c == ' '|| c == '\n' ||c == '\t')
			state = OUT;
		else if(state == OUT)
		{
			state = IN;
			++nw;
			printf("%5d%5d%5d\n", nc, nl, nw);
		}
	}
}

/* In this program there is a problem that if you type just one word then the program
give a wrong result. If you give a sentence then the program gives a correct result bt
ir you give an another sentence one more time in input then the total character and word
number sum up with the number of previous result. so thats the problem in this program*/
