#include<stdio.h>
#include<math.h>
int is_pr(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
   int w,t,k,n,i,j,a[10001],prime[100000],pr_ind,flag;
   for(k=0,i=2;i<100001;i++)
   {
       if(is_pr(i)) {prime[k]=i;k++;}
   }
   pr_ind=k;
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
    if(flag!=1)
    {
    for(k=0;k<pr_ind;k++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]%prime[k]!=0)
            {
                break;
            }
        }
        if(j==n) {flag=2;break;}
    }
    }
    else if(flag==1) printf("YES\n");
    if(flag==2) printf("NO\n");
    if(flag==0) printf("YES\n");
  }
}
