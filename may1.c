#include<stdio.h>
int main()
{
    int cnt,t,w,n,k,i,j,m,prime[300],a[1001],flag,mark;
    //unsigned long long int fib[100001],result;
    scanf("%d",&t);
    prime[0]=2;k=1;
    for(i=3;i<225;i++)
    {
        flag=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            prime[k]=i;k++;
        }
    }
    for(w=0;w<t;w++)
    {
        mark=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(j=0;j<k;j++)
        {
            cnt=0;
            for(i=0;i<n;i++)
                if(a[i]%prime[j]==0) cnt++;
            if(cnt==n) {mark=0;break;}
        }
        if(mark==0) printf("-1\n");
        else printf("0\n");
    }
}

