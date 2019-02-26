#include<stdio.h>
#define mod 1000000007
long long int find_a(long long int a[][405],int n,int k,long long int b[][405]);
long long int find_b(long long int b[][405],int n,int k,long long int a[][405])
{
    //printf("in b %d %d = %d\n",n,k,b[n][k]);
    if(b[n][k]!=-1) return b[n][k];
    b[n][k]=( ( ( 2*find_a(a,n-2,k-1,b) )%mod + (2*find_b(b,n-2,k-1,a) ) % mod  )%mod + find_b(b,n-1,k,a)%mod)%mod;
    return b[n][k];
}
long long int find_a(long long int a[][405],int n,int k,long long int b[][405])
{
    //printf("in a %d %d = %d\n",n,k,a[n][k]);
    if(a[n][k]!=-1) return a[n][k];
    a[n][k]=((find_a(a,n-1,k-1,b)%mod)+(find_b(b,n-1,k,a)%mod))%mod;
    return a[n][k];
}
int main()
{
    long long int a[55][405]={-1},b[55][405]={-1};
    int t,n,k,i,j;
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
        for(i=1;i<=n;i++)
        {
            a[i][0]=1;
            a[i][1]=1;
            b[i][0]=1;
            b[i][1]=2*i;
        }
        printf("%lld\n",find_b(b,n,k,a));
    }
}
