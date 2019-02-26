#include<stdio.h>
#define mod 1000000007

long long int gcdExtended(long long int a,long long int b,long long int *x,long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
long long int modInverse(long long int a,long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(a, m, &x, &y);
    long long int res = (x%m + m) % m;
    return res;
}
long long int power(long long int x,long long int y)
{
    long long int res = 1;
    x=x%mod;
 	while (y > 0)
   	{
          if (y & 1)
               res=((res%mod)*(x%mod))%mod;

            y = y >> 1;
            x =((x%mod)*(x%mod))%mod;
    }
    return res;
}
int main()
{
	long long int ans,t,n,k,i,prod,temp;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		ans=0;
		if(k==1)
		{
			printf("1\n");
			continue;
		}
		prod=power(k,n)-1;
		ans=((k%mod)*(prod%mod))%mod;
		//printf("%lld\n",ans);
		temp=modInverse(k-1,mod);
		ans=(ans*temp)%mod;
		printf("%lld\n  %lld\n",k-1,temp);
		printf("%lld\n",ans);
	}
}
