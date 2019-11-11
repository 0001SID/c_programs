#include <iostream>
using namespace std;

int a[50],n,big,end,mid,item;
void binary_search();

int main(){
	cout<<"How many numbers you want to add: ";cin>>n;
	for(int i = 0; i<n; i++){
		cout<<"Enter value: ";cin>>a[i];
	}
	cout<<"Enter the value you want to search: ";cin>>item;
	binary_search();
	return 0;
}

void binary_search(){
	big = 0; end = n;mid = (big+end)/2;
	while(big<=end && a[mid] != item){
		if(item>a[mid]){
			big = mid+1;
		}
		else{
			end = mid-1;
		}
		mid = big + end;
	}
	if(a[mid] == item){
		cout<<"value "<<item<<" is found on position "<<mid+1;
	}
	else{
		cout<<"No record found";
	}
}