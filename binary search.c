#include<stdio.h>
int bin_srch( int a[],int val,int l,int r)
{
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[mid]==val) return mid;
        if(a[mid]<val)  l=mid+1;
        if(a[mid]>val)  r=mid-1;
    }
    if(a[l]==val) return l;
    return -1;
}
int main()
{
    int n,a[100],i,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b);
        printf("%d\n",bin_srch(a,b,0,n-1));

    }
}
