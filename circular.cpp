#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,n,i,j,k,l,r,w,m,q,x,ans=0;
    cin>>t;
    for(w=0;w<t;w++)
    {
        cin>>n;
        bool linInd[n][100000]={false};
        for(i=0;i<n;i++)
        {
            cin>>l>>r;
            for(int j=l;j<=r;j++)
                linInd[i][j]=true;
        }
        cin>>q;
        for(k=0;k<q;k++)
        {
            short int cnt[100000]={0};
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>x;
                for(i=0;i<n;i++)
                {
                    if(linInd[i][x]) cnt[i]++;
                }
            }
            for(i=0;i<n;i++)
            {
                if(cnt[i]%2) ans++;
            }
            cout<<ans<<endl;
            ans=0;
        }
    }
}
