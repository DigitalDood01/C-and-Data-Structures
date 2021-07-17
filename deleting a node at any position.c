#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};
struct Node* head;
void insert(int data)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head; //variable to traverse through the list
    temp1->data = data;
    temp1->link = NULL;         // set to NULL because the the added element is the last one in the list
    if(head == NULL)
    {
        head = temp1;           // when list is empty make the new node as head
        return;
    }
    while(last->link != NULL)    // if link is not empty traverse till the last node
    {
        last = last->link;
    }
    last->link = temp1;         //change the next of last node  (or)(n-1th node


}

void print()
{
    struct Node* temp = head;

    while(temp!= NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void delete(int n)
{
    struct Node* temp1 = head;

    if(n==1)
    {
        head = temp1->link;     //head now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=1; i<n-1; i++)
    {
       temp1 = temp1->link;         //temp1 points to the n-1 node
    }
 struct Node* temp2 = temp1->link;       //nth node
 temp1->link = temp2->link;                 // removing the connection of the node to be removed from the list
 free(temp2);

}
struct Node* head;

int main()
{
    int n;
  head = NULL;
  insert(2);
  insert(4);
  insert(6);
  insert(5);
  print();
  printf("\nenter the position ");
  scanf("%d", &n);
  delete(n);
  print();
}
