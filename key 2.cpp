#include<bits/stdc++.h>
#include<iostream>
//#include<boost/math/common_factor.hpp>
#include<string>
using namespace std;
#include <iostream>
using namespace std;
// Recursive function to return gcd of a and b
class lcmclass
{
 public : int gcd(int a, int b)
 {
    // Everything divides 0
    if (a == 0 || b == 0)
        return 0;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
 }


// Function to return LCM of two numbers
  int lcm(int a, int b)
 {
    return (a*b)/gcd(a, b);
 }
} ;
int main()
{
    lcmclass g;
    int i,j,n,poss,cnt[10000],lcmnum;
    string w,s;
    char temp;
    cin>>s;
    poss=1;
    for(i=0;i<s.size();i++)
    {
        temp=s[i];j=1;
        while(temp!='A'+i && j<270)
        {
            cout<<temp<<" i  "<<i<<endl;
            temp=s[temp-'A'];
            j++;
        }
        cnt[s[i]-'A']=j;
        if(j==270)
        {
            poss=0;
            cout<<s[i]<<endl;
            break;
        }
    }
    for(i=0;i<26;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    cin>>n;
    cin>>w;
    cout<<"okay"<<endl;
    if(poss==1)
    {
        if(n==1) cout<<cnt[w[0]-'A'];
        else if(n==2) cout<<g.lcm(cnt[w[0]-'A'],cnt[w[1]-'A']);
        else
        {
            cout<<" "<<cnt[w[0]-'A']<<"  "<<cnt[w[1]-'A']<<endl;
            lcmnum=g.lcm(cnt[w[0]-'A'],cnt[w[1]-'A']);
            for(i=2;i<n;i++)
            {
                lcmnum=g.lcm(lcmnum,cnt[w[i]-'A']);
            }
            cout<<lcmnum;
        }


    }

}
