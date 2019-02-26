#include<stdio.h>
long long int htl,lth;
long long int max(long long int a,long long int b)
{
    if(a>b) return a;
    return b;
}
long long int find(long long int a[],long long int x,long long int n,long long int pos)
{
    long long int mid,low,high;
    low=1;high=n;
    for( mid=(low+high)/2 ; a[mid]!=x && low<=high ; mid=(low+high)/2)
    {
        if(pos<mid)
        {
            high=mid-1;
            if(x>a[mid])
            {
                lth++;
            }
        }
        if(pos>mid)
        {
            low=mid+1;
            if(x<a[mid])
            {
                htl++;
            }
        }
    }
}
int main()
{
    long long int w,t,n,q,i,j,a[100002],x,bno,sno,pos,cnt;
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        scanf("%lld%lld",&n,&q);
        for(j=1;j<=n;j++)
            scanf("%lld",&a[j]);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&x);
            bno=0;sno=0;
            for(j=1;j<=n;j++)
            {
                if(a[j]>x) bno++;
                if(a[j]<x) sno++;
                if(a[j]==x) pos=j;
            }
            lth=0;htl=0;
            find(a,x,n,pos);
            cnt=max(lth,htl);
            if(htl>sno || lth>bno) cnt=-1;
            printf("%lld\n",cnt);
        }
    }
}
