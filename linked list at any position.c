#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
void insert(int data, int n)
{
    int i;
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = dataF:\career\STUDY\C-PROGRAMMING\DATA_STRUCTURES\linked list at any position.c;
    temp1->next = NULL;

    if(n==1)
    {
        temp1->next = head;     //new node's link is made equal to the link of head node which is NULL initially.
        head = temp1;  //adjust the variable to newly created node
        return;
    }
    struct Node* temp2 = head;
    for(i = 1 ; i<n-1; i++)
    {
        temp2 = temp2->next; //pointing temp2 to (n-1)th node(traversing to the n-1 node).
    }
    temp1->next = temp2->next;  //set the link of newly created node to link of (n-1)th node
    temp2->next = temp1;        //insert the new node to the network
    return;

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

int main()
{
    head = NULL; //initially its a empty list
    insert(2,1);
    insert(4,2);
    insert(6,3);
    print();
    insert(8,3);
    insert(7,1);
    print();
    return 0;
}

