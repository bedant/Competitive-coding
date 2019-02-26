#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int w,i,u1,u2,d1,d2,h;
    cin>>w>>h;
    cin>>u1>>d1;
    cin>>u2>>d2;
    for(i=h;i>=0;i--)
    {

        w+=i;
        if(d1==i)
        {
            w-=u1;
            if(w<0)
                w=0;
        }
        if(d2==i)
        {
            w-=u2;
            if(w<0)
                w=0;
        }
    }
    cout<<w;
}
