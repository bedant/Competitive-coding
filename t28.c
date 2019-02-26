#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
long long int invert_mod(unsigned long long a, unsigned long long p) {
    if(a==0) return -1;
    unsigned long long ex = p-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*a) % p;
        }
        a = (a*a) % p;
        ex /= 2;
    }
    return result;
}
int main()
{
    int n,q,i,a,b;
    unsigned short int arr[2000000001]={0};
    unsigned long long int k,expr;
    long long int modInv;
    double root;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        expr=1LL*4*a*b+2*max(a,b);
        //printf("%llu\n",expr);
        root=sqrt(expr);
        //printf("%lf\n",root);
        k=(unsigned long long int)root;
        if(k*(k+1)==expr)
            {arr[k]++;}
    }
    for(i=0;i<q;i++)
    {
       scanf("%llu",&k);
       //printf(" %d\n",arr[k]);
       modInv=invert_mod(arr[k],1000000009);
       printf("%lld\n",modInv);
    }
}
