#include<iostream>
#include<cmath>
using namespace std;
long long int modInverse(long long int a,long long int m)
{
    a = a%m;
    for (long long int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
long long int findhcf(long long int a,long long int b)
{
    long long int temp;
    if(a>b) {temp=a;a=b;b=temp;}
    for(;a!=0;)
    {
        temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}
int main()
{
    long long int n,h,k,x,p[50001]={0},ntp[1000001]={0},i,j,a[1000001]={0},c[101],s,f[1000001]={0},nm,ans,hcf,invs;
    cin>>n>>h>>x>>k;
    for(i=1;i<=n;i++)
        {
            cin>>p[i];
            ntp[p[i]]++;
        }
    for(i=1;i<=k;i++)
        cin>>a[i];
    for(i=1;i<=k;i++)
        cin>>c[i];
    for(i=k+1;i<=h;i++)
    {
        for(j=1;j<=k;j++)
            a[i]+=c[j]*a[i-j];
        //cout<<"   a  "<<a[i]<<endl;
    }
    //cout<<"okay"<<endl;
    for(s=0,i=1;i<=h;i++)
        {s+=a[i];s=s%163577857;}

    //cout<<s<<endl;
    for(f[1]=0,i=1;i<=x;i++)
        f[1]+=ntp[i];
    //cout<<"okay  1"<<endl;
    for(i=2;i<=h;i++)
    {
        f[i]=f[i-1]+( ntp[(i+x-1) % h]-ntp[i-1] );
        //cout<<" f "<<f[i-1]<<endl;
    }
    //cout<<"okay  2"<<endl;
    for(nm=0,i=1;i<=h;i++)
    {
        nm+=(a[i]*f[i]);
        nm=nm%163577857;
    }
    //cout<<"okay  "<<nm<<endl;
    if(nm && s)
    {
        hcf=findhcf(nm,s);
        //cout<<"okay  "<<hcf<<endl;
        nm/=hcf;s/=hcf;
        invs=modInverse(s,163577857);
        //cout<<"oinv  "<<invs<<endl;
        ans=( (nm%163577857) * (invs%163577857) )%163577857;
    }
    else ans=0;
    cout<<ans<<endl;
}



