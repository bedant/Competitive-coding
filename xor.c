#include<stdio.h>

void dec2bin(int c,long int sum[])
{
   int i = 0;
   for(i = 31; i >= 0; i--){
     if((c & (1 << i)) != 0){
       sum[i]+=1;
     }
   }
}
int main()
{
    int n,q,r,l,i,j,a[100000];
    unsigned long long int out;
   scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<q;j++)
    {
        int sum[40]={0};out=0;
        scanf("%d%d",&l,&r);
        for(i=l;i<=r;i++)
        {
            dec2bin(a[i-1],sum);
        }
        //for(i=30;i>=0;i--) printf("sum[%d]=%d ",i,sum[i]);
        //printf("\n");
        for(i=30;i>=0;i--)
        {

            if(2*sum[i]<=(r-l+1)) {out+=pow(2,i);}
        }
        printf("%llu\n",out);
    }

}

