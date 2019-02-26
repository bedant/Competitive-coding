#include<stdio.h>
int main()
{
    int n,i,j,cnt[100][100],count[100]={1},a[100],temp,b,c,k,l;

    scanf("%d",&n);
    for(i=0;i<10;i++)
        {a[i]=i;
        cnt[i][0]=i;}
    for(j=0;j<n;j++)
    {
        scanf("%d %d",&c,&b);
        printf("countinit %d",count[c]);
        if(a[b]>a[c])
        {
            temp=b;b=c;c=temp;
        }
        a[c]=a[b];
        printf("count %d",count[c]);
        for(i=0;i<count[c];i++)
        {
            cnt[b][count[b]+i]=cnt[c][i];
        for(l=0;l<10;l++)
        {for(k=0;k<10;k++)
        printf("inside %d  ",cnt[l][k]);
        printf("\n");
        }
        }
        count[b]+=i;
        for(i=1;i<count[b];i++)
        {
            a[cnt[b][i]]=a[b];
        }
        for(i=0;i<10;i++) printf("%d ",a[i]);
        for(i=0;i<10;i++)
        {for(k=0;k<10;k++)
        printf("%d  ",cnt[i][k]);
        printf("\n");
        }
    }
    printf("union over\n");
    for(i=0;i<10;i++)
    {for(j=0;j<10;j++)
        printf("%d  ",cnt[i][j]);
        printf("\n");
    }
    for(i=0;i<10;i++) printf("%d ",a[i]);
    for(i=0;i<6;i++)
    {scanf("%d %d",&c,&b);
    if(a[c]==a[b]) printf("yes\n");
    }

}
