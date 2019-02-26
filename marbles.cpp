#include<iostream>
#include<cmath>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)
int main()
{
    int t,n,i,j,k,l,r,w,m,q,x;
    double pro=1;
    unsigned long long int proi=1;
    cin>>t;
    loop(w,t)
    {
        pro=1;
        cin>>n>>k;
        loop(i,k-1)
        {
            pro*=(n-1-i)/((k-1-i)*1.0);
        }
        proi=static_cast<unsigned long long int>(pro+.1);
        cout<<proi<<endl;
    }
}

