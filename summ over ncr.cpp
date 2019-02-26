#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,i,k,evpres,fn1pres;
    long long int n[1001];
    cin>>t;
    while(t--)
    {
        evpres=0;fn1pres=0;
        cin>>k;
        for(i=0;i<k;i++)
            cin>>n[i];
        if(k%2==0)
            cout<<0;
        else
        {
            for(i=0;i<k;i++)
            {
                if(n[i]%2==0)
                {
                    evpres=1;
                    break;
                }
            }
            for(i=0;i<k;i++)
            {
                if(n[i]%4==1 && n[i]!=1)
                {
                    fn1pres=1;
                    break;
                }
            }
            if(evpres==1) cout<<1;
            else if(fn1pres==1) cout<<2;
            else cout<<-1;
        }
        cout<<endl;
    }
}
