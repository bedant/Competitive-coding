#include<stdio.h>
int main()
{int n;
char a[1000003];
char b[1000003];
int s=0;
int count=0;
int max=0;
int x=0;
scanf("%d",&n);
scanf("%s %s",a,b);
char c1;
//scanf("%c",&c1);
//scanf("%s",b);
int y=0,i;
int flag=0;
for(i=0;i<n;i++)
{
    if(a[0]==b[i])
    {

    y++;
    s=i;
    count++;
    i++;
    while(a[y]==b[i])
    {

        count++;y++;i++;
        if(i==n)
        {
            flag=1;
            break;
        }
    }
    int k=0;
    if(flag)
    {
        while(y<n&&a[y]==b[k])
            {count++;y++;k++;}
    }
    if(max==count&&s<x)
    {
        x=s;
    }
    else if(max<count)
    {
        max=count;
        x=s;
    }
    y=0;
    count=0;i--;
    flag=0;
    }
}


printf("%d",x);




return 0;
}
