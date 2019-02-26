#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ldb long double
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define clr(x) memset(x,0,sizeof(x))
#define count_bit(x) __builtin_popcount(x)
const ll mod=1e9+7;
const ll size=1e6+7;
const ll inf = 1e18+7;
int main()
{
	//cout<<setprecision(12)<<fixed;//in.open("input");out.open("output");
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll T=1;
	char m;
	while(T--)
	{
		ll n;cin>>n;
		map<vector<char>,ll> M;
		//map<vector<char>,ll> X;
		for(ll i=0;i<n;i++)
		{
			ll val=0;
			vector<char> vi;
			//ll c=0;
			for(ll j=0;j<n;j++)
			{
				cin>>m;
				vi.pb(m);
				//if(m=='T')c++;
			}
			M[vi]++;
		}
		ll mx=0;
		map<vector<char>,ll> :: iterator it;
		//for(auto x:M)
		pair <vector<char>,ll> x;
        for(it=M.begin();it!=M.end();it++)
		{
		    x=*it;
            //cout<< x.ff <<endl;
			vector<char> vi=x.ff;
			for(ll i=0;i<vi.size();i++)
                cout<<vi[i];
            cout<<endl;
			ll cnt=0;
			//for(ll i=0;i<vi.size();i++)if(vi[i]=='T')cnt++;
			mx=max(mx,x.ss);
		}
		cout<<mx<<endl;
	}
}
