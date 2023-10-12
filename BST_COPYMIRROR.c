#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *right,*left;
}NODE;
NODE *create(NODE *root)
{
    NODE *newnode,*temp,*parent;
    int n,i;
    printf("Enter limit:");
    scanf("%d",&n);
    printf("Enter numbers:");
    for(i=1;i<=n;i++)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        scanf("%d",&newnode->info);
        newnode->left=newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while (temp!=NULL)
            {
                parent=temp;
                if(temp->info>newnode->info)
                temp=temp->left;
                else
                temp=temp->right;
            }
            if(parent->info>newnode->info)
            parent->left=newnode;
            else
            parent->right=newnode;
        }
    }
    return root;
}
void inorder(NODE*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
NODE *copy(NODE *root)
{
      NODE *newnode;
      if(root==NULL)
      return NULL;

      while (root!=NULL)
      {
        newnode=(NODE*)malloc(sizeof(NODE));  
        newnode->info=root->info;
        newnode->right=copy(root->right);
        newnode->left=copy(root->left);
        return newnode;
      }      
}
/*NODE *mirror(NODE *root)
{
      NODE *newnode;
      if(root==NULL)
      {
          return NULL;
      }

      while(root!=NULL)
      {
        newnode=(NODE *)malloc(sizeof(NODE));
        newnode->info=root->info;
        newnode->left=mirror(root->right);
        newnode->right=mirror(root->left);
      
      }
  
}*/
int mirror(NODE* root)
{
    if (root == NULL)
        return NULL;
    else {
        NODE* temp;
 
        //do the subtrees
        mirror(root->left);
        mirror(root->right);
 
        //swap the pointers in this node
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
void main()
{
    NODE *root=NULL;
    root=create(root);
    
    mirror(root);
    inorder(root);
    
}