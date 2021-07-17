#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* link;
};
struct Node* top = NULL;
void push(data)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;          //adding the data
    temp->link = top;           //new element's link is pointing to the next element
    top = temp;                 //top is pointing to the new element
}
void pop()
{
    if(top == NULL)
    {
        printf("the stack is empty");
        return;
    }
    struct Node* temp = top;       //temporary variable is pointing to the top
    top = top->link;               // top points to the next element
    free(temp);                    // the deleted element's memory space is freed
}
void print()
{
    struct Node* temp = top;
    printf("The stack is \t");
    while(temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
struct Node* topelement()
{
    return top->data;
};
int main ()
{
    push('{');
    push('}');
    print();
}
