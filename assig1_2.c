#include<stdio.h>
int main()
{
    int tempr,templ,right,left,a[100000],sum=0,max_sum=0,n,i,lsum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    left=0;right=0;templ=0;tempr=0;
    while(1)
    {
        for(;a[tempr]>=0 && tempr<n;tempr++)
        {
            sum+=a[tempr];
            printf("r %d %d %d %d %d\n",sum,max_sum,tempr,left,right);
        }
        if(sum>max_sum)
        {
            right=tempr-1;max_sum=sum;
        }
        lsum=sum;
        for(templ=left;templ<tempr;templ++)
        {
            lsum-=a[templ];
            if(lsum>max_sum)
            {
                left=templ;max_sum=lsum;
                sum=lsum;
            }
            printf("l %d %d %d %d %d\n",lsum,max_sum,templ,left,right);
        }
        for(;a[tempr]<0 && tempr<n;tempr++)
        {
            sum+=a[tempr];
        }
        if(tempr==n) break;
    }
    printf("%d %d %d",right,left,max_sum);
}
