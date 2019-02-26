#include<stdio.h>
#include<math.h>
#include<string.h>
long long int min(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
int main()
{
    long long int w,t,n,i,j,k,len,nab,diff[1005],term,aa,bb;
    long long int cnt;
    char st[1005],stri[1000005];
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        cnt=0;
        scanf("%s",st);
        scanf("%lld",&n);
        len=strlen(st);
        nab=0;
        for(i=0;i<strlen(st)*n;i++)
        {
            stri[i]=st[i%len];
                if(stri[i]=='a') nab++;
                if(stri[i]=='b') nab--;
            if(nab>0) cnt++;
        }
        printf("%lld\n",cnt);
    }
}
