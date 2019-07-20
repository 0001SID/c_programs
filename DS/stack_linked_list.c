#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
void push(int);
void pop();
int topVal();
int isEmpty();


struct node* createNode();
struct node* top = NULL;


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

struct node* createNode(){
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp->next = NULL;
	return temp;
}

void push(int data){
	struct node* temp = createNode();
	temp->data = data;
	temp->next = top;
	top = temp;
}

void pop(){
	struct node *temp = top;
	top = top->next;
	free(temp);
}

int topVal(){
	return top->data;
}

int isEmpty(){
	if(top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

