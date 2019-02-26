#include<iostream>
#include<cstdlib>

using namespace std;
int main()
{
    int n,i,j,hatcnt,cntarr[100005],impos,a[100005],hat[100005],mencnt[100005];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=n-a[i];
        cntarr[a[i]]++;
    }
    impos=0;
    for(i=1;i<=n;i++)
    {
        if(cntarr[i]!=0)
        {
            if((cntarr[i]%i)!=0)
                impos=1;
        }
    }
    if(impos==1)
        cout<<"Impossible\n";
    else
    {
        cout<<"Possible\n";
        for(i=0;i<=n;i++)
        {
            mencnt[i]=0;
            hat[i]=-1;
        }
        j=0;hatcnt=1;
        for(i=0;i<n;i++)
        {
            if(hat[a[i]]==-1)
            {
                hat[a[i]]=hatcnt;
                hatcnt++;
            }
            if(mencnt[a[i]]==a[i])
            {
                mencnt[a[i]]-=a[i];
                hat[a[i]]=hatcnt;
                hatcnt++;
            }
            cout<<hat[a[i]]<<" ";
            mencnt[a[i]]++;
        }
        cout<<endl;
    }
}
