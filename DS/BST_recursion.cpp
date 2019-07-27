#include <iostream>
#include <stdlib.h>
using namespace std;

class bst{
private:
	struct node
	{
		int data;
		node* left;
		node* right;
	};
	node* mainRoot;
public:
	bst(){
		mainRoot = NULL;
	}
	node* createNode(int);
	void insert(int);
	void mainInsert(node**,int);
	bool search(int val);
	bool mainSearch(node*,int);
	int findMin(),mainFindMin(node*);
	int findMax(),mainFindMax(node*);
	int findHeight(),mainFindHeight(node*);

};
int main(){
	int what,n,val;
	char res;
	bst Tree;

	printf("\n\n\t\tA PROGRAM OF BINARY SEARCH TREE\n");

	do{
		printf("\n1. Insert\n2. Search\n3. Find Min\n4. Find Max\n5. Find Height\n\nYour Response: ");
		scanf("%d",&what);
		if(what == 1){
			cout<<"How many number you want to insert: ";
			cin>>n;
			for(int i = 0; i< n; i++){
				cout<<"Enter the value: ";
				cin>>val;
				Tree.insert(val);
			}
		}
		else if(what == 2){
			cout<<"Enter the number you want to search: ";
			cin>>val;
			if(Tree.search(val)){
				cout<<"Record Found";
			}
			else{
				cout<<"Record not found";
			}
		}
		else if(what == 3){
			cout<<"Min value in the tree: "<<Tree.findMin();
		}
		else if(what == 4){
			cout<<"Max value in the tree: "<<Tree.findMax();
		}
		else if(what == 5){
			cout<<"Height of the tree is: "<<Tree.findHeight();
		}
		else{
			cout<<"Invalid Response";
		}
		printf("\n\nWant to do some more function? (y/n): ");
		fflush(stdin);
		scanf("%c",&res);

	}while(res == 'y');
}

void bst::mainInsert(node** root, int val){
	if(*root == NULL){
		*root = createNode(val);
	}
	else if(val<=(*root)->data){
		mainInsert(&((*root)->left),val);
	}
	else{
		mainInsert(&((*root)->right),val);
	}
}

void bst::insert(int val){
	mainInsert(&mainRoot,val);
}

bool bst::search(int val){
	return mainSearch(mainRoot,val);
}
bool bst::mainSearch(node* root,int val){
	if(root != NULL){
		if(root->data == val){
			return true;
		}
		else if(val<=root->data){
			mainSearch(root->left,val);
		}
		else{
			mainSearch(root->right,val);
		}
	}
	else{
		return false;
	}
}

bst::node* bst::createNode(int val){
	node* temp = new node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
}

int bst::findMin(){
	return mainFindMin(mainRoot);
}

int bst::mainFindMin(node* root){
	if(root->left == NULL){
		return root->data;
	}
	else{
		return mainFindMin(root->left);
	}
}

int bst::findMax(){
	return mainFindMax(mainRoot);
}

int bst::mainFindMax(node* root){
	if(root->right == NULL){
		return root->data;
	}
	else{
		return mainFindMax(root->right);
	}
}

int bst::findHeight(){
	return mainFindHeight(mainRoot);
}

int bst::mainFindHeight(node* root){
	if(root == NULL){
		return -1;
	}
	else{
		return max(mainFindHeight(root->left),mainFindHeight(root->right)) + 1;
	}
}