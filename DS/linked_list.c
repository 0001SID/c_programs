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

void reverse(struct node* a){
	struct node* next = NULL;
	struct node* pre = NULL;
	current = a;
	while(current != NULL){
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	head = pre;
}

void view(struct node *a){
	current = a;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
}

void insert_sp(struct node *a,int data,int index,int elements){

	current = a;
	int count = 1;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(index == 1){
		temp->next = head;
		temp->data = data;
		head = temp;
	}
	else{
		if(head != NULL){
			while(current->next != NULL){
				if(index == count+1){
					temp->next = current->next;
					temp->data = data;
					current->next = temp;
					break;
					
				}
				current = current->next;
				count++;
			}
		}
	}
	if(index > elements){
		current->next = temp;
		temp->next = NULL;
		temp->data = data;
	}
}

void update(struct node *a,int index,int data,int elements){
	int count = 1;
	while(a->next != NULL){
		if(index == count){
			a->data = data;
		}
		// printf("%d  ",a->data);
		a = a->next;
		count++;
	}
	if(index == elements){
		a->data = data;
	}
}

void delete(struct node *a,int index,int elements){
	int count = 1;
	if(index == 1){
		if(elements>1){
			head = head->next;
		}
		else{
			head = NULL;
		}
	}
	else{
		while(a->next != NULL){
			if(index == count+1){
				if(elements == count+1){
					a->next = NULL;
					break;
				}
				else{
					a->next = a->next->next;
					break;
				}
				// free(a);
				
			}
			a = a->next;
			count++;
		}	
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
int main()
{
	int what,elements,data,pos,total;
	char res;

	printf("\n\n\t\tA PROGRAM OF SIMPLE LINKED LIST DATA STRUCTURE\n");

	do{
		printf("\n1. Insert\n2. Insert at specific position\n3. Delete\n4. Update\n5. view\n6. Reverse Record\n\nYour Response: ");
		scanf("%d",&what);
		elements = check_element(head);
		fflush(stdin);
		if(elements == 0 && what == 2){
			what = 1;
		}


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
			printf("\nHow many numbers you want to add: ");
			scanf("%d",&total);
			for(int i = 0; i<total; i++){

				elements = check_element(head);

				printf("\nYou have %d records\n",elements );
				printf("\nEnter the position: ");
				scanf("%d",&pos);
				fflush(stdin);
				
				if(pos>0){
					printf("\nEnter the value: ");
					scanf("%d",&data);
					fflush(stdin);
					insert_sp(head,data,pos,elements);
					if(elements != 0){
						printf("\nUpdated Record:\n");
						view(head);
					}
				}
				else{
					printf("\nNo record on this position");
				}
			}

		}


		else if (what == 3)
		{
			printf("\nHow many numbers you want to delete: ");
			scanf("%d",&total);
			for(int i = 0; i<total; i++){

				elements = check_element(head);

				printf("\nEnter the position: ");
				scanf("%d",&pos);
				fflush(stdin);
				
				if(pos<=elements && pos>0){
					delete(head,pos,elements);
					if(elements-1 != 0){
						printf("\nUpdated Record:\n");
						view(head);
					}
				}
				else{
					printf("\nNo record on this position");
				}
			}
		}


		else if (what == 4)
		{
			printf("\nHow many numbers you want to update: ");
			scanf("%d",&total);
			for(int i = 0; i<total; i++){

				elements = check_element(head);

				int pos;
				printf("\nEnter the position: ");
				scanf("%d",&pos);
				fflush(stdin);
				
				
				if(pos<=elements && pos>0){
					printf("\nEnter the value: ");
					scanf("%d",&data);
					fflush(stdin);
					update(head,pos,data,elements);

					printf("\nUpdated Record:\n");
					view(head);

				}
				else{
					printf("\nNo record on this position");
				}
			}
		}


		else if (what == 5)
		{
			if(elements!= 0){
				view(head);
			}
			else{
				printf("\nNo record found\n");
			}
		}
		else if (what == 6)
		{
			if(elements != 0){
				reverse(head);
				printf("\nUpdated Record:\n");
				view(head);
			}
		}
		printf("\n\nWant to do some more function? (y/n): ");
		scanf("%c",&res);
	}while(res == 'y');
	return 0;
}