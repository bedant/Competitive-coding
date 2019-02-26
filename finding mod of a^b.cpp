#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
int main()
{
    long long int t,w,i,m,out1=1,out2;
    int n1,n2;
    cin>>n1>>n2;
    for(i=1,out2=1;i<=1000000006;i++)
    {
        out1=(out1*n1)%mod;
        out2=(out2*n2)%mod;
    }
    cout<<out1<<" "<<out2<<endl;
}
