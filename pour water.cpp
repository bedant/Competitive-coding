#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int t,n,i,j,k,l,cnt1,cnt2,r,high,low,mid,w,m,temp,amta,amtb,amtc,a,b,c;
    cin>>t;
    f(w,t)
    {
        cin>>a>>b>>c;
        if(a<b) {temp=a;a=b;b=temp;}
        if(c>a && c>b) {cnt1=cnt2=-1;}
        else if(a%b==0 && c%b!=0) {cnt1=cnt2=-1;}
        else if(c==0) {cnt1=cnt2=0;}
        else if(a==0) {cnt1=cnt2=-1;}
        else if(b==0 && a==c) {cnt1=cnt2=1;}
        else{
        amtc=c;amta=0;amtb=0;
        for(cnt1=0;(amta!=amtc && amtb!=amtc) && cnt1<100000;cnt1++)
        {
            if(amta==0) amta=a;
            else if(amta==a)
            {
                amta=amta-b+amtb;
                amtb=b;
            }
            else if(amtb==b) amtb=0;
            else if(amtb==0 && amta<=b) {temp=amta;amta=amtb;amtb=temp;}
            else if(amtb==0 && amta>b)
            {
                amta-=b;amtb=b;
            }
            //else if(amta<a)  {temp=amtb;amtb=minm(amta+amtb,b);amta=max(0,amta-(b-temp));}
        }
        {temp=a;a=b;b=temp;}
        amta=0;amtb=0;
        for(cnt2=0;amta!=amtc && amtb!=amtc && cnt2<100000;cnt2++)
        {
            if(amta==0) amta=a;
            else if(amta==a && amta+amtb<=b) {amtb=amta+amtb;amta=0;}
            else if(amta==a && amta+amtb>b) {amta=amta-(b-amtb);amtb=b;}
            else if(amtb==b) amtb=0;
            else if(amtb==0) {temp=amta;amta=amtb;amtb=temp;}
        }
        }
        if(cnt1>=100000 && cnt2>=100000) {cnt1=cnt2=-1;}
        if(cnt1<=cnt2)
            cout<<cnt1<<endl;
        else cout<<cnt2<<endl;
    }
}
