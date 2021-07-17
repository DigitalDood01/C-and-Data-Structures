
#include <stdio.h>
#define MAX_SIZE  30000
char A[MAX_SIZE];
int top = -1;               //empty stack
void push(char x)
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
        printf("%c", A[i+1]);
    }
    printf("\n");
}
reverseprint()
{
    int i,j,temp;
    j = top;
    for(i=0; i<top; i++)
    {
        temp = A[i];            /* swapping the last and first element of the Array */
        A[i] = A[j];
        A[j] = temp;
        j--;
    }
}
int main()
{
    printf(" Enter the string\t");
    int i;
    gets(A);
    for(i=0; i<strlen(A); i++)
    {
        push(A[i]);
    }
    print();
    reverseprint();
    print();
}
