#include<stdio.h>

int main()
{
    int n,k,q,x,y,i1,i2,j1,j2,cnt[1000]={0},a[150][150]={0},ans,z,i,j;
    scanf("%d%d%d",&n,&k,&q);
    short int board[150][150]={0};
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        board[x-1][y-1]=1;
    }
    a[0][0]=board[0][0];
    for(j2=1;j2<n;j2++)
    {
        i2=0;
        a[i2][j2]=a[i2][j2-1]+board[i2][j2];
    }
    for(i2=1;i2<n;i2++)
    {
        j2=0;
        a[i2][j2]=a[i2-1][j2]+board[i2][j2];
    }
    for(i2=1;i2<n;i2++)
    {
        for(j2=1;j2<n;j2++)
        {
            a[i2][j2]=a[i2][j2-1];
            for(i=0;i<=i2;i++)
            {
                a[i2][j2]+=board[i][j2];
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    for(i2=0;i2<n;i2++)
    {
        for(j2=0;j2<n;j2++)
        {
            cnt[a[i2][j2]]++;
            //printf("cnt+00 %d\n",a[i2][j2]);
        }
    }
    for(i1=1;i1<n;i1++)
    {
        j1=0;
        for(i2=i1;i2<n;i2++)
        {
            for(j2=j1;j2<n;j2++)
            {
                ans=a[i2][j2]-a[i1-1][j2];
                cnt[ans]++;
               // printf("cnt+i0 %d\n",ans);
            }
        }
    }

    for(j1=1;j1<n;j1++)
    {
        i1=0;
        for(i2=i1;i2<n;i2++)
        {
            for(j2=j1;j2<n;j2++)
            {
                ans=a[i2][j2]-a[i2][j1-1];
                cnt[ans]++;
                //printf("cnt+0j %d\n",ans);
            }
        }

    }
    //printf("okay\n");
    for(i1=1;i1<n;i1++)
    {
        for(j1=1;j1<n;j1++)
        {
            for(i2=i1;i2<n;i2++)
            {
                for(j2=j1;j2<n;j2++)
                {
                    ans=a[i2][j2]-a[i2][j1-1]-a[i1-1][j2]+a[i1-1][j1-1];
                    cnt[ans]++;
                    //printf("cnt+ij %d\n",ans);
                }
            }
        }
    }
    //printf("%d ",cnt[0]);
   /* for(i=0;i<n+4;i++)
    {
        //cnt[i]+=cnt[i-1];
        printf("%d ",cnt[i]);
    }
    printf("\n%d ",cnt[0]);
    */
    for(i=1;i<n;i++)
    {
        cnt[i]+=cnt[i-1];
        //printf("%d ",cnt[i]);
    }
    //printf("\n");
    long long int out=0;
    for(i=0;i<q;i++)
    {
        scanf("%d",&z);
        out+=cnt[z];
    }
    printf("%lld\n",out);
}
