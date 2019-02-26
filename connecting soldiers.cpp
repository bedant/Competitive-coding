#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int t,w,n,m,out;
    cin>>t;
    f(w,t)
    {
        cin>>n>>m;
        out=m-n*(n+3)/2;
        if(out<0 && m>=(n+1)* log(n+1)/log(2))
            out=0;
        else if(out<0) out=-1;
        cout<<out<<endl;
    }
}
