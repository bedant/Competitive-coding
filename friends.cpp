#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    char fre[201][201];
    int n,k;
    bool sug[201][201]={false};
    int cnt=0;
    cin>>n;
    f(i,n)
    {
        //f(j,n)
        {
            scanf("%s",fre[i]);
        }
    }
    //cout<<"okay"<<endl;
    f(i,n)
    {
        f(j,n)
        {
            if(fre[i][j]=='1')
            {
                for(k=j+1;k<n;k++)
                {
                    if(fre[i][k]=='1' && fre[j][k]=='0' && sug[j][k]==false && sug[k][j]==false)
                    {sug[j][k]=true;sug[k][j]=true;cnt+=2;}
                }
            }
        }
    }
    cout<<cnt<<endl;
    cnt=0;
}
//y967576458764
