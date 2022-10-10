#include <stdio.h>

typedef struct
{
	char c;
	int i;
}foo;

struct Employee
{
	int id;
	char Name[20];
	float salary;
}emp;

struct example
    {
	
        int i1;
        double d1;
        char c1;

    } example1;

void main()
{
	foo i;
	printf("Size of struct in memory: %ld \n",sizeof(foo));
	printf("Size of employee: %ld \n", sizeof(emp));
	  printf("size = %ld bytes\n",sizeof(example1));	
}
