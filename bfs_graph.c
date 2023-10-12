#include<stdio.h>
#define max 100
struct queue 
{
  int data[max];
  int rear,front;
}q;
void initq()
{
    q.front=q.rear=-1;
}
int isempty()
{
    if(q.rear==q.front)
    return 1;
    else
    return 0;
}
int isfull()
{
    if(q.rear==max-1)
    return 1;
    else
    return 0;
}
void addq(int num)
{
    if(isfull())
    printf("Queue is full..");
    else
    {
        q.rear++;
        q.data[q.rear]=num;
    }
}
int removeq()
{
    int val;
    if(isempty())
    printf("queue is empty..");
    else
    {
    q.front++;    
    val=q.data[q.front];
    return val;
    }
}
void bfs(int g[20][20],int n)
{
    int i,j,v;
    int visited[20]={0};
    initq();
    v=0;
    visited[0]=1;
    addq(v);
    while(!isempty())
    {
        static int k=0;
        v=removeq();
        printf("V%d:%d\t",k,v);
        k++;
        for(i=0;i<n;i++)
        {
            if(g[v][i]==1 && visited[i]==0)
            {
                addq(i);
                visited[i]=1;
            }
        }//for
    }//while
}
void main()
{
    int g[20][20],i,j,n;
    printf("Enter Number of verties:");
    scanf("%d",&n);
    printf("Enter graph in form of matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bfs(g,n);
}


