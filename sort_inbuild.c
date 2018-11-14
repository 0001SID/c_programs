#include<stdio.h>
#include<stdlib.h>
int compare(const void *,const void *);
int main()
{
    int arr[] = {5,4,6,3,5,12,34,45};
    int size = sizeof(arr)/sizeof(arr[0]);
    int width = sizeof(arr[0]);
    qsort((void *)arr,size,width,compare);
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
int compare(const void *a, const void *b)
{
    if((*(int *)a) == (*(int *)b))
    return 0;
    else if((*(int *)a) < (*(int *)b))
    return -1;
    else
    return 1;
}