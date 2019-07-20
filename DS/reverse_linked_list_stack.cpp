#include <iostream>
#include <stack>
using namespace std;

struct node{
	int data;
	struct node *next;
};
void push(int);
void reverse();
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
		printf("\n1. Push\n2. Pop\n3. Top\n4. Reverse\n\nYour Response: ");
		cin>>what;
		fflush(stdin);
		if(what == 1){
			cout<<"How many numbers you want to push: ";
			cin>>n;
			if(n > 0){
				for(int i = 0 ; i < n ; i++){
					cout<<"Enter value: ";
					cin>>val;
					push(val);
				}
			}

		}
		else if(what == 2){
			if(!isEmpty()){
				pop();
			}
			else{
				cout<<"Stack is empty\n";
			}
		}
		else if(what == 3){
			if(!isEmpty()){
				cout<<"Top value = "<<topVal();
			}
			else{
				cout<<"Stack is empty\n";
			}
		}

		else if(what == 4){
			if(!isEmpty()){
				reverse();
			}
			else{
				cout<<"Stack is empty\n";
			}
		}

		cout<<"\n\nWant to do some more function? (y/n): ";
		fflush(stdin);
		cin>>res;

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

void reverse(){
	stack<struct node*> S;
	struct node* temp = top;
	while(temp != NULL){
		S.push(temp);
		temp = temp->next;
	}
	top = S.top();
	temp = top;
	S.pop();
	while(!S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}