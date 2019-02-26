#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
/*int finprs(char str[],int n)
{
    int cnt=0,i,j;
    f(i,n)
    {
        for(j=i+1;j<n;j++)
            {if(str[i]<str[j]) {cnt++;cout<<i<<" "<<j<<"   ";}}
    }
    return cnt;
}
*/
long long int finpr(char str[],long long int n,long long int coun[][27])
{
    long long int cnt=0,i,j;
    f(i,n)
    {
        cnt+=coun[i][str[i]-'a'];
        //cout<<"sec  "<<coun[i][str[i]-'a']<<" ";
    }
    return cnt;
}
int main()
{
    long long int t,w,n,m,out,min=9999999999999,sum,x,y,i,j,ch,y_per,cnt,coun[100004][27];
    char s[100004];
    cin>>t;
    for(w=0;w<t;w++)
    {
        min=999999999999;
        cin>>s;
        //strcpy(str,s);
        n=strlen(s);
        for(ch='a';ch<='z';ch++)
        {
            for(cnt=0,i=1;i<n;i++)
            {
                if(ch<s[i]) cnt++;
            }
            coun[0][ch-'a']=cnt;
        }
        for(i=1;i<n;i++)
        {
            for(ch='a';ch<='z';ch++)
            {
                coun[i][ch-'a']=coun[i-1][ch-'a'];
                if(ch<s[i]  ) coun[i][ch-'a']--;
                if(ch>s[i-1]) coun[i][ch-'a']++;
            }
        }
        //for(i=0;i<n;i++) {for(ch='a';ch<='z';ch++) {cout<<coun[i][ch-'a']<<" ";} cout<<endl;}
        //y_per=finprs(s,n);
        y_per=finpr(s,n,coun)/2;
        //cout<<y_per<<" "<<y2<<endl;
        for(i=0;i<n;i++)
        {
            for(ch='a';ch<='z';ch++)
            {
                y=coun[i][ch-'a']-coun[i][s[i]-'a'];
                //cout<<" "<<y<<" "<<s[i]<<" "<<str[i]<<endl;
                sum=abs(ch-s[i])+y+y_per;
                if(sum<min) min=sum;
            }
            //str[i]=s[i];
        }
        cout<<min<<endl;
    }
}
