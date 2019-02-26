#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string str;
    int n,k,i,j,l,qpres,done,minm,act;
    cin>>str;
    cin>>k;
    minm=act=str.size();
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='*' || str[i]=='?')
        {
            minm-=2;
            act--;
        }
    }
    qpres=0;done=0;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='*')
        {
            qpres=1;
            break;
        }
    }
    //cout<<minm<<" "<<act<<" "<<str.size()<<endl;
    if(minm<=k && act>=k)
    {
        for(i=0,j=0;j<act-k;i++)
        {
            if(str[i+1]=='*' || str[i+1]=='?')
            {
                str[i]='-';
                j++;
            }
        }
        for(i=0;i<str.size();i++)
        {
            if(str[i]!='*' && str[i]!='-' && str[i]!='?')
                cout<<str[i];
        }
        cout<<endl;
    }

    else if(act<k && qpres==1)
    {

        for(i=0;i<str.size()-1;i++)
        {
            if(str[i+1]=='*' && done==0)
            {
                for(l=0;l<k-act+1;l++)
                    cout<<str[i];
                done=1;
            }
            else if(str[i]!='*' && str[i]!='?')
                cout<<str[i];
        }
        if(str[i]!='*' && str[i]!='?')
            cout<<str[i]<<endl;
    }
    else cout<<"Impossible\n";
}
