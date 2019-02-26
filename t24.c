#include<stdio.h>
#include<math.h>
#define mods 1000000007;
long long int power(long long int base, long long int exp, long long int modulus) {
  base %= modulus;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
  long long int invert_mod(  long long a,   long long p) {
    //if(a==0) return -1;
      long long ex = p-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*a) % p;
        }
        a = (a*a) % p;
        ex /= 2;
    }
    return result;
}
int main()
{
      long long int n,k,t,w,inv_d,num,res;
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        scanf("%lld%lld",&n,&k);
        if(k==1) {printf("%lld\n",n);continue;}
        inv_d=invert_mod(k-1,1000000007)%1000000007;
        num=power(k,n+1,1000000007)%1000000007;
        //printf("%  lld\n",num);
        num=((num+1000000007)-k)%1000000007;
        //printf("%  lld\n",num);
        //printf("%lld %lld\n",num,inv_d);
        res=1LL*(num*inv_d)%1000000007;
        printf("%lld\n",res);
    }
}
