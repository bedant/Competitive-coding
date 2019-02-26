#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
double solve(double t[],double b[],double r)
{
    int i;
    double dot,deno,sum;
    for(i=0,dot=0;i<3;i++)
    {
        dot+=t[i]*b[i];
    }
    for(i=0,deno=0;i<3;i++)
    {
        deno+=b[i]*b[i];
    }
    for(i=0,sum=0;i<3;i++)
    {
        sum+=(dot*b[i]/deno-t[i])*(dot*b[i]/deno-t[i]);
    }
    return (sum-r*r);
}
int main()
{
int t1,w,i,flag;
double p[3],q[3],c[3],d[3],r,t[3],b[3],low,high,mid,check;
cin>>t1;
for(w=0;w<t1;w++)
{
    for(i=0;i<3;i++)
    {
        cin>>p[i];
    }
    for(i=0;i<3;i++)
    {
        cin>>q[i];
    }
    for(i=0;i<3;i++)
    {
        cin>>d[i];
    }
    for(i=0;i<3;i++)
    {
        cin>>c[i];
    }
    cin>>r;
    for(i=0;i<3;i++)
    {
        t[i]=c[i]-p[i];
    }
    low=0;high=1000000000;
    for(flag=0;low<high;)
    {
        mid=(low+high)/2;
        for(i=0;i<3;i++)
        {
           b[i]=q[i]+d[i]*mid-p[i];
        }
        check=solve(t,b,r);
        if(check==0)
        {
            flag=1;break;
        }
        //cout<<low<<" "<<mid<<" "<<high<<"  =  "<<check<<"\n";
        if(check<0) low=mid+.0000002;
        if(check>0) high=mid-.0000002;

    }
    printf("%lf\n",mid);
}
}
