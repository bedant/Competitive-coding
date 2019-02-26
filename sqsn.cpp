#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n,r;
    cin>>n;
    r=sqrt(n);
    if(n==r*r)
    {
        cout<<2*r<<endl;
    }
    else if(n<r*r+r+1)
    {
        cout<<2*r+1<<endl;
    }
    else cout<<2*r+2<<endl;
}

