#include<stdio.h>
#include<math.h>
int main()
{
int t,w,n,i,j,k,a[100000];
long long int sum;
scanf("%d",&t);
for(w=0;w<t;w++)
{
    int s[100000]={0},sum[100000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  scanf("%d",&a[i]);
	  if(i>=2) {sum[i]=sum[i-1]+a[i-1];}
	}
	for(i=0;i<n-1;i++)
	{
	  for(j=i+1;j<n;j++)
	    {
         //printf("sum[%d]=%d",j,sum[j]);
	     if(sum[j]<=a[i]) s[j]++;
	     if(sum[j]<=a[j]) s[i]++;
	     sum[j]-=a[i+1];
	    }
	 }
for(i=0;i<n;i++)
printf("%d ",s[i]);
printf("\n");
}
}
