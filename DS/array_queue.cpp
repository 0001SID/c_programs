#include <iostream>
#include <iomanip>
using namespace std;

class queue{
	private:
		int a[10];
		int front,rear;
	public:
		queue(){
			front = -1;
			rear = -1;
		}
		bool enqueue(int);
		bool dequeue();
		int frontVal();
		bool isEmpty();
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
				if(!Q.enqueue(val)){
					cout<<"Queue is full"<<endl;
					break;
				}
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



bool queue :: enqueue(int val){
	if(!isEmpty()){
		rear = (rear + 1)%(sizeof(a)/sizeof(int));
		if(rear == front){
			rear = (rear + (sizeof(a)/sizeof(int)) - 1)%(sizeof(a)/sizeof(int));
			return false;
		}
		else{
			a[rear] = val;
			return true;
		}
	}
	else{
		rear++;front++;
		a[front] = val;
		return true;
	}
}

bool queue :: dequeue(){
	if(!isEmpty()){
		if(front == rear){
			front = rear = -1;
			return true;
		}
		else{
			front =(front + 1)%(sizeof(a)/sizeof(int));
			return true;
		}
	}
	else{
		return false;
	}
}

int queue :: frontVal(){
	return a[front];
}

bool queue :: isEmpty(){
	if(front == -1 && rear == -1){
		return true;
	}
	else{
		return false;
	}
}