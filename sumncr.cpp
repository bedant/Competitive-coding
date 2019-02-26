#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define endl() printf("\n")
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define M 1000000007

inline void fastio()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main()
{
    fastio();
    ll t,k,i,j,x,y;
    cin >> t;
    while(t--)
    {
        cin >> k;
        bool ok=false;
        vector<ll> a(k);
        for(i=0;i<k;i++)
        {
            cin >> a[i];
            if(a[i]%2==0)
            {
                ok=true;
            }
        }
        if(k%2==0)
        {
            cout << 0 << endl;
            continue;
        }
        if(ok)
        {
            cout << 1 << endl;
            continue;
        }
        ll ans=1e18;
        for(i=0;i<k;i++)
        {
            x=1;
            while((a[i]+1)%x==0)
            {
                x*=2;
            }
            x/=2;
            if(x!=a[i]+1)
            {
                ans=min(ans,x);
            }
        }
        if(ans==1e18)
        {
            ans=-1;
        }
        cout << ans << endl;
    }
    return 0;
}
