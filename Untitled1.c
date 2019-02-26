#include<stdio.h>
int max(int a,int b)
{
if(a>b) return a;
return b;
}
int main()
{
    int i,j,n,m,w,t,out=1;
    int a[101][101];
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        out=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        if(a[0][0]==-1) a[0][0]=1;
        for(j=1;j<m;j++)
        {
            if(a[0][j]==-1) a[0][j]=a[0][j-1];
        }
        for(i=1;i<n;i++)
        {
            if(a[i][0]==-1) a[i][0]=a[i-1][0];
        }
        for(i=1;i<n;i++)
            for(j=1;j<m;j++)
            {
                if(a[i][j]==-1) a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        for(i=1;i<n;i++)
        {
            if(a[i][0]<a[i-1][0]) {out=0;break;}
        }
    if(out)
        {
        for(j=1;j<m;j++)
        {
            if(a[0][j]<a[0][j-1]) {out=0;break;}
        }
        }
    if(out)
        {
        for(i=1;i<n;i++)
            for(j=1;j<m;j++)
            {
                if(a[i][j]<a[i-1][j] || a[i][j]<a[i][j-1])
                {
                    out=0;break;
                }
            }
        }
        if(!out)
        printf("-1\n");
        else
        {
             for(i=0;i<n;i++)
             {
                for(j=0;j<m;j++)
                {
                    printf("%d ",a[i][j]);
                }
                printf("\n");
             }
        }
    }
}
