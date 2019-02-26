#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int finprs(char str[],int n,int size[],char stac[][100001])
{
    bool seen[100001][200]={false};
    int cnt=0,i,j;
    f(i,n)
    {
        for(j=i+1;j<n;j++)
        {
            if(str[i]<str[j])
            {
                 if(seen[i][str[j]]==false) {stac[i][size[i]]=str[j];size[i]++;seen[i][str[j]]=true;}
                 if(seen[j][str[i]]==false) {stac[j][size[j]]=str[i];size[j]++;seen[j][str[i]]=true;}
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int t,w,n,m,out,min=99999999,sum,k,x,y,i,j,ch,y_per;
    char s[100001],str[100001],stac[100001][28];
    cin>>t;
    f(w,t)
    {
        int size[100001]={0};
        cin>>s;
        strcpy(str,s);
        n=strlen(s);
        y_per=finprs(str,n,size,stac);
        //ch=s[0];
        for(ch='a';ch<='z';ch++)
        {
            for(cnt=0,i=1;i<n;i++)
            {
                if(ch<str[i]) cnt++;
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
        min=y_per;
        /*for(i=0;i<n;i++)
        {
            cout<<size[i]<<" ";
            for(j=0;j<size[i];j++)
                cout<<"  "<<stac[i][j];
            cout<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            //strcpy(str,s);
            for(k=0;k<size[i];k++)
            {
                ch=stac[i][k];
                str[i]=ch;
                for(y=0,j=0;j<n;j++)
                {
                    if((i-j)*(str[i]-str[j])>0) y++;
                    if((i-j)*(s[i]-s[j])>0) y--;
                }
                //cout<<" "<<y<<" "<<s[i]<<" "<<str[i]<<endl;
                sum=abs(str[i]-s[i])+y+y_per;
                if(sum<min) min=sum;
                //cout<<str<<" "<<sum<<endl;
            }
            str[i]=s[i];
        }
        cout<<min<<endl;
    }
}
