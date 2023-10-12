#include<stdio.h>
void main()
{
    int g[50][50],i,j,n,c1,c2;
    printf("Enter Number of Vertex:");
    scanf("%d",&n);
    printf("Enter Graph in form of matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        c1=0,c2=0;
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==1)
            c1++;
            if(g[j][i]==1) 
            c2++;
        }
    printf("\nInComing Edges to Vertex V%d is:%d",i,c2);
    printf("\nOutGoing Edges from Vertex V%d is:%d",i,c1);
    printf("\nTotal Edges Vertex V%d is:%d",i,c1+c2);
    }
    

}