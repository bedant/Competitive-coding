#include<stdio.h>
int main()
{
    int n,max,i,j,cnt;
    char strn[100][100],c;
    scanf("%d",&n);
    scanf("%c%c",&c,&c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n;j++)
        {
            //printf("%d %d ",i,j);
            scanf("%c",&strn[i][j]);
        }
        scanf("%c",&c);
        strn[i][j-1]='\0';
    }
    max=0;
   // for(i=0;i<n;i++)
     //   printf("1:%s\n",strn[i]);
    for(i=0;i<n;i++)
    {
        cnt=0;
        for(j=0;j<n;j++)
        {
            if(strcmp(strn[i],strn[j])==0)
                cnt++;
        }
        if(cnt>max)
            max=cnt;
    }
    printf("%d\n",max);
}
