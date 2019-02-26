#include<iostream>
#include<cmath>
using namespace std;
int a[1000][1000]={0},cnt;
//int b[100][100];
void check(int b[][1000],int i,int j,int g,int h,int n,int m)
{
    //cout<<i<<" "<<j<<"cnt="<<cnt<<endl;
    cnt++;b[i][j]=0;

    if( (b[i][j+1]==g || b[i][j+1]==h) && j+1<m) check(b,i,j+1,g,h,n,m);
    if( (b[i+1][j]==g || b[i+1][j]==h) && i+1<n) check(b,i+1,j,g,h,n,m);
    if( (b[i][j-1]==g || b[i][j-1]==h) && j-1>0) check(b,i,j-1,g,h,n,m);
    if( (b[i-1][j]==g || b[i-1][j]==h) && i-1>0) check(b,i-1,j,g,h,n,m);
    return;
}
int main()
{
    //long long int n,h,k,x,p[50001]={0},ntp[1000001]={0},i,j,a[1000001]={0},c[102],s,f[1000001]={0},nm,ans,hcf,invs;
    int n,m,i,j,k,l,g,h,b[1000][1000],maxm=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
           cin>>a[i][j];
    }
    for(g=1;g<=1000000;g++)
    {
        for(h=1;h<=1000000;h++)
        {
            for(k=0;k<1000;k++)
            {
                for(l=0;l<1000;l++)
                    b[k][l]=a[k][l];
            }
            for(i=0;i<n;i++)
            {
                //cout<<"ok"<<endl;
                for(j=0;j<m;j++)
                {
                    //cout<<"@";
                    cnt=0;
                    if(a[i][j]==g || a[i][j]==h)
                    {
                        check(b,i,j,g,h,n,m);
                        if(cnt>maxm) maxm=cnt;
                    }
                }
            }
        }
    }
    cout<<maxm<<endl;
}

