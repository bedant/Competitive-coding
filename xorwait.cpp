#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 //   long long int l,r,num;
    int t,xor1,i,n,maxm,j;
    char c;
    vector<int> vec;
    string strn[1001];
    cin>>n;
    //cin>>c;
    maxm=0;
    for(i=0;i<n;i++)
    {
        scanf ("%[^\n]%*c", strn[i]);
        for(j=0;2*j<strn[i].size();j++)
            strn[i][j]=strn[i][2*j];
    }
    strn[i][j]='\n';
    for(i=0;i<n;i++)
        cout<<strn[i]<<endl;
        //cin>>c;
        //cout<<i<<endl;}
    for(i=0;i<n;i++)
    {
        vec.clear();
        vec.push_back(i);
        for(j=0;j<n;j++)
        {
            if(strn[i][j]=='T' && i!=j)
                vec.push_back(j);
        }
        for(j=0;j<vec.size()-1;j++)
        {
            if(strn[vec[j]]!=strn[vec[j+1]])
            {
                break;
            }
        }
        if(j==vec.size()-1 && maxm<vec.size())
        {
            maxm=vec.size();
        }
    }
    cout<<maxm<<endl;
}
