#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop();
int topVal();
int isEmpty();
int a[50],top = -1;

int main(){
	int what,n,val;
	char res;

	printf("\n\n\t\tA PROGRAM OF SIMPLE STACK DATA STRUCTURE WITH ARRAY\n");

	do{
		printf("\n1. Push\n2. Pop\n3. Top\n\nYour Response: ");
		scanf("%d",&what);
		fflush(stdin);
		if(what == 1){
			printf("How many numbers you want to push: \n");
			scanf("%d",&n);
			if(n > 0){
				for(int i = 0 ; i < n ; i++){
					printf("Enter value: ");
					scanf("%d",&val);
					push(val);
				}
			}

		}
		else if(what == 2){
			if(!isEmpty()){
				pop();
			}
			else{
				printf("Stack is empty\n");
			}
		}
		else if(what == 3){
			if(!isEmpty()){
				printf("Top value = %d\n",topVal());
			}
			else{
				printf("Stack is empty\n");
			}
		}

		printf("\n\nWant to do some more function? (y/n): ");
		fflush(stdin);
		scanf("%c",&res);

	}while(res == 'y');
	
}

void push(int val){
	top++;
	a[top] = val;
}

void pop(){
	top--;
}

int topVal(){
	return a[top];
}

int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}