#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int w,t,i,n,m,a[30],cnt;
    long long int ans;
    cin>>t;
    f(w,t)
    {
        cnt=0;
        cin>>n>>m;
        f(i,n)
        {
            cin>>a[i];
            if(a[i]%m==0) cnt++;
        }
        ans=pow(2,cnt)-1;
        cout<<ans<<endl;
    }
}
