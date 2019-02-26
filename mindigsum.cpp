#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int max(long long int a,long long  int b)
{
    if(a>b) return a;
    return b;
}
 long long int digsm( long long int a)
{
     long long int sum=0;
    for(;a>0;a/=10)
        sum+=a%10;
    return sum;
}
 long long int fincnt( long long int n, long long int d, long long int i, long long int min)
{

    n=n+i*d;
     long long int cnt=0;
    while(n>=10)
    {
        n=digsm(n);
        cnt++;
    }
    return cnt+i;

}
int main()
{
    long long int n,d,ns,ds,min,i,fact,a[10],mincnt,cnt,pos;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        ns=digsm(digsm(digsm(n)));
        ds=digsm(digsm(digsm(d)));
        min=100;
        ns=ns-ds;
        for(i=0;i<10;i++)
        {
            ns+=ds;
            ns=digsm(ns);
            if(ns<min)
            {
                min=ns;
                //fact=i;
            }
            a[i]=ns;
        }
        //cout<<min<<endl;
        mincnt=100000000;
        for(i=0;i<10;i++)
        {
            if(a[i]==min)
            {
                cnt=fincnt(n,d,i,min);
                if(cnt<mincnt)
                {
                    mincnt=cnt;
                    pos=i;
                }
            }
        }
        cout<<min<<" "<<mincnt<<endl;

    }
}
