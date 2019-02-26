#include<stdio.h>
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int prev(int a[],int k,int i,int n)
{
    int maxm=0,j;
    for(j=max(0,i-k);j<min(n,i+k+1);j++)
    {
        if(a[j]<a[i] && a[j]>maxm)
            maxm=a[j];
        else if(a[j]==a[i] && j!=i)
            maxm=a[i]-1;
    }
    return maxm;
}
int sum(int a[],int k,int n)
{
    int flag=1,i,temp,summ=0,b[100000];
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    while(flag)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            temp=b[i];
            b[i]=prev(b,k,i,n)+1;
            if(temp!=b[i]) flag=1;
        }
    }
    for(i=0;i<n;i++)
    {
        //printf("%d ",b[i]);
        summ+=b[i];
    }
    //printf("\n");
    return summ;
}
int main()
{
    int t,n,i,l,h,a[100000],k,out_k,s,su,check;
    scanf("%d",&t);
    while(t--)
    {
        out_k=-1;check=1;
        scanf("%d%d",&n,&s);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i>1 && a[i]!=a[i-1])
                check=0;
        }
     if(check==0)
     {
        for(l=0,h=n;;)
        {
            k=l+(h-l)/2;
            su=sum(a,k,n);
      //      printf("k %d su %d\n",k,su);
            if(su<=s)
            {
                out_k=k;
                if(l>=h) break;
                l=k+1;
            }
            else
            {
                if(l>=h) break;
                h=k-1;
            }
        }
        printf("%d\n",out_k+1);
     }
     else
     {
         if(s<=n) printf("%d\n",n+1);
         else printf("0\n");
     }
    }
}
