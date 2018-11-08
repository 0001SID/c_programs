#include<stdio.h>
main()
{
	int c, nc, nl, nw, state;
	#define IN 1
	#define OUT 0
	state = OUT;
	nc = nl = nw = OUT;
	while((c = getchar()) !=EOF)
	{
		++nc;
		if( c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if( state == OUT)
		{
			state = IN;
			++nw;
			printf("%5d%5d%5d\n", nc, nl, nw);
		}
	}
}
	
