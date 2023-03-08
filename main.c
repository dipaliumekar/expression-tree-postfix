/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>

struct tree
{
  char data;
  struct tree *left,*right;
};

int top= - 1;
struct tree *stack[20];
struct tree *root1;
void push(struct tree*);
struct tree*pop();
void inorder(struct tree*);
void preorder(struct tree*);
void operand(char);
void operator(char);
int main()
{
   char s[50];
   int i=0;
   printf("Enter the postfix expression:\n");
   scanf(" %s",s);
   
 while(s[i]!='\0')
 {
     if(isalnum(s[i]))
     {
         printf("\noperand: %c\n",s[i]);
         operand(s[i]);
     }
     else
     {
         printf("\noperator:%c\n",s[i]);
         operator(s[i]);
     }
     i++;
 }
    printf("\nThe traversal of tree is \n");
    inorder(stack[top]);
    printf("\npreorder traversal:\n");
    preorder(stack[top]);
    return 0;
}
 
void push(struct tree*root)
{
    top=top+1;
    stack[top]=root;
    printf("\nEnter pushed is %p\n",stack[top]);
}


struct tree*pop()
{
    return stack[top--];
}

void inorder(struct tree*root)
{
    if(root==NULL)
    {
        return;
    }
    else 
    {
        if(root!=NULL)
        {
           inorder(root->left);
        }
        printf("%c\n",root->data);
        inorder(root->right);
}
}
void operand(char a)
{
    struct tree*root=(struct tree*)malloc(sizeof(struct tree));
    root->data=a;
    root->left=NULL;
    root->right=NULL;
    printf("\n%c",root->data);
    push(root);
    
    
}


void  operator(char b)
{
    struct tree*root=(struct tree*)malloc(sizeof(struct tree));
    root->data=b;
    printf("\n%c",root->data);
    root->right=pop();
    root->left=pop();
    push(root);
}

void preorder(struct tree*root)
{
    if(root==NULL)
    {
        return;
    }
    else 
    {
        if(root!=NULL)
        {
        
        printf("%c\n",root->data);
        inorder(root->left);
        inorder(root->right);
        }
    }
}

void traversal(struct tree*root)
{
    
}