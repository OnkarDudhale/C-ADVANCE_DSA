#include<stdio.h>
#include<stdlib.h>
#define MAX 50
    struct node
    {
      int info;
      struct node *left,*right;
    };

 struct Queue
{
	struct node *data[MAX];
	int front,rear;
}Q;
void initq()
{
	 Q.front=Q.rear=-1;
}
int isempty()
{
  if(Q.front==Q.rear)	
     return 1;
  else
    return 0;   
}
int isfull()
{
  if(Q.rear==MAX-1)	
     return 1;
  else
    return 0;   
}
void addq(struct node *treedata)
{
	if(isfull())
	  printf("Queue is overflow..");
	else
	{
	 Q.rear++;   
	  Q.data[Q.rear]=treedata;	
	}
}
struct node * removeq()
{
	if(!isempty())
	{
		return Q.data[++Q.front];
	}
}
void Disp_Level(struct node *root)
{
	int i,level=0,count=0;
	struct node *temp,*marker=NULL;
	initq();
	addq(root);
	addq(marker);
	printf("\n Level=%d",level);
	while(!isempty())
	{
		temp=removeq();
		if(temp==marker)
		{
			level++;
      
			if(!isempty())
			{
				addq(marker);
        printf("\n Level=%d",level);
			}
		}
		else
		{
			printf("\t %d",temp->info);
      count++;
			if(temp->left!=NULL)
			  addq(temp->left);
			if(temp->right!=NULL)
			  addq(temp->right);  
    }
	}
  printf("count:%d",count);
}
struct node *createBST(struct node *root)
{
   struct node * newnode,*temp,*parent;
   int n,i,num;
   printf("Enter limit:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      newnode=(struct node*)malloc(sizeof(struct node));
       printf("Enter value:");
       scanf("%d",&newnode->info);
       newnode->left=newnode->right=NULL;
       if(root==NULL)
       {
	 root=newnode;
       }
       else
       {
	   temp=root;
	   while(temp!=NULL)  
	   {
	      parent=temp;
	       if(newnode->info<temp->info)
		temp=temp->left;
	      else
		temp=temp->right;
	   }
	   if(newnode->info<parent->info)
	      parent->left=newnode;
	   else
	    parent->right=newnode;
       }
   } 
  return root;
}
void inorder(struct node *root)
{
   if(root!=NULL)
  {
      inorder(root->left);
      printf("%d\t",root->info);
      inorder(root->right);
  }
}
void preorder(struct node *root)
{
   if(root!=NULL)
  {
      printf("%d\t",root->info);
      preorder(root->left);
      preorder(root->right);
  }
}
void postorder(struct node *root)
{
   if(root!=NULL)
  {
      postorder(root->left);
      postorder(root->right);
      printf("%d\t",root->info);
  }
}
int main()
{
	int ch,val;
    struct node *root=NULL,*temp;
    do
    {
    	printf("\n 1-create \n 2-inorder \n 3-pre \n 4-post \n 5-Disp Levelwise:");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:   root=createBST(root);
             break;
            case 2: 
             printf("\n Display Inorder:");
             inorder(root);
             break;
            case 3: 
             printf("\n Display Preorder:");
             preorder(root);
             break;
            case 4: 
             printf("\n Display Postorder:");
             postorder(root);
             break;
            case 5:
            	Disp_Level(root);
            	break;
		}
	}while(ch<6);
}