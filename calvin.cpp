#include<iostream>
using namespace std;
int maxm(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    int n,k,i,wt[100005],back[100005],totsc[100006];
    cin>>n>>k;
    k--;
    for(i=0;i<n;i++)
        cin>>wt[i];
    back[0]=0;
    back[1]=wt[0];
    for(i=2;i<n;i++)
    {
        back[i]=maxm(wt[i-1]+back[i-1],wt[i-2]+back[i-2]);
    }
    totsc[n-1]=back[n-1];
    totsc[n-2]=maxm(wt[n-1]+totsc[n-1],back[n-2]);
    for(i=n-3;i>=0;i--)
    {
        totsc[i]=maxm(maxm(wt[i+1]+totsc[i+1],wt[i+2]+totsc[i+2]),back[i]);
    }
    cout<<totsc[k]<<endl;
}
