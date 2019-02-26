#include<stdio.h>
int lth,htl;
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
void find(int x,int a[],int low,int high,int pos)
{
    //printf("cnt=%d\n",cnt);
    int mid=(low+high)/2;
    if(x==a[mid]) return;
    if(x<a[mid] && pos<mid)
    {
        //printf(" 1\n");
        find(x,a,low,mid-1,pos);
    }
    if(x>a[mid] && pos>mid)
    {
        //printf(" 2\n");
        find(x,a,mid+1,high,pos);
    }
    if(x>a[mid] && pos<mid)
    {
        //printf(" 3\n");
        lth++;
        //cnt++;
        find(x,a,low,mid-1,pos);
    }
    if(x<a[mid] && pos>mid)
    {
        //printf(" 4\n");
        htl++;
        //cnt++;
        find(x,a,mid+1,high,pos);
    }

}
int main()
{
    int t,w,n,q,k,i,j,a[100002],x,pos,bno,sno,cnt;
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
            lth=0;htl=0;
            find(x,a,1,n,pos);
            cnt=max(lth,htl);
            if(lth>bno || htl>sno) cnt=-1;
            printf("%d\n",cnt);
        }
    }
}
