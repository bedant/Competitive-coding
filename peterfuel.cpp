#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int sum,n,a,i,j;
    string st;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(i=1;i<pow(2,n);i++)
    {
        st=bitset<16>(i).to_string();
        //cout<<st<<endl;
        sum=0;
        for(j=0;j<n;j++)
        {
            //cout<<j<<" "<<st[15-j]<<" "<<v[j]<<endl;
            if(st[15-j]=='0')
            {
                //cout<<sum<<"->";
                sum-=v[j];
                //cout<<sum<<endl;
            }

            else
            {
                //cout<<sum<<"->";
                sum+=v[j];
                //cout<<sum<<endl;
            }

        }
        //cout<<" "<<sum<<endl;
        if(sum%360==0)
        {
            cout<<"YES\n";
            break;
        }
    }
    if(i==pow(2,n))
        cout<<"NO\n";

}
