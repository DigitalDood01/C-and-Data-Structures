
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


struct Node* insert( struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    return head;
}

void print(struct Node* p)
{
 if(p == NULL)
 {
     printf("\n");
     return;                     //exit condition for recursion
 }
 printf("%d ", p->data);        //first print the value in the node
 print(p->next);                //recursive Call
}

void reverseprint(struct Node* p)
{
 if(p == NULL)
    {
        printf("\n");
        return;
    }

    reverse print(p->next);
    printf("%d ", p->data);


}

int main()
{
struct Node* head = NULL;
head = insert(head, 2);
head = insert(head, 4);
head = insert(head, 6);
head = insert(head, 5);
print(head);
reverseprint(head);
}
