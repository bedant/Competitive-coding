#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int max(long long int a,long long  int b)
{
    if(a>b) return a;
    return b;
}
short int find(int a[],int b[],int n,long long int m,long long int c)
{
    long long int ans=0,i;
    for(i=0;i<n;i++)
    {
       ans+=max(0,a[i]-c/b[i]);
       if(ans>m)
        {
         //   cout<<n<<" "<<m<<" "<<c<<" "<<ans<<endl;
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long int m,l,h,c,k;
    int i,n,a[100005],b[100005];
    short int ans;
    scanf("%d%lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(l=0,h=pow(10,18)+1;l<h;)
    {
       // cout<<l<<" lh "<<h<<endl;
        c=(h+l)/2;
        ans=find(a,b,n,m,c);
        if(ans==1)
        {

            h=c-1;
        }
        else l=c+1;
    }
    k=c;
    for(c=max(0,k-5);c<k+6;c++)
    {
        ans=find(a,b,n,m,c);
        if(ans==1)
        {
            break;
        }
    }
    cout<<c<<endl;

}
