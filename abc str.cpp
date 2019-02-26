#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int cnta[1000001],cntb[1000001],cntc[1000001],n,i,j,k,counter=0;
    char s[1000001];
    scanf("%s",s);
    n=strlen(s);
    if(s[0]=='A') {cnta[0]=1;cntb[0]=0;cntc[0]=0;cntab[0]=cnta[}
    else if(s[0]=='B') {cnta[0]=0;cntb[0]=1;cntc[0]=0;}
    else if(s[0]=='C') {cnta[0]=0;cntb[0]=0;cntc[0]=1;}
    for(i=1;i<n;i++)
    {
        if(s[i]=='A') {cnta[i]=cnta[i-1]+1 ; cntb[i]=cntb[i-1] ; cntc[i]=cntc[i-1];}
        else if(s[i]=='B') {cntb[i]=cntb[i-1]+1;cnta[i]=cnta[i-1];cntc[i]=cntc[i-1];}
        else if(s[i]=='C') {cntc[i]=cntc[i-1]+1;cntb[i]=cntb[i-1];cnta[i]=cnta[i-1];}
            //cout<<i<<" 0 "<<cnta<<cntb<<cntc<<endl;
    }

