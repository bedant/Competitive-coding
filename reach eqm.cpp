#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mods 1000000007
long long int power(long long int a,long long int b, long long int mod){
	long long int x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}
long long int modular_inverse(long long int n, long long int mod){
	return power(n, mod-2, mod);
}
int main()
{
    long long int n,k,cnt,a,deno,num,out;
    cin>>n>>k;
    a=n;
    for(cnt=0;;a/=2)
    {
        if(a%2==0) cnt++;
        else break;
    }
    a=n/pow(2,cnt);
    deno=power(2,n-1-cnt,mods);
    deno=deno%mods;
    num=mods+deno-a;
    num=num%mods;
    //fact=gcd(num,deno);
    //num/=fact;deno/=fact;
    out=(num*modular_inverse(deno,mods))%mods;
    cout<<out<<endl;
}
