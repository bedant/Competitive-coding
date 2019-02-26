#include<stdio.h>
int main()
{
    int low,prelow,high,i,cnt,broken,rem,n,c;
    scanf("%d%d",&n,&c);
    broken=0;
    prelow=0;
    low=0;
    cnt=1;
    high=n;
    rem=1000;
    while(rem)
    {

        if(broken==1)
        {
            prelow=low;
            high=low+cnt;
            low=low+cnt/2;
            cnt=1;
            printf("2");
            rem-=c;
            broken=0;
            if(low+3>high)
                break;
        }
        else if(broken==0)
        {
            cnt*=2;
            printf("1 %d",low+cnt);
            scanf("%d",&broken);
            //cnt*=2;
            rem--;
        }
    }
    for(i=low;i<low+6;i++)
    {
        printf("1 i\n");
        scanf("%d",broken);
        if(broken)
            break;
    }
    printf("3 %d\n",i-1);
}
