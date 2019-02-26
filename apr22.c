#include<stdio.h>
#include<math.h>
long long int mod=1000000007;
int main()
{
    long long int t,w,n,wt,i,ans,way;
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        long long int a[10000]={0};
        scanf("%lld%lld",&n,&wt);

        if(wt>=0 && wt<9) way=9-wt;
        else if(wt<0 && wt>=-9) way=10+wt;
        else way=0;
        a[n-2]=way;
        ans=a[n-2];
        for(i=n-2;i>0;i--)
        {
            ans=ans%(mod)*10+a[i-1];
        //printf("%lld \n",ans);
        }
        ans=ans%mod;
        printf("%lld\n",ans);
    }
}
