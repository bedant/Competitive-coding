#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
//int z;
#define f(i,n) for(int i=0;i<n;i++)
int com(char a[],char b[],int sft,int n)
{
    int i,j,cnt;
    for(cnt=0,i=sft;i<n;i++,cnt++)
    {
        //cout<<++z<<endl;
        //j=i%n;
        if(!(b[i]==a[i-sft])) break;
    }
    if(i==n)
    {
        for(j=0;j<sft;j++,cnt++)
        {
            if(!(b[j]==a[n-sft+j])) break;
        }
    }
    return cnt;
}
int main()
{
    int n,maxm,pos,i,sft,ans;
    char a[1000000],b[1000000];
    cin>>n;
      cin>>a>>b;
      //n=strlen(a);
      //cout<<n<<endl;
    maxm=com(a,b,0,n);
    pos=0;
    for(sft=1;sft<n;sft++)
    {
        //cout<<"pos"<<endl;
        ans=com(a,b,sft,n);
        //cout<<"pos2"<<endl;
        if(ans>maxm) {maxm=ans;pos=sft;}
        if(maxm==n) break;
        if(ans) sft=sft+ans-1;
    }
    cout<<pos<<endl;
}
