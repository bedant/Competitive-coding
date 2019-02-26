#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,k,n,q,r,len,maxm,pos,cnt[100001],flag;
    char strin[100001][11],p[11];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>strin[i];
    }
    cin>>q;

    for(j=0;j<q;j++)
    {
        cin>>r;
        cin>>p;
        maxm=0;
        for(i=0;i<r;i++)
        {
            len=strlen(strin[i]);
            for(k=0;k<len;k++)
            {
                if(strin[i][k]!=p[k])
                    break;
            }
            cnt[i]=k;
            if(k>maxm) {maxm=k;pos=i;}
            if(k==maxm)
            {
                if(strcmp(strin[i],strin[pos])<0) pos=i;
            }
        }
        cout<<strin[pos]<<endl;
    }
    //cout<<"hello1";
}
