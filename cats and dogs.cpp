#include<iostream>
#include<cmath>
using namespace std;
int maxm(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    int t;
    long long int w,l,c,d;
    cin>>t;
    for(w=0;w<t;w++)
    {
        cin>>c>>d>>l;
        if(l>=4*(d+maxm(c-2*d,0)) && l<=4*(c+d) && l%4==0)
           cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
