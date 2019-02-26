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
    long long int w,t,n,i,j,k,len,na,nb,diff[1005],term,aa,bb;
    long long int cnt;
    char st[1005];
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        cnt=0;
        scanf("%s",st);
        scanf("%lld",&n);
        len=strlen(st);
        //printf("%d\n",len);
        for(i=1;i<=len;i++)
        {
            na=0;nb=0;
            for(j=0;j<i;j++)
            {
                if(st[j]=='a') na++;
                if(st[j]=='b') nb++;
            }
            diff[i-1]=na-nb;
          //  printf("%d\n",diff[i-1]);
        }
        term=diff[len-1];
       // printf("term=%d\n",term);
        for(i=0;i<len-1;i++)
        {
            if(diff[i]==0 && term>0) cnt+=n-1;
            if(diff[i]>0 && term>=0) cnt+=n;
            if(diff[i]>0 && term<0)
            {
               if(diff[i]%(-1*term))
               {
               aa=diff[i]/(-1*term)+1;
               cnt+=min(n,aa);
               }
               else {bb=diff[i]/(-1*term);cnt+=min(n,bb);}
            }
            if(diff[i]<0 && term>0)
            {
               if((-1*diff[i])%(term)) cnt+=(n-(-1*diff[i])/term-1);
               else cnt+=(n-(-1*diff[i])/(term)-1);
            }
        }
        if(term>0) cnt+=n;
        printf("%lld\n",cnt);
    }
}
