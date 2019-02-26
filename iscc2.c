#include<stdio.h>
int main()
{
    int t,w,i,rem_m,rem_n;
    char n[100001],m[100001];
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        rem_m=rem_n=0;
        scanf("%s",m);
        scanf("%s",n);
        for(i=0;i<strlen(m);i++)
            {rem_m+=(m[i]-'0');}
        for(i=0;i<strlen(n);i++)
            rem_n+=(n[i]-'0');
        rem_m=rem_m%3;
        rem_n=rem_n%3;
        printf("%d\n",(rem_m*rem_n)%3);
    }

}
