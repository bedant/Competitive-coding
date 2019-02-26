#include<stdio.h>
int maxm(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    int low,high,n,mid,c,i,rem=1000,broken=0;
    scanf("%d%d",&n,&c);
    //low=1;high=n;
    for(i=1;i<=388;i++)
    {
        printf("1 %d\n",i*387);
        fflush(stdout);
        scanf("%d",&broken);
        if(broken)
        {
            rem-=c;break;
        }
        rem--;
    }
    high=i*387;low=high-387;
    printf("2\n");
    mid=low+110;
    printf("1 %d\n",mid);
    fflush(stdout);
    scanf("%d",&broken);
    if(broken)
    {
        rem-=c;
        printf("2\n");
        fflush(stdout);
        broken=0;
        high=mid;
    }
    else
        low=mid;
    for(i=maxm(1,low);i<=high;i++)
    {
        printf("1 %d\n",i);
        fflush(stdout);
        scanf("%d",&broken);
        if(broken)
        {
            rem-=c;
            break;
        }
        rem--;
    }
    printf("3 %d\n",i);
    fflush(stdout);
    //printf("%d",rem);
}
