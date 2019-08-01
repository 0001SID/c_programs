#include <iostream>
#include <stdlib.h>
#include <queue>
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
	bool search(int val);
	bool mainSearch(node*,int);
	int findMax();
	int findMin(),mainFindMin(node*);
	int findHeight(),mainFindHeight(node*);
	void levelOrderTraversal();
	void preorder(),mainPreorder(node*);
	void postorder(),mainPostorder(node*);
	void inorder(),mainInorder(node*);
	void del(int);
	node* mainDelete(node*,int);


};
int main(){
	int what,n,val;
	char res;
	bst Tree;

	printf("\n\n\t\tA PROGRAM OF BINARY SEARCH TREE\n");

	do{
		cout<<"\n1. Insert\n2. Search\n3. Find Min\n4. Find Max\n5. Find Height\n6. Level Order Traversal\n7. Pre Order Traversal\n8. In Order Traversal\n9. Post Order Traversal\n10. Delete\n\nYour Response: ";
		cin>>what;
		switch(what){
			case 1:
			cout<<"How many number you want to insert: ";
			cin>>n;
			for(int i = 0; i< n; i++){
				cout<<"Enter the value: ";
				cin>>val;
				Tree.insert(val);
			}
			break;
		
			case 2:
			cout<<"Enter the number you want to search: ";
			cin>>val;
			if(Tree.search(val)){
				cout<<"Record Found";
			}
			else{
				cout<<"Record not found";
			}
			break;
		
			case 3:
				cout<<"Min value in the tree: "<<Tree.findMin();
				break;
			case 4:
				cout<<"Max value in the tree: "<<Tree.findMax();
				break;
			case 5:
				cout<<"Height of the tree is: "<<Tree.findHeight();
				break;
			case 6:
				Tree.levelOrderTraversal();
				break;
			case 7:
				Tree.preorder();
				break;
			case 8:
				Tree.postorder();
				break;
			case 9:
				Tree.inorder();
				break;
			case 10:
				cout<<"Enter the number you want to delete: ";
				cin>>val;
				Tree.del(val);
				break;
			default:
				cout<<"Invalid Response";
		}
		printf("\n\nWant to do some more function? (y/n): ");
		fflush(stdin);
		cin>>res;

	}while(res == 'y');
}

void bst::insert(int val){
	if(mainRoot != NULL){
		node* root = mainRoot;
		node* pre = NULL;
		int side;
		while(root != NULL){
			if(val<=root->data){
				pre = root;side = 0;
				root = root->left;
			}
			else{
				pre = root;side = 1;
				root = root->right;
			}
		}
		if(side == 0){
			pre->left = createNode(val);
		}
		else{
			pre->right = createNode(val);
		}
		// root = createNode(val);
	}
	else{
		mainRoot = createNode(val);
	}
}

bool bst::search(int val){
	node* root = mainRoot;
	while(true){
		if(root != NULL){
			if(root->data == val){
				return true;
			}
			else if(val<= root->data){
				root = root->left;
			}
			else{
				root = root->right;
			}
		}
		else{
			return false;
		}
	}
}

bst::node* bst::createNode(int val){
	node* temp = new node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
}

int bst::findMin(){
	node* root = mainRoot;
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;
}

int bst::findMax(){
	node* root = mainRoot;
	while(root->right != NULL){
		root = root->right;
	}
	return root->data;
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

void bst::levelOrderTraversal(){
	node* root = mainRoot;
	queue<node*> Q;
	if(root != NULL){
		Q.push(root);
		do{
			root = Q.front();
			if(root->left != NULL){
				Q.push(root->left);
			}
			if(root->right != NULL){
				Q.push(root->right);
			}
			cout<<Q.front()->data<<" ";
			Q.pop();

		}while(!Q.empty());
	}
	else{
		cout<<"Empty Tree"<<endl;
		return;
	}
}

void bst::preorder(){
	mainPreorder(mainRoot);
}

void bst::mainPreorder(node* root){
	if(root == NULL) return ;
	cout<<root->data<<" ";
	mainPreorder(root->left);
	mainPreorder(root->right);
}

void bst::postorder(){
	mainPostorder(mainRoot);
}

void bst::mainPostorder(node* root){
	if(root == NULL) return ;
	mainPostorder(root->left);
	mainPostorder(root->right);
	cout<<root->data<<" ";
}

void bst::inorder(){
	mainInorder(mainRoot);
}

void bst::mainInorder(node* root){
	if(root == NULL) return ;
	mainInorder(root->left);
	cout<<root->data<<" ";
	mainInorder(root->right);
}

void bst::del(int val){
	mainDelete(mainRoot,val);
}

bst::node* bst::mainDelete(node* root,int val){
	if(root == NULL) return NULL;
	if(val > root->data) root->right = mainDelete(root->right,val);
	else if(val < root->data) root->left = mainDelete(root->left,val);
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		else if(root->left == NULL){
			node* temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL){
			node* temp = root;
			root = root->left;
			free(temp);
		}
		else{
			root->data = mainFindMin(root->left);
			root->left = mainDelete(root->left,root->data);
		}
		return root;
	}
}

int bst::mainFindMin(node* root){
	if(root->left == NULL){
		return root->data;
	}
	else{
		return mainFindMin(root->left);
	}
}