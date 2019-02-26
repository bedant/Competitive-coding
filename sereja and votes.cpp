#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int t,n,i,j,k,l,r,w,m,term,b,x,sum=0,check=1;
    cin>>t;
    f(w,t)
    {
        cin>>n;
        term=n;
        f(i,n)
        {
           cin>>b;
           sum+=b;
           if(b>100 || b<0) check=0;
           if(b==0) term--;
        }
        if(sum>=100 && sum<100+term && check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        sum=0;check=1;
    }
}
