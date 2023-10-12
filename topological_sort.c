#include<stdio.h>
#include<string.h>
#define MAX 5
struct stack
{
   int data[MAX];
   int top;
}s;
void init()
{
  s.top=-1;
}
int isempty()
{
  if(s.top==-1)
    return 1;
  else
    return 0;
}
int isfull()
{
   if(s.top==MAX-1)
     return 1;
   else
     return 0;
}
void push(int num)
{
  if(isfull())
  {
     printf("Stack is full");
  }
  else
  {
    s.top++;
    s.data[s.top]=num;
  }
}
int pop()
{
  int val;
   if(isempty())
   {
      printf("Stack is empty");
   }
   else
   {
     val=s.data[s.top];
     s.top--;
   }
  return val;
}
void tsort(int a[10][10],int n)
{
   int i,j,v,w;
   int visited[10]={0};
   int inde[10]={0};
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         inde[i]=inde[i]+a[j][i];
      }
   }
  init();
  while(1)
  {
    for(v=0;v<n;v++)
    {
        if(inde[v]==0&&visited[v]==0)
        {
          push(v);
          visited[v]=1;
           printf("v%d\t",v);
        }
    }
     if(isempty())
       break;
     v=pop();
      for(w=0;w<n;w++)
      {
          if(a[v][w]==1)
	     inde[w]=inde[w]-1;
      }
  } //while
}//function

int main()
{
  int a[10][10],i,j,n;

  printf("Enter limit:");
  scanf("%d",&n);
  printf("Enter matrix:");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
       scanf("%d",&a[i][j]);
    }
  }
 tsort(a,n);
 
}