#include<stdio.h>
long long int res_add(unsigned long long int a,unsigned long long int b,unsigned long long int x,unsigned long long int y)
{
    unsigned long long int p=((x%1000000007) * (a%1000000007))%1000000007;
    unsigned long long int q=((y%1000000007) * (b%1000000007))%1000000007;
    return (p+q)%1000000007;
}
int main()
{
    unsigned long long int t,w,n,k,i,j,m,a,b,suma,sumb;
    unsigned long long int fib[100001],result;
    fib[1]=1;fib[2]=1;
    for(i=3;i<100001;i++)
        fib[i]=(fib[i-1]+fib[i-2])%1000000007;
    scanf("%llu",&t);
    for(w=0;w<t;w++)
    {
        suma=0;sumb=0;
        result=0;
        scanf("%llu%llu",&m,&n);
        for(i=0;i<m;i++)
            {scanf("%llu",&a);
            suma+=a;
            suma=suma%1000000007;}
        for(i=0;i<m;i++)
            {scanf("%llu",&b);
            sumb+=b;
            sumb=sumb%1000000007;}
        if(n==1) result+=suma;
        if(n==2) result+=sumb;
        if(n>=3)
        {
            result=res_add(suma,sumb,fib[n-2],fib[n-1]);
        }
        result=((result%1000000007)*(m%1000000007))%1000000007;

                //printf("%d\n",result);
       printf("%llu\n",result);
    }
}
