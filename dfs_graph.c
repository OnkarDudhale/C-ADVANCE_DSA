#include<stdio.h>
struct stack
{
    int data[max];
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
    if(s.top==max-1)
    return 1;
    else
    return 0;
}
void push(int num)
{
    if(isfull())
    printf("stack overflow..");
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
    printf("stack underflow..");
    else
    {
        val=s.data[s.top];
        s.top--;
        return val;
    }
}
void dfs(int g[20][20],int n)
{
}
void main()
{
   int g[20][20],n,i,j;
   printf("Enter number of Vertex:");
   scanf("%d",&n);
   printf("Enter graph in form of matrix:");
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%d",&g[i][j]);
       }
   }
   dfs(g,n);
}