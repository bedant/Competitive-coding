#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void addedge(vector<int> vec[],int u,int v,int n)
{
    if(find(vec[u].begin(),vec[u].end(),v)==vec[u].end())
    {
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
}
void dfs(vector<int> vec[],int visited[],vector<int> outvec,int vert)
{
    cout<<" "<<vert<<endl;
    visited[vert]=1;
    for(int j=0;j<vec[vert].size();j++)
    {
        if(visited[vec[vert][j]]==0)
        {
            dfs(vec,visited,outvec,vec[vert][j]);
            outvec.push_back(vec[vert][j]);
            cout<<vert<<"   "<<outvec.size()<<endl;
        }
    }
}
int main()
{
    int v,e,i,j,u,n,visited[10]={0};
    cin>>n>>e;
    vector<int> vec[n],outvec;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        addedge(vec,u,v,n);
    }
    for(i=0;i<n;i++)
    {
        cout<<i<<"::";
        for(j=0;j<vec[i].size();j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    dfs(vec,visited,outvec,1);
    cout<<"\nmain "<<endl<<outvec.size()<<endl;
    outvec.push_back(1);
    for(int x=0;x<outvec.size();x++)
        cout<<outvec[x]<<" ";
    cout<<endl;
}
