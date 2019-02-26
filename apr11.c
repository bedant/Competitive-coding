#include<stdio.h>
#include<math.h>
#include<string.h>
long long int min(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
int main()
{
    long long int w,n,i,j,k,min1,min2,min3,c[1001],term,aa,bb;
    int t[1001];
    scanf("%lld",&n);
    min1=100001;min2=100001;min3=100001;
    for(i=0;i<n;i++)
        scanf("%lld",&c[i]);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t[i]);
        if(t[i]==1)
        {
            min1=min(min1,c[i]);
        }
        if(t[i]==2)
        {
            min2=min(min2,c[i]);
        }
        if(t[i]==3)
        {
            min3=min(min3,c[i]);
        }
    }
    printf("%lld",min(min1+min2,min3));
}
