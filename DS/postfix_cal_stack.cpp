#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

bool isValid(char*),check_parenthesis(char*),isOperator(char);
int check_open(char),check_close(char),check_astvt(char),calculate(char*);
char* createPostfix(char*);

int main(){
	char exp[50],res;
	char *postfix_exp;
	int i,result;
	cout<<"\n\n\t\tA PROGRAM TO CALCULATE EXPRESSION USING STACK(POSTFIX METHOD)\n\n";
	do{
		i = 0;
		cout<<"\nEnter any expression to calculte: ";
		cin>>exp;
		if(isValid(exp)){
			postfix_exp = createPostfix(exp);
			if(postfix_exp != NULL){
				result = calculate(postfix_exp);
				if(result){
					cout<<endl;
					cout<<"\nPost Fix expression: ";
					//cout<<postfix_exp; //Showing some gurbage value after the result but why?
					while(postfix_exp[i]){
						if(isdigit(postfix_exp[i]) || isOperator(postfix_exp[i])){
							cout<<postfix_exp[i];i++;
						}
						else{
							break;
						}
					}	
					free(postfix_exp);
					
					cout<<"\n\nCalculated result: "<<result;
				}
				else{
					cout<<"\nInvalid Expression";
				}
			}
			else{
				cout<<"\nInvalid Expression";
			}
		}
		else{
			cout<<"\nInvalid expression";
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

bool isOperator(char exp){
	if(exp == '+' || exp == '-' || exp == '/' || exp == '*'){
		return true;
	}
	else{
		return false;
	}
}

int check_astvt(char exp){
	if(exp == '+' || exp == '-'){
		return 10;
	}
	else if(exp == '*' || exp =='/'){
		return 20;
	}
}

bool isParenthesis(char exp){
	if(check_open(exp) || check_close(exp)){
		return true;
	}
	else{
		return false;
	}
}
bool isValid(char *exp){
	int i;
	if(check_parenthesis(exp)){
		for(i = 0 ; i< strlen(exp); i++){
			if(isdigit(exp[i])){continue;}
			else if(isParenthesis(exp[i])){continue;}
			else if(isOperator(exp[i])){continue;}
			else{return false;}
		}
		if(i == strlen(exp)){
			return true;
		}
	}
	else{
		return false;
	}
}

 char* createPostfix(char *exp){
 	// cout<<"Test"<<endl;
	stack<char> S;
	char* new_exp = (char*)malloc(sizeof(char)*50);
	int j = 0;
	for(int i = 0; i< strlen(exp); i++){
		if(check_open(exp[i])){
			S.push(exp[i]);
		}
		else if(check_close(exp[i])){
			if(!S.empty()){
				do{
					if(isOperator(S.top())){
						new_exp[j] = S.top();j++;
						S.pop();
					}
					else{

						new_exp = NULL;
						return new_exp;
					}
				}while(check_close(exp[i]) != check_open(S.top()));
				S.pop();
			}
			// else{
			// 	return 'Invalid Expression';
			// }
		}
		else if(isOperator(exp[i])){
			// cout<<"in isOperator"<<S.top();
			if(!S.empty() && isOperator(S.top())){
				if(check_astvt(S.top())>=check_astvt(exp[i])){
					new_exp[j] = S.top();j++;
					S.pop();
					S.push(exp[i]);
				}
				else{
					S.push(exp[i]);
				}
			}
			else{
				S.push(exp[i]);
			}
		}
		else{
			new_exp[j] = exp[i];j++;
		}
	}
	while(!S.empty()){
		if(isOperator(S.top())){
			// cout<<"test op"<<S.top();
			new_exp[j] = S.top();j++;
			S.pop();
		}
		else{
			new_exp = NULL;
			return new_exp;
		}
	}
	new_exp = (char*)realloc(new_exp,sizeof(char)*j);
	return new_exp;
}

int perform(int op1,int op2,char oprtr){
	switch(oprtr){
		case '+':
		return op1+op2;
		case '-':
		return op1-op2;
		case '*':
		return op1*op2;
		case '/':
		return op1/op2;
	}
}
int calculate(char *exp){
	stack<int> S;
	int op1,op2,i = 0;
	while(exp[i]){
		// cout<<"t"<<exp[i]<<endl;
		if(isdigit(exp[i])){
			S.push((int)(exp[i]-'0'));
			// cout<<"top"<<S.top()<<endl;
		}
		else if(isOperator(exp[i])){
			if(!S.empty()){
				op2 = S.top();
				S.pop();
			}
			else{
				return 0;
			}
			if(!S.empty()){
				op1 = S.top();
				S.pop();
			}
			else{
				return 0;
			}
			S.push(perform(op1,op2,exp[i]));
			// cout<<"res"<<S.top()<<endl;

		}
		else{
			break;
		}
		i++;
	}
	return S.top();
}