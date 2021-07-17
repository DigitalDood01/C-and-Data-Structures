#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if((rear == NULL)&& (front == NULL))                /*when list is empty*/
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;                                  /*include the new node in the existing linked list*/
    rear = temp;                                        /* make the rear to point to the new node*/
}
void dequeue ()
{
    struct Node* temp = front;
    if(front == NULL)
    {
        printf("list is empty \n");
        return;
    }
    if(front == rear)
    {
        front = NULL;                   /* if both rear and front are equal the list get locked so make both as null*/
        rear = NULL;
    }
    front = front->next;            
    free(temp);                         /*free the memory allocated in the memory*/
    
}

void print()
{
    struct Node* temp = front;
    printf(" The queue is \t");
    while(temp!=rear->next)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }printf("\n");
}

int main ()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print();
    dequeue();
    print();
    enqueue(4);
    print();
}