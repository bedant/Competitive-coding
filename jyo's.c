#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define ulli unsigned lli
#define ld long double
#define pb push_back
#define bp pop_back
#define vi vector<int>
#define vvi vector< vector<int> >
#define vli vector<lli>
#define vvli vector< vector<lli> >
#define pii pair <int, int>
#define pli pair <lli, lli>
#define forn(i,n) for(i=0;i<n;i++)
#define FORN(i,k,n) for(i=k;i<n;i++)
#define rof(i,k,n) for(i=k;i>=n;i--)
#define wh(k) while(k--)
#define mod 1000000007
#define set(a,s) memset(a,s,sizeof(a))
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
#define abs(a) a<0?-a:a
#define bs binary_search
void swapi(int *a, int *b) {int temp;temp=*a;*a=*b;*b=temp;}
void swapc(char *a, char *b) {char temp;temp=*a;*a=*b;*b=temp;}
template<typename T> void fscan(T &x)
{
    x=0;
    bool neg=0;
    register T c=getchar();

    if (c=='-')
        neg=1,c=getchar();

    while ((c<48) || (c>57))
        c=getchar();
    for ( ;c<48||c>57;c=getchar());
    for ( ;c>47&&c<58;c=getchar())
        x=(x<<3)+(x<<1)+(c&15);
    if(neg)
    	x*=-1;
}
template<typename T> void fprint(T n)
{
    bool neg=0;
    if (n<0)
        n*=-1,neg=1;
    char snum[65];
    int i=0;
    do
    {
        snum[i++]=n%10+'0';
        n/=10;
    }
    while(n);
    --i;
    if(neg)
    	putchar('-');
    while(i>=0)
        putchar(snum[i--]);
    putchar('\n');
}
template<typename T, typename U>
static inline void amin(T &x, U y)
{
    if(y<x)
    	x=y;
}
template<typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x<y)
        x=y;
}
void me(int arr[], int l, int m, int r)
{
    int i, j, k;
    int x = m - l + 1;
    int y =  r - m;
    int L[x], R[y];
    for (i = 0; i < x; i++)
        L[i] = arr[l + i];
    for (j=0;j<y;j++)
        R[j] = arr[m+1+j];
    i = 0;
    j = 0;
    k = l;
    while (i<x && j<y)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < x)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < y)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void ms(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        ms(arr, l, m);
        ms(arr, m+1, r);
        me(arr, l, m, r);
    }
}
int main()
{
	fast;
	int t,n,x,y,i;
	cin>>t;
	wh(t)
	{
		cin>>n>>x>>y;
		int a[2*n];
		forn(i,n)
		{
			cin>>a[i];
			a[i]=abs(a[i]);
			a[n+i]=-a[i];
		}
		ms(a,0,2*n-1);
		for(i=0;i<2*n;i++)
		{
			if(a[i]==x || a[i]==y)
			{
				cout<<1<<'\n';
				goto here;
			}
		}
		for(i=0;i<2*n;i++)
		{
			if(((bs(a,a+2*n,x-a[i]))==0)&&((bs(a,a+2*n,y-a[i])))==0)
			{
				goto there;
			}
		}
		cout<<2<<'\n';
		if(0)
		{
			there:
			cout<<0<<'\n';
		}
		here:
		;
	}
	return 0;
}
