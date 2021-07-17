#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
};
void insertathead(int data)
{
    struct Node* temp = GetNewNode(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;      //prev link of existing node is pointed to the new node
    temp->next = head;      //next link of new node is pointed to the exisitng node
    head = temp;            //instead of pointing to the existing node, the head now points to the new node
}

void insertattail(int data)
{
    struct Node* temp = GetNewNode(data);
    struct Node* temp1 = head;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    temp->next = NULL;
}

void print()
{
    struct Node* temp = head;
    printf("forward \t");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void reverseprint()
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        return;             //empty list, so return
    }
    printf("reverse \t");
    while(temp->next!= NULL)
    {
        temp = temp->next;      //going to last node
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;      //traversing back using previous pointer
    }
    printf("\n");
}

int main()
{
    head = NULL;
   insertattail(2);
   print();
   insertattail(4);
   print();
   insertattail(6);
   print();
   reverseprint();
}
