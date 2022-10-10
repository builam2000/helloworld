#include <stdio.h>
void foo(int a)
{
    printf("Value of a is %d\n", a);
}
  
int main()
{ 
    void (*funtion_pointer)(int) = foo;
  
    funtion_pointer(10);
  
    return 0;
}
