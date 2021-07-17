#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define true 1
#define false 0
int a[MAX];
int rear, front;
rear = 0;
front = 0;

void enqueue(int x)
{
    if(isfull())
    {
        return;
    }
    else
    {
        rear = (rear + 1)%MAX;
        a[rear] = x;
    }

}

void dequeue()
{
    if(isempty())
    {
        return;
    }
    else if(rear == front)
    {
        printf(" equal");
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1)%MAX;
    }
   // printf(" front = %d \n", front);
}
void top()
{
    printf("%d \n", rear);
}
int isfull()                    // Mention the return type as int as 1 or 0 should be returned to the called function
{
    if(((rear+1)%MAX) == front)
    {
        printf(" The queue is full \n");
        return true;
    }
    else
    {
        return false;
    }
}
int isempty()               // Mention the return type as int as 1 or 0 should be returned to the called function
{
  if((front == -1)&&(rear == -1))
     {
         printf(" The queue is empty \n");
        printf(" The queue is empty \n");
        return true;
     }
  else
  {
      return false;
  }

}

void print()
{
    printf(" The elements in queue are \t");
    int i = 0;;
    for(i = 0; i<MAX; i++)
    {
        //printf(" rear %d \n", rear);
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main ()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    enqueue(6);
    enqueue(7);
    print();
}
