#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

bool isValid(char*),check_parenthesis(char*),isOperator(char);
int check_open(char),check_close(char),check_astvt(char),calculate(char*, int*),toInt(char);
char* createPostfix(char*,int*,int*);
char* createAdvanceExp(char*, int*);

int main(){
	char exp[50],res;
	int exp_digit[50],advance_digit[50];
	char *postfix_exp,*advance_exp;
	int i,result,error;
	cout<<"\n\n\t\tA PROGRAM TO CALCULATE EXPRESSION USING STACK(POSTFIX METHOD)\n\n";
	do{
		i = 0,error = 0;
		cout<<"\nEnter any expression to calculte: ";
		cin>>exp;
		if(isValid(exp)){
			advance_exp = createAdvanceExp(exp,exp_digit);
			// cout<<advance_exp;
			if(advance_exp != NULL){
				postfix_exp = createPostfix(advance_exp,exp_digit,advance_digit);
				if(postfix_exp != NULL){
					result = calculate(postfix_exp,advance_digit);
					if(result){
						cout<<endl;
						cout<<"\nPost Fix expression: ";
						//cout<<postfix_exp; //Showing some gurbage value after the result but why?
						while(postfix_exp[i]){
							if(isdigit(postfix_exp[i]) || isOperator(postfix_exp[i]) || postfix_exp[i] == 'd'){
								if(postfix_exp[i] == 'd'){
									cout<<advance_digit[i];i++;
								}
								else{
									cout<<postfix_exp[i];i++;
								}
							}
							else{
								cout<<"\nResult Terminated (Error in expression)";
								error = 1;
								break;
							}
						}
						if(error == 0){
							free(postfix_exp);							
							cout<<"\n\nCalculated result: "<<result;
						}	
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

 char* createPostfix(char *exp, int *digit, int *advance_digit){
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
					else{		//if there is anything without operator in betoown two parenthesis that means the expression is invalid

						// new_exp = NULL;
						free(new_exp);
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
		else if(exp[i] == 'd'){
			advance_digit[j] = digit[i];
			new_exp[j] = 'd';
			j++;
		}
		else{			//If anything come with out the subjected list then the expression is invalid
			free(new_exp);
			return new_exp;
		}
	}
	while(!S.empty()){
		if(isOperator(S.top())){	
			// cout<<"test op"<<S.top();
			new_exp[j] = S.top();j++;
			S.pop();
		}
		else{		//At the end the stack should only have operators otherwise the expression is invalid
			// new_exp = NULL;
			free(new_exp);
			return new_exp;
		}
	}
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
int calculate(char *exp , int *digit){
	stack<int> S;
	int op1,op2,i = 0;
	while(exp[i]){
		// cout<<"t"<<exp[i]<<endl;
		// if(isdigit(exp[i])){
		// 	S.push((int)(exp[i]-'0'));
		// 	// cout<<"top"<<S.top()<<endl;
		// }
		if(exp[i] == 'd'){
			S.push(digit[i]);
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

char* createAdvanceExp(char *exp, int *digit){
	int j = 0;
	int val = 0,pos,loc = 0;
	char* new_exp = new char[strlen(exp)];
	for(int i = 0; i <strlen(exp) ; i++){
		if(isdigit(exp[i])){
			while(isdigit(exp[i])){
				// val += val*pow(10,j);
				j++;i++;
			}
			i--;
			for(int k = 0 ; k<j;k++){	//creating integer value from the array of characters
				cout<<"val "<<val<<" add "<<toInt(exp[i-k])*pow(10,k)<<endl;
				val += toInt(exp[i-k])*pow(10,k);
				cout<<"res "<<val<<endl;
			}
			j = 0;
			new_exp[loc] = 'd';
			digit[loc] = val;
			val = 0;
			loc++;
		}
		else{
			new_exp[loc] = exp[i];loc++;
		}
	}
	return new_exp;
}

int toInt(char exp){
	if(isdigit(exp)){
		switch(exp){
			case '1':
			return 1;
			break;
			case '2':
			return 2;
			break;
			case '3':
			return 3;
			break;
			case '4':
			return 4;
			break;
			case '5':
			return 5;
			break;
			case '6':
			return 6;
			break;
			case '7':
			return 7;
			break;
			case '8':
			return 8;
			break;
			case '9':
			return 9;
			break;
			case '0':
			return 0;
			break;
		}
	}
	else{
		return 0;
	}
}