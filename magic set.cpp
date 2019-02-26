#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int w,t,i,n,m,cnt;
    unsigned long long int ans;
    cin>>t;
    f(w,t)
    {
        cin>>n;
        //f(i,n)
        //ans=pow(10,n/2);
        cout<<"1 "<<"1";
        for(i=0;i<static_cast<int>(n/2);i++)
            cout<<"0";
        cout<<endl;
    }
}
