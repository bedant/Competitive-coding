#include<stdio.h>
int main()
{
    int n,m,k,t,w,i,j,flag,l,g,r,out=0,cnt=0,a[100000];
    char opt,b[100000]={"n"};
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        out=1;cnt=0;
        scanf("%d%d%d",&n,&m,&g);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<m;j++)
        {
            flag=0;
            scanf(" %c %d%d",&opt,&l,&r);
            for(i=l;i<=r;i++)
            {
                b[i]=opt;
            }
        }
            for(i=1;i<=n;i++)
            {
                if(b[i]=="I" && !flag) {Iarr[k]=i;k++;flag=1;}
                if(b[i]!="I" && flag) {Iarr[k]=i-1;k++;flag=0;}
            }
            for(i=1;i<=n;i++)
            {
                if(b[i]=="D" && !flag) {Darr[k]=i;k++;flag=1;}
                if(b[i]!="D" && flag) {Darr[k]=i-1;k++;flag=0;}
            }




















            if(flag)
            {
                if(opt=='I')
                {
                    for(k=i;;k++)
                    {
                        if(k>=r) break;
                        a[k+1]=a[k]+1;
                    }
                }
                if(opt=='D')
                {
                    for(k=i;;k--)
                    {
                        if(k<=l) break;
                        a[k-1]=a[k]-1;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            printf("%d    %d\n",a[i],k);
            if(a[i]>g) {out=0;break;}
            if(a[i]==-1) cnt++;
        }
        if(out) printf("%d\n",g*cnt);
        else printf("0\n");
    }
}

