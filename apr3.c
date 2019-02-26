#include<stdio.h>
#include<math.h>
int main()
{
    int w,t,n,i,j,k,a[100001];
    unsigned long long int cnt;
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        unsigned long long int b[2002]={0};
        cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]+1000]+=1;
        }
        for(i=0;i<2001;i++)
        {
            cnt+=b[i]*(b[i]-1)/2;
            for(j=i+1;j<2001;j++)
            {
               if(b[i]*b[j] && (i+j)%2==0 && b[(i+j)/2])
               {
                cnt+=b[i]*b[j];
                //printf("a[%d]=%d a[%d]=%d a[%d]=%d\n",i,b[i],j,b[j],(i+j)/2,b[(i+j)/2]);
               }
                //printf("  %d\n",cnt);
            }
        }
        printf("%llu\n",cnt);
    }
}
