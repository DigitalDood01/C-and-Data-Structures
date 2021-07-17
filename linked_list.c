#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
linked list definition
*/
// Inserting a linked list at the beginning
struct Node
{
    int data;
    struct Node* next;      //this is how pointer to node is declared in C
};
struct Node* head;          //global variable, can be accessed anywhere

void insert(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));   //we are using typedef because malloc usually returns void pointer.
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print()
{
    struct Node* temp = head;       //creating a local variable to get store the value of head temporarily so that value in head remains uncorrupted
    printf("list is ");
    while(temp!=NULL)               //checks whether the list is empty or not
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main ()
{
    head = NULL; // Initially its points to nothing
    printf("how many numbers? \n");
    int i,n,x;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("enter the number \n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}
