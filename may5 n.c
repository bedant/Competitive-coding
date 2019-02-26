#include<stdio.h>
int main()
{
    int t,w,n,q,k,i,j,a[100000],x,pos,bno,sno;
    //long long int suma,sumb;
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]==x) pos=i
        }
        for(low=1,high=n;;)
        {
            if(x>a[(low+high)/2] && pos<(low+high)/2)
            {
                lth++;
            }
            if(x<a[(low+high)/2] && pos>(low+high)/2)
            {
                htl--;
            }
        }
