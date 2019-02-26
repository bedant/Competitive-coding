#include<stdio.h>
int lth,htl,right,left;
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int find(int x,int a[],int low,int high,int pos)
{
    int mid;
    for(mid=(low+high)/2;a[mid]!=x;mid=(low+high)/2)
    {
        if(x>a[mid] &&  pos>mid)
        {
            right++;
            low=mid+1;
        }
        else if(x<a[mid] && pos<mid)
        {
            left++;
            high=mid-1;
        }
        else if(x>a[mid] && pos<mid)
        {
            left++;
            lth++;
            high=mid-1;
        }
        else if(x<a[mid] && pos>mid)
        {
            right++;
            htl++;
            low=mid+1;
        }
    }
    return 0;
}
int main()
{
    int t,w,n,q,k,i,j,a[100002],x,pos,bno,sno,cnt,ret;
    //long long int suma,sumb;
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<q;j++)
        {
            bno=0;sno=0;
            scanf("%d",&x);
            for(i=1;i<=n;i++)
            {
                if(a[i]>x) bno++;
                if(a[i]==x) pos=i;
                if(a[i]<x) sno++;
            }
            lth=0;htl=0;left=0;right=0;
            ret=find(x,a,1,n,pos);
            cnt=max(lth,htl);
            if(left>bno || right>sno) cnt=-1;
            printf("%d\n",cnt);
        }
    }
}
