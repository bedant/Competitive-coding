#include<stdio.h>
long long int multiply(long long int a,long long int b,long long int mod)
{
    long long int res=0;
    while(b>0)
    {
        if(b%2) res=(res+a)%mod;
        a=(a+a)%mod;
        b=b >> 1;
    }
    return res;
}
long long int power(long long int a,long long int n,long long int mod)
{
    //printf("  %lld\n",a);
    a=(a)%mod;
    //printf("  %lld\n",a);
    long long int result=1;
    while (n > 0)
    {
        if (n%2) result = multiply(result,a,mod);
        a = multiply(a,a,mod);
        n=n >> 1;
   }
   //printf("  %lld\n",result);
  return result;
}
long long int gcd(long long int x,long long int y)
{
    long long int temp;
    while(x%y)
    {
        temp=x;
        x=y;
        y=temp%x;
    }
    return y;
}
int main()
{
    int t;
    long long int n,x,y,ans,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
     //   printf("%lld    %lld    %lld\n",a,b,n);
        x=(a-b);
        if(a-b==0)
        {
            ans=power(a,n,1000000007)+power(b,n,1000000007);
            //ans=ans%1000000007;
            printf("%lld\n",ans%1000000007);
            continue;
        }
        y=(power(a,n,x)+power(b,n,x))%x;
       // printf("nums %lld %lld %lld %lld\n",num1,num2,y,x);
        if(y!=0)
        {
            ans=gcd(x,y);
        }
        else
        {
            ans=x;
        }
        printf("%lld\n",ans%1000000007);
    }
}
