#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main(){
	void reverse(char *, int);
	char a[50];
	printf("Enter any string: ");
	cin>>a;
	reverse(a,strlen(a));
	cout<<"Reversed String is: "<<a;


}

void reverse(char a[],int n){
	stack<char> S;
	for (int i = 0; i < n; ++i)
	{
		S.push(a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = S.top();
		S.pop();
	}
}