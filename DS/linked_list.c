#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void insert(struct node *temp,int data){
	
	temp->next = NULL;
	temp->data = data;

}

void insert_sp(struct node *a,struct node *temp,int data,int index,int elements){
	int count = 1;
	while(a->next != NULL){
		if(index == count+1){
			temp->next = a->next;
			temp->data = data;
			a->next = temp;
			break;
			
		}
		a = a->next;
		count++;
	}
	if(index > elements){
		a->next = temp;
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

// void delete_last(struct node *a){
// 	while(a->next != NULL){
// 		printf("%d  ",a->data);
// 		a = a->next;
// 	}
// 	free(a);
// }


void save_address(struct node *a,struct node *temp){
	while(a->next != NULL){
		a = a->next;
	}
	a->next = temp;
}

void view(struct node *a){
	while(a->next != NULL){
		printf("%d  ",a->data);
		a = a->next;
	}
	printf("%d  ",a->data);
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
	int what,elements,data,pos;
	char res;
	struct node *A;
	A = NULL;

	do{
		printf("\n1. Insert\n2. Insert at specific position\n3. Delete\n4. Update\n5. view\n\nYour Response: ");
		scanf("%d",&what);
		elements = check_element(A);
		fflush(stdin);
		if(elements == 0 && what == 2){
			what = 1;
		}


		if (what == 1)
		{
			printf("You have %d records\n",elements );
			printf("Enter the data\n");
			scanf("%d",&data);
			fflush(stdin);
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			if(elements == 0){
				A = temp;
			}else{
				save_address(A,temp);
			}
			insert(temp,data);
			printf("\nUpdated Record:\n");
			view(A);
		}


		else if(what == 2){
			printf("You have %d records\n",elements );
			printf("Enter the position: ");
			scanf("%d",&pos);
			fflush(stdin);
			
			if(pos>0){
				printf("Enter the value: ");
				scanf("%d",&data);
				fflush(stdin);
				struct node *temp = (struct node*)malloc(sizeof(struct node));
				
				if(pos == 1){
					temp->next = A;
					temp->data = data;
					A = temp;
				}else{
					insert_sp(A,temp,data,pos,elements);
				}
				if(elements != 0){
					printf("\nUpdated Record:\n");
					view(A);
				}
			}
			else{
				printf("No record on this position\n");
			}

		}


		else if (what == 3)
		{
			printf("Enter the position: ");
			scanf("%d",&pos);
			fflush(stdin);
			
			if(pos<=elements && pos>0){
				if(pos == 1){
					if(elements>1){
						A = A->next;
					}
					else{
						A = NULL;
					}
				}else{
					delete(A,pos,elements);
				}
				if(elements-1 != 0){
					printf("\nUpdated Record:\n");
					view(A);
				}
			}
			else{
				printf("No record on this position\n");
			}
		}


		else if (what == 4)
		{
			int pos;
			printf("Enter the position: ");
			scanf("%d",&pos);
			fflush(stdin);
			
			
			if(pos<=elements && pos>0){
				printf("Enter the value: ");
				scanf("%d",&data);
				fflush(stdin);
				update(A,pos,data,elements);

				printf("\nUpdated Record:\n");
				view(A);

			}
			else{
				printf("No record on this position\n");
			}
			// printf("test 3\n");
		}


		else if (what == 5)
		{
			if(elements!= 0){
				view(A);
			}
			else{
				printf("No record found\n");
			}
		}
		printf("\n\nWant to do some more function? (y/n): ");
		scanf("%c",&res);
	}while(res == 'y');
	return 0;
}