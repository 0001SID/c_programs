//Traversing linked list forward and backward using recursion

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* head = NULL;
struct node* current = NULL;

void insert(struct node *a,int data){
	current = a;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(head != NULL){
		while(current->next != NULL){
			current = current->next;
		}
		
		current->next = temp;
	}
	else{
		head = temp;
	}
	temp->next = NULL;
	temp->data = data;

}

void forwardPrint(struct node *a){
	if(a == NULL) return;
	else{
		printf("%d ",a->data);
		a = a->next;
		forwardPrint(a);
	}

}

void backwardPrint(struct node *a){
	if(a == NULL) return;
	else{
		backwardPrint(a->next);
		printf("%d ",a->data );
	}
}


void view(struct node *a){
	current = a;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
}

int check_element(struct node *a){
	int count = 0;
	if(a == NULL){
		return 0;
	}else{
		while(a->next != NULL){
			a = a->next;
			count++;
		}
		return count+1;
	}
	
}

int main(){
	int what,elements,data,total;
	char res;

	printf("\n\n\t\tA PROGRAM OF SIMPLE LINKED LIST DATA STRUCTURE\n");

	do{
		printf("\n1. Insert\n2. Forward Traverse\n3. Backward Traverse\n\nYour Response: ");
		scanf("%d",&what);
		elements = check_element(head);
		fflush(stdin);

		if (what == 1)
		{
			printf("\nHow many numbers you want to add: ");
			scanf("%d",&total);
			for(int i = 0; i<total; i++){

				elements = check_element(head);

				printf("\nYou have %d records",elements );
				printf("\nEnter the value: ");
				scanf("%d",&data);
				fflush(stdin);
				insert(head,data);
				printf("\nUpdated Record:\n");
				view(head);
			}
		}

		else if(what == 2){
			forwardPrint(head);
		}
		else if(what == 3){
			backwardPrint(head);
		}

printf("\n\nWant to do some more function? (y/n): ");
		scanf("%c",&res);
	}while(res == 'y');
	return 0;
}