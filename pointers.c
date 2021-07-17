#include <stdio.h>
#include <stdlib.h>
int increment(int *a)
{
    *a = *a+1;
    return(*a);
}
int main()
{
   int a;
   a = 10;
   increment(&a);
   printf("a is %d", a);
    return 0;
}
