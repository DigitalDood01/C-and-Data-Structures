 #include <stdio.h>
 #include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
 struct BstNode 
 {
     int data;
     struct BstNode* left;
     struct BstNode* right;
 };

 struct BstNode* root = NULL;

 struct BstNode* GetNewNode(int x)
 {
     struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
     temp->data = x;
     temp->left = NULL;
     temp->right = NULL;
     return temp;
 }
 struct BstNode*  insert(struct BstNode* root, int x)
 {
     if(root == NULL)
     {
        return GetNewNode(x);
     }
     else if(x<= root->data)
     {
         root->left = insert(root->left, x);
     }
     else
     {
         root->right = insert(root->right, x);          /* recursive call to traverse*/
     }
    ; return root;
     
 }

void print(struct BstNode* root)
{
    if(root != NULL)
    {
        print(root->left);
        printf("%d ", root->data);                  /* inorder traversal*/
        print(root->right);
    }
}
int search(struct BstNode* root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->data == data)
    {
        return 1;
    }
    else if(root->data < data)
    {
        return search(root->left, data);
    }
    else if(root->data > data)
    {
        return search(root->right, data);
    }
}
int findmin(struct BstNode* root)
{
    struct BstNode* current = root;
    if(root == NULL)
    {
        printf(" The tree is empty \n");
        return -1;
    }
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
    
    
}
int findmax(struct BstNode* root)
{
    struct BstNode* current = root;
    if(root == NULL)
    {
        printf(" the tree is empty");
        return -1;
    }
    while(current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int max (int x, int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int findheight(struct BstNode* root)
{
    if(root == NULL)
    {
        return -1;
    }
    return max(findheight(root->left), findheight(root->right)) + 1;
}
 int main ()
 {
 root = insert(root, 20);
 root = insert(root, 30);
 root = insert(root, 10);
 root = insert(root, 40);
 int min, max;
 min = findmin(root);
 max = findmax(root);
 int height = findheight(root);
 printf(" The height is %d \n", height); 
 printf(" min is %d\n max is %d \n", min, max);
print(root);
int n; 
printf("Enter the number to be searched");
scanf("%d", &n);
if(search(root, n) == 1)
{
    printf("found");

}
else 
{
    printf("not found");
}
}