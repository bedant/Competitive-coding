#include<stdio.h>
int is_pr(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
        if(a%i==0) return 0;
    return 1;
}
int main()
{
    int w,t,n,i,min,a[101],flag=0;
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1) flag=1;
        }
        min=101;
        for(i=0;i<n;i++)
        {
            if(a[i]!=1 && a[i]<min && is_pr(a[i]) )
                min=a[i];
        }
        if(flag==1 && min<101) printf("%d\n",min);
        else printf("-1\n");
    }
}
