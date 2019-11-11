#include <stdio.h>
#include <stdlib.h>
void del(int *,int*),view(int*,int),reverse(int*,int);
int* insert(int*,int*);
int* insert_sp(int*,int*);
int main(){
	int what,n = 0;
	char res;
	int *a = (int *)malloc(sizeof(int));

	printf("\n\n\t\tA PROGRAM OF SIMPLE ARRAY DATA STRUCTURE\n");

	do{
		printf("\n1. Insert\n2. Insert at specific position\n3. Delete\n4. view\n5. Reverse Record\n\nYour Response: ");
		scanf("%d",&what);
		fflush(stdin);
		if(what == 1){
			a = insert(a,&n);
		}
		else if(what == 2){
			a = insert_sp(a,&n);
		}
		else if(what == 3){
			del(a,&n);
		}
		else if(what == 4){
			view(a,n);
		}
		else if(what == 5){
			reverse(a,n);
		}

		printf("\n\nWant to do some more function? (y/n): ");
		fflush(stdin);
		scanf("%c",&res);

	}while(res == 'y');
	
	
}

void del(int *a,int *n){
	// int *a;
	// a = b;
	int total,pos;
	printf("How many numbers you want to delete: ");
	scanf("%d",&total);
	if(total<0 || total > *n){
		printf("Out of range\n");
	}
	else{
		for(int j = 0; j< total ; j++){
			printf("\nEnter the postion to delete: ");
			scanf("%d",&pos);
			if(pos<0 || pos > *n){
				printf("\nEntered position is empty"); 
				j--;
			}
			else{
				pos = pos-1;
				for(int i = pos; i<*n-1; i++){
					a[i] = a[i+1];
				}
				*n = *n-1;
				a = realloc(a,sizeof(int)*(*n)); //Why this line working here but nor working in insert function

				printf("\nThe new record is:\n");

				view(a,*n);

			}
		}
	}
	
}
int* insert(int *a,int *n){
	int total;
	printf("How many numbers you want to add: ");
	scanf("%d ",&total);
	total = *n + total;
	int *b = realloc(a,sizeof(int)*(total));
	// a = realloc(a,sizeof(int)*(total));  //Why this is not working?
	for(int i = *n ; i< total ; i++){
		scanf("%d",b+i);
	}
	*n = total;
	return b;
}

int* insert_sp(int *a, int *n){
	int total,pos,val,pre;
	printf("How many numbers you want to insert: ");
	scanf("%d",&total);
	total = *n + total;
	pre = *n;
	int *b = realloc(a,sizeof(int)*total);
	for(int i = pre; i< total; i++){
		printf("\nEnter the position: ");
		scanf("%d",&pos);
		pos = pos-1;
		if(pos>=0 && pos<=*n){
			printf("\nEnter the value: ");
			scanf("%d",&val);
			for(int j = *n; j>pos; j--){
				b[j] = b[j-1];
			}
			b[pos] = val;
			*n+=1;
			printf("\nupdated Record:\n");
			view(b,*n);
		}
		else{
			printf("\nOut of range");
			i--;
		}
	}
	return b;
}

void view(int *a,int n){
	for(int i = 0 ; i< n; i++){
		printf("%d ",a[i]);
	}
}

void reverse(int *a,int n){
	for(int i = n-1 ; i>= 0; i--){
		printf("%d ",a[i]);
	}
}