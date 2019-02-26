#include<stdio.h>
int main()
{
    int t,w,n,i,j;
    long long int a[100001],xor;
    //unsigned long long int fib[100001],result;
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        xor=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
                xor=xor ^ (2*a[i]);
            }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                {
                    xor= (xor ^ (a[i]+a[j])) ^ (a[i]+a[j]);
                }
        }
        printf("%lld\n",xor);
    }
}

