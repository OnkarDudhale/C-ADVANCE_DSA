#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *right,*left;
}node;
node *create(node *root)
{
    int i,n,num;
    node *newnode,*temp,*parent;
    printf("Enter limit:");
    scanf("%d",&n);
    printf("Enter numbers:");
    for(i=1;i<=n;i++)
    {
        newnode=(node *)malloc(sizeof(node));
        scanf("%d",&num);
        newnode->data=num;
        newnode->left=newnode->right=NULL;
        if(root==NULL)
        root=newnode;
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                parent=temp;
                if(temp->data<newnode->data)
                temp=temp->right;
                else
                temp=temp->left;
            }
            if(parent->data<newnode->data)
            parent->right=newnode;
            else
            parent->left=newnode;
        }
    }
    return root;
}
void inorder(node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\nInorder is:%d\t",root->data);
        inorder(root->right);
    }
}
int leaf_node(node *root)
{
    node *temp=root;
    static int count=0;
    if(temp!=NULL)
    {
        if(temp->right==NULL&&temp->left==NULL)
        count++;
        leaf_node(temp->left);
        leaf_node(temp->right);
    }
    return count;
}
int nonleaf_node(node *root)
{
    node *temp=root;
    static int count=0;
    if(temp!=NULL)
    {
        if((temp->right!=NULL&&temp->left!=NULL)||(temp->left!=NULL||temp->right!=NULL))
        count++;
        nonleaf_node(temp->left);
        nonleaf_node(temp->right);
    }
    return count;
}
int allnodes(node *root)
{
    node *temp=root;
    static int count=0;
    if(temp!=NULL)
    {
        count++;
        allnodes(temp->left);
        allnodes(temp->right);
    }
    return count;
}
void main()
{
    node *root=NULL;
    int ch,c;
    do
    {
        printf("\nenter choice:");
        scanf("%d",&ch);
        switch (ch)
       {
        case 1:root=create(root);
            break;
        case 2:inorder(root);
            break;
        case 3:c=leaf_node(root);
            printf("\ncounted leaf nodes are:%d",c);
            break;
        case 4:c=nonleaf_node(root);
            printf("\ncounted non-leaf nodes are:%d",c);
            break;
        case 5:c=allnodes(root);
             printf("\ncounted nodes are:%d",c);
             break;
        
        default:printf("INVALID case....");
           break;
       }
    }while(ch!=6);
}