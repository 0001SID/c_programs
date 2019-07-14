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

struct node* reverse(struct node* a){
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

int main(){
	int value,count;
	printf("How many numbers you want to add: ");
	scanf("%d",&count);
	
	for (int i = 0; i < count; ++i)
	{
		printf("Enter value: ");
		scanf("%d",&value);
		insert(head,value);
		
	}
	view(head);
	printf("\nReversed string:\n");
	head = reverse(head);
	view(head);
}