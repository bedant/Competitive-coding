#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int t,q,i,j,n,c[100001],w[100001],max,k;
    long long int sum=0;
    cin>>t;
    f(q,t)
    {
        cin>>n;
        f(i,n)
        cin>>c[i];
        f(i,n)
        cin>>w[i];
        max=w[0];
        for(i=0;i<n;)
        {
            sum=0;
            short int cnt[100001]={0};
            for(j=i;j<n;j++)
            {
                if(cnt[c[j]]) break;
                cnt[c[j]]++;
                sum+=w[j];
            }
            if(sum>max) max=sum;
            if(j==n) break;
            for(k=i;k<n;k++)
            {
                if(c[k]==c[j]) {break;}
            }
            i=k+1;
        }
        cout<<max<<endl;
    }
}
