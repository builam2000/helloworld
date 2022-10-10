#include <stdio.h>
typedef char* ptr;
#define PTR char*
int main()
{
    ptr a, b;
    PTR x, y;
    printf("sizeof a:%zu\n" ,sizeof(a) );
    printf("sizeof b:%zu\n" ,sizeof(b) );
    
    printf("sizeof x:%zu\n" ,sizeof(x) );
    printf("sizeof y:%zu\n" ,sizeof(y) );
    
    return 0;
}