#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define f(i,n) for(int i=0;i<=n;i++)
int minm(long long int a,long long int b,long long int c,long long int d)
{
    if(a<=b && a<=c && a<=d) return a;
    if(b<=a && b<=c && b<=d) return b;
    if(c<=a && c<=b && c<=d) return c;
    if(d<=a && d<=b && d<=c) return d;
}
int main()
{

    long long int n,t,a,i,j,c,k,cnt,w;
    char s[100001];
    cin>>t;
    for(w=0;w<t;w++)
    {   cnt=0;
        cin>>n>>k;
        cin>>s;
        for(i=1;i<n;i++)
            if(s[i]==s[i-1]) cnt+=minm(k,n-k,i,n-i);
        cout<<((n-k)*k-cnt)<<endl;
    }
}
