#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j,visited[10000],a,cnt,temcnt;
    cin>>n>>k;
    vector<int> vec,numsofcol[5001];
    for(i=0;i<n;i++)
    {
        cin>>a;
        vec.push_back(a);
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    cnt=0;
    for(i=0,j=1;j<=k;j++,i++)
    {
        if(visited[i]==0)
        {
            //cout<<" in"<<i<<endl;
            numsofcol[j].push_back(vec[i]);
            visited[i]=j;
            cnt++;
        }
    }
    temcnt=cnt;
    //cout<<" "<<cnt;
    //for(i=0;i<n;i++)
      //  cout<<visited[i]<<" ";
    //cout<<endl;
    for(j=1;j<=k;j++)
    {
        for(i=cnt;i<n;i++)
        {
            if(visited[i]==0 && find(numsofcol[j].begin(),numsofcol[j].end(),vec[i])==numsofcol[j].end())
            {
                numsofcol[j].push_back(vec[i]);
                visited[i]=j;
                temcnt++;
            }
        }
    }
    //cout<<endl<<temcnt<<endl;
    if(temcnt<n) cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(i=0;i<n;i++)
            cout<<visited[i]<<" ";
        cout<<endl;
    }
}
