#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{

    int t,n,i,j,k,l,r,w,m,q,x,cnt=0;
    short int a[100000]={0},opt;
    cin>>n>>q;
    f(i,q)
    {
        cin>>opt>>l>>r;
        if(opt==0)
        {
            for(j=l;j<=r;j++)
                if(a[j]) a[j]=0;
                else a[j]=1;
        }
        if(opt==1)
        {
            for(j=l;j<=r;j++)
                cnt+=a[j];
            cout<<cnt<<endl;
            cnt=0;
        }
    }
}
