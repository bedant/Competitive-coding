#include<stdio.h>
int main()
{
    int low,prelow,high,i,cnt,broken,rem,n,c;
    scanf("%d%d",&n,&c);
    broken=0;
    prelow=0;
    low=0;
    cnt=0;
    high=n;
    rem=1000;
    while(rem)
    {

        if(broken==1)
        {
            prelow=low;
            high=low+cnt;
            low=low+cnt/2;
            cnt=0;
            printf("2\n");
            rem-=c;
            broken=0;
            if(low+3>high)
                break;
        }
        else if(broken==0)
        {
            cnt*=2;
            if(cnt==0) cnt=1;
            if(low+cnt<high)
            {
                printf("1 %d\n",low+cnt);
                fflush(stdout);
                scanf("%d",&broken);
                //cnt*=2;
                rem--;
            }
            else
            {
                broken=1;
                {
                    prelow=low;
                    high=low+cnt;
                    low=low+cnt/2;
                    cnt=0;
                    //printf("2\n");
                    //rem-=c;
                    broken=0;
                    if(low+3>high)
                        break;
                }
            }
        }
    }
    for(i=low;i<low+6;i++)
    {
        printf("1 %d\n",i);
        fflush(stdout);
        scanf("%d",&broken);
        if(broken)
            break;
    }
    printf("3 %d\n",i);
    fflush(stdout);
    printf("%d\n",rem);
}
