#include<stdio.h>
int find_a(int a[][405],int n,int k,int b[][405]);
int find_b(int b[][405],int n,int k,int a[][405])
{
    printf("in b %d %d\n",n,k);
    if(b[n][k]!=-1) return b[n][k];
    b[n][k]=2*find_a(a,n-2,k-1,b)+2*find_b(b,n-2,k-1,a)+find_b(b,n-1,k,a);
    return b[n][k];
}
int find_a(int a[][405],int n,int k,int b[][405])
{
    printf("in a %d %d\n",n,k);
    if(a[n][k]!=-1) return b[n][k];
    a[n][k]=find_a(a,n-1,k-1,b)+find_b(b,n-1,k,a);
    return b[n][k];
}
int main()
{
    int a[805][405]={-1},b[805][405]={-1},t,n,k,i,j;
    scanf("%d",&t);
    a[0][0]=1;
    a[1][0]=1;
    a[1][1]=1;
    b[1][0]=1;
    b[1][1]=2;
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                a[i][j]=-1;b[i][j]=-1;
            }
        }
        for(j=0;j<=k;j++)
        {
            if(j==0 || j==1 || j==2) a[1][j]=1;
            a[1][j]=0;
            if(j==1) b[1][j]=2;
            b[1][j]=0;
        }
        a[0][0]=1;
        a[1][0]=1;
        a[1][1]=1;
        b[1][0]=1;
        b[1][1]=2;
        a[0][1]=1;
        b[0][1]=0;
        b[0][2]=0;
        for(j=2;j<=k;j++)
        {
            a[0][j]=0;
            b[0][j]=0;
        }
        printf("%d\n",find_b(b,n,k,a));
    }
}
