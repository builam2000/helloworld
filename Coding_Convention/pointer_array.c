#include <stdio.h>

void main()
{
    int arr[10]={0};
    int a = 1;
    int *p = &arr[0];
    printf("%p %p \n",arr,p);

    printf("Size of array: %ld, Size of pointer to array: %ld \n",sizeof(arr)/sizeof(int), sizeof(p));

    p = &a;
    printf("p after assign: %p\n",p);
}
