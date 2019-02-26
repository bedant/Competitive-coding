#include<stdio.h>
#include<math.h>
int mod=1000000007;
unsigned long long int powmod(unsigned long long int base,unsigned long long int pow)
{
   unsigned long long int res=1;
   while(pow)
   {
         if (pow%2!=0)  res=(res*base)%mod;
         base=(base*base)%mod;
         pow/=2;
         //printf("    %llu %llu\n",base,res);
   }
   //printf("  %d\n",res);
   return res;
}
int main()
{
    long long int wt;
    unsigned long long int t,n,w,out,ans;
    scanf("%llu",&t);
    for(w=0;w<t;w++)
    {
        scanf("%llu%lld",&n,&wt);
        if(wt>=0 && wt<9) out=9-wt;
        else if(wt<0 && wt>=-9) out=10+wt;
        else out=0;
        if(wt==0) out=9;
        ans=powmod(10,n-2);
        ans=(out*ans)%mod;
        //printf("%d %d\n",(int)(pow(10,n-2)*out),(int)(pow(10,9)+7));
        printf("%llu\n",ans);

    }
}
