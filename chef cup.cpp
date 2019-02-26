#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define f(i,n) for(int i=1;i<=n;i++)
int main()
{

    int n,t,a,i,j,c,q,l,r,cnt;
    char s[10001][21],p;
    vector <vector <int> > vec;
    vec.resize(27);
    cin>>n;
    f(i,n)
    {
        cin>>s[i];
        for(j=0;j<strlen(s[i]);j++)
        {
            //cout<<i<<" "<<j<<s[i][j]-'a'<<endl;
            vec[s[i][j]-'a'].push_back(i*100+j);
        }
    }
    cin>>q;
    f(j,q)
    {
        cnt=0;
        cin>>l>>r>>c>>p;
        for(i=0 ; i<vec[p-'a'].size() ; i++)
        {
            //cout<<vec[p-'a'][i]<<endl;
            if(vec[p-'a'][i]<100*(r+1) &&vec[p-'a'][i]>=100*l && vec[p-'a'][i]%100==c-1)
                cnt++;
        }
        cout<<cnt<<endl;
    }
}
