#include<iostream>
#include<bits/stdc++.h>

#include <string>
using namespace std;
typedef struct pattern
{
    string str;
    int cnt;
    int mincnt;
}pattern;
bool compstr2(pattern i1,pattern i2)
{
    return (i1.cnt < i2.cnt);
}
bool compstr1(pattern i1,pattern i2)
{
    return (i1.mincnt < i2.mincnt);
}
int main()
{
    pattern p[1001];
    int i,j,n,low,high,out;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p[i].str;
        p[i].cnt=0;
        p[i].mincnt=1000005;
        for(j=0;j<(p[i].str).size();j++)
        {
            if((p[i].str)[j]=='(')
                p[i].cnt++;
            else if((p[i].str)[j]==')')
            {
                p[i].cnt--;
                if(p[i].cnt<p[i].mincnt)
                    p[i].mincnt=p[i].cnt;
            }
        }
    }
    sort(p,p+n,compstr1);
    sort(p,p+n,compstr2);
    low=0;out=0;
    for(high=n-1;high>low;)
    {
        for(;low<high;)
        {
            if(p[high].cnt+p[low].cnt==0)
            {
                if(p[high].cnt>=p[low].mincnt)
                {
                    out++;
                    low++;
                    high--;
                    break;
                }
                else low++;
            }
            else if(p[high].cnt+p[low].cnt>0)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    cout<<out<<endl;;
}
