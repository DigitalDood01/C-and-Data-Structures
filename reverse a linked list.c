
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
 struct Node* head;

 void insert(int data)
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

     while(last->next!= NULL)
     {
         last = last->next;
     }
     last->next = temp;
 }

 void print()
 {
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
 }

 void reverse()
 {
    struct Node *current, *previous, *next;
    current = head;
    previous = NULL;

    while(current!= NULL)
    {
        next = current->next;       //storing the address of the next node in this variable
        current->next = previous;   //setting the link of the current node to the previous node
        previous = current;         //resetting the previous and current pointers
        current = next;
    }
    head = previous;
 }


 int main()
 {
     head = NULL;
     insert(2);
      insert(4);
     insert(6);
     insert(5);
     print();
     reverse();
     print();
 }
