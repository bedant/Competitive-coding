#include<stdio.h>
int main()
{
    int t,n,k,i,sum;
    int a[30001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        sum=0;
        //scanf("%d",&a[0]);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i%2==0)
            {
                //printf("if 1\n");
                if(a[i] && sum>=0) sum++;
                else if(a[i] && sum<0) {sum--;a[i]=-a[i];}
            }
            else
            {
                //printf("if 2\n");
                if(a[i] && sum<0) sum++;
                else if(a[i] && sum>=0) {sum--;a[i]=-a[i];}
            }
            //printf("sum= %d\n",sum);
        }
        if(sum>=k || sum<=-k) printf("1\n");
        else printf("2\n");
    }
}
