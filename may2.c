#include<stdio.h>
int main()
{
    long long int cnt,t,w,n,k,i,j,m,b[10000000001],a[100001],out;
    //unsigned long long int fib[100001],result;
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(k=0,i=0;i<n;i++)
        {
            for(j=0;j<n;j++,k++)
                {
                    b[k]=a[i]+a[j];
                }
        }
        out=b[0];
        for(i=1;i<n*n;i++)
            out=out^b[i];
        printf("%lld\n",out);
    }
}
