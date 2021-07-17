#include <stdio.h>
#define MAX_SIZE  10
int A[MAX_SIZE];
int top = -1;               //empty stack
void push(int x)
{
    if(top == (MAX_SIZE-1))
    {

        printf("stack overflow");
    }
    else
    {
        A[++top] = x;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("No element to pop");
    }
    else
    top = top-1;
}
int topelement()
{
    return A[top];
}
void print()
{
    int i;
    printf("The stack elements are\t");
    for(i=-1; i<top; i++)
    {
        printf("%d ", A[i+1]);
    }
    printf("\n");
}
int main ()
{
    int x = 0;
    push(1);
    print();
    push(2);
    print();
    push(50);
    print();
    pop();
    print();
   x = topelement();
   printf("top element is %d\n", x);
    push(4);
    print();
    push(5);
    print();
    pop();
    print();
   // topelement();
}
