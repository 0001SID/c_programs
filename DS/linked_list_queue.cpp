#include <iostream>
#include <iomanip>
using namespace std;

class queue{
	private:
		struct node{
			int data;
			struct node* next;
		};
		struct node* front;
		struct node* rear;
		struct node* temp;
	public:
		queue(){
			front = NULL;
			rear = NULL;
		}
		void enqueue(int);
		bool dequeue();
		int frontVal();
		bool isEmpty();
		node* createNode(){
			temp = new node;
			temp->next = NULL;

		}
};

int main(){
	char res;
	int n,val,what;
	queue Q;
	cout<<"\n\n\t\tA PROGRAM TO CREATE QUEUE USING ARRAY\n\n";
	do{
		cout<<"\n1. Enqueue\n2. Dequeue\n3. Front\n\nYour Response: ";
		cin>>what;

		if(what == 1){
			cout<<"How many numbers you want to enqueue: ";
			cin>>n;
			for(int i = 0 ; i< n; i++){
				cout<<"Enter value: ";
				cin>>val;
				Q.enqueue(val);
			}
		}
		else if(what == 2){
			cout<<"How many numbers you want to dequeue: ";
			cin>>n;
			for(int i = 0; i< n; i++){
				if(!Q.dequeue()){
					cout<<"Queue is empty"<<endl;
					break;
				}
			}
		}
		else if(what == 3){
			if(!Q.isEmpty()){
				cout<<"Front value: "<<Q.frontVal()<<endl;
			}
			else{
				cout<<"Queue is empty"<<endl;
			}
		}

		cout<<"\n\nDo you want to check more(y/n): ";
		cin>>res;
	}while(res == 'y');
}

void queue :: enqueue(int val){
	temp = createNode();
	temp->data = val;
	if(!isEmpty()){
		rear->next = temp;
		rear = temp;
	}
	else{
		front = rear = temp;
	}
}

bool queue :: dequeue(){
	if(!isEmpty()){
		temp = front;
		front = front->next;
		delete temp;
		return true;
	}
	else{
		return false;
	}
}

int queue :: frontVal(){
	return front->data;
}

bool queue :: isEmpty(){
	if(front == NULL){
		return true;
	}
	else{
		return false;
	}
}

// queue::node* queue :: *createNode(){
// 	struct node* temp = new queue::node;
// 	temp->next = NULL;
// 	return temp;
// }