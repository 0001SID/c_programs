#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool check_parenthesis(char*);
int main(){
	char exp[50],res;
	cout<<"\n\n\t\tA PROGRAM OF CHECK PARENTHESIS BALANCE USING STACK\n";
	do{
		cout<<"\nEnter any expression: ";
		cin>>exp;
		if(check_parenthesis(exp)){
			cout<<"\nExpression is balanced";
		}
		else{
			cout<<"\nExpression is not balanced";
		}
		cout<<"\n\nDo you want to check more(y/n): ";
		cin>>res;
	}while(res == 'y');

}

int check_open(char a){
	if(a == '('){
		return 1;
	}
	else if(a == '{'){
		return 2;
	}
	else if(a == '['){
		return 3;
	}
	else{
		return 0;
	}
}
int check_close(char a){
	if(a == ')'){
		return 1;
	}
	else if(a == '}'){
		return 2;
	}
	else if(a == ']'){
		return 3;
	}
	else{
		return 0;
	}
}

bool check_parenthesis(char *exp){
	stack<int> S;
	for(int i = 0; i< strlen(exp); i++){
		if(check_open(exp[i])){
			S.push(exp[i]);
		}
		if(check_close(exp[i])){
			if(S.empty()){
				return false;
				break;
			}
			else{
				if(check_close(exp[i]) == check_open(S.top())){
					S.pop();
				}
				else{
					return false;
					break;
				}
			}
		}
	}
	if(S.empty()){
		return true;
	}
	else{
		return false;
	}
}