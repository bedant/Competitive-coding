#include<stdio.h>
long long int minm(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
int main()
{
    //short int b[1000000001]={0};
    long long int t,n,i,k,x,a[20002],min,temp,max,cnt,sum,temsum;
    scanf("%lld",&t);
    while(t--)
    {
        temsum=0;sum=0;
        //short int b[1000000001]={0};
        scanf("%lld%lld%lld",&n,&k,&x);
        for(i=0;i<k;i++)
        {
            scanf("%lld",&a[i]);
            temsum+=a[i];
            if(a[i]<min) min=a[i];
            //b[a[i]]=1;
        }
        max=minm(min+x,1000000000);
        cnt=0;
        for(i=0;i<k;i++)
        {
            if(a[i]>=max-(n-k)+1-cnt )
            {
                cnt++;
                sum-=a[i];
            }
        }
        sum+=temsum;
        temp=max-(n-k)+1-cnt;
        sum=sum+max*(max+1)/2-temp*(temp+1)/2;
        printf("%lld\n",sum);
    }
}
