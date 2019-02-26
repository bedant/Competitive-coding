#include<iostream>
#include<bits/stdc++.h>

#include <string>
using namespace std;
int main()
{
    string tab;
    string hand;
    int i;

        getline(cin,tab);
    //for(i=0;i<14;i++)
        getline(cin,hand);
    //cout<<hand;
    for(i=0;i<14;i++)
    {
        //cout<<hand[i]<<endl;
        if(hand[i]==tab[0] || hand[i]==tab[1])
        {

            cout<<"YES\n";
            break;
        }
    }
    if(i==14)
        cout<<"NO\n";
}
