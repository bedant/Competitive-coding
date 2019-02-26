#include<stdio.h>
void countSort(char b[][100],int j,int l,int h)
{
    char fin[100][100];
    int c[10]={0},i,pos,k;
    for(i=l;i<=h;i++)
    {
        c[ b[i][j]-'0' ]++;
    }
    //printf("okay1");
    for(i=1;i<10;i++)
    {
        c[i]+=c[i-1];
    }
   /* printf("%d ",c[0]);
    for(i=1;i<10;i++)
    {
        printf("%d ",c[i]);
    }
    */
    //printf("okay");
    for(i=h;i>=l;i--)
    {
      //  printf(" okay3 %d ",i);
        pos=c[b[i][j]-'0']-1;
        c[b[i][j]-'0']--;
        for(k=0;k<100;k++)
        {
            fin[pos][k]=b[i][k];
            //c[b[i][j]-'0']--;
        }
    }
    //printf("\nokay %d\n",j);
    for(i=l;i<=h;i++)
    {
        for(k=0;k<99;k++)
            b[i][k]=fin[i][k];
    }
}
int main()
{
    int n,i,j,maxlen=20,len;
    char a[100][100],b[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        len=strlen(a[i])-1;
        for(j=maxlen-1;j>=0;j--)
        {
            if(len>=0)
            {
                b[i][j]=a[i][len];
                len--;
            }
            else
            {
                b[i][j]='0';
            }
        }
    }
    b[i][maxlen]='\0';
    for(i=0;i<n;i++)
    {
        printf("%s\n",b[i]);
    }
    for(j=maxlen-1;j>=0;j--)
    {
        countSort(b,j,0,n-1);
        /*for(i=0;i<n;i++)
        {
            printf("%s\n",b[i]);
        }
        */
    }
    for(i=0;i<n;i++)
    {
        printf("%d %s\n",i,b[i]);
    }
    return 0;
}
