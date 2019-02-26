#include<stdio.h>
int main()
{
  int t,n,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    if(n>10)
    {
      for(i=0;i<n;i++)
      {
        if((i==0 || arr[i]<arr[i-1]) && (i==(n-1) || arr[i]<arr[i+1]))
        {
          if((i<n-2) && (i==(n-3) || arr[i+2]<arr[i+3]) && (arr[i+2]<arr[i+1]) && (arr[i]+arr[i+2]>=arr[i+1]))
          {
            if((i<n-4) && (i==(n-5) || arr[i+4]<arr[i+5]) && (arr[i+4]<arr[i+3]) && (arr[i+2]+arr[i+4]>=arr[i+3]))
            {
              int j;
              for(j=i+6;j<n;j+=2)
              {
                if((arr[j]<arr[j-1]) && (j==(n-1) || arr[j]<arr[j+1]) && (arr[j-2]+arr[j]>=arr[j-1]))
                continue;
                else
                break;
              }
              int p=(j-i)/2,brr[2][p];
              long long int sum1,sum2,temp;
              brr[0][0]=1;
              brr[0][1]=i;
              sum1=arr[i];
              if(arr[i+2]>arr[i])
              {
                brr[1][0]=1;
                brr[1][1]=i+2;
                sum2=arr[i+2];
              }
              else
              {
                brr[1][0]=1;
                brr[1][1]=i;
                sum2=arr[i];
              }
              int x=0;
              for(j=2;j<p;j++)
              {
                if((temp=sum1+arr[i+2*j])>sum2)
                {
                  brr[x][0]++;
                  brr[x][brr[x][0]]=i+2*j;
                  sum1=sum2;
                  sum2=temp;
                  x=!x;
                }
                else
                {
                  sum1=sum2;
                  int k;
                  for(k=0;k<=brr[!x][0];k++)
                  brr[x][k]=brr[!x][k];
                  x=!x;
                }
              }
              for(j=1;j<=brr[!x][0];j++)
              arr[brr[!x][j]]=-arr[brr[!x][j]];
              i=i+(2*p)-1;
            }
            else
            {
              if(arr[i]>arr[i+2])
              arr[i]=-arr[i];
              else
              arr[i+2]=-arr[i+2];
              i+=3;
            }
          }
          else
          {
            arr[i]=-arr[i];
            i+=1;
          }
        }
      }
    }
    else
    {
      for(i=0;i<n;i++)
    {
      if((i==0 || arr[i]<arr[i-1]) && (i==(n-1) || arr[i]<arr[i+1]))
      {
        if((i<n-2) && (i==(n-3) || arr[i+2]<arr[i+3]) && (arr[i+2]<arr[i+1]) && (arr[i]+arr[i+2]>=arr[i+1]))
        {
          if((i<n-4) && (i==(n-5) || arr[i+4]<arr[i+5]) && (arr[i+4]<arr[i+3]) && (arr[i+2]+arr[i+4]>=arr[i+3]))
          {
            int j;
            for(j=i+6;j<n;j+=2)
            {
              if((arr[j]<arr[j-1]) && (j==(n-1) || arr[j]<arr[j+1]) && (arr[j-2]+arr[j]>=arr[j-1]))
              continue;
              else
              break;
            }
            int p=(j-i)/2,sub[p][p];
            long long int sum1,sum2,temp;
            sub[0][0]=1;
            sub[0][1]=i;
            sum1=arr[i];
            if(arr[i]<arr[i+2])
            {
              sub[1][1]=i+2;
              sum2=arr[i+2];
              sub[1][0]=1;
            }
            else
            {
              sub[1][1]=i;
              sum2=arr[i];
              sub[1][0]=1;
            }
            for(j=2;j<p;j++)
            {
              int d;
              if((temp=sum1+arr[i+2*j])>sum2)
              {
                for(d=0;d<=sub[j-2][0];d++)
                sub[j][d]=sub[j-2][d];
                sub[j][d]=i+2*j;
                sub[j][0]++;
                sum1=sum2;
                sum2=temp;
              }
              else
              {
                for(d=0;d<=sub[j-1][0];d++)
                sub[j][d]=sub[j-1][d];
                sum1=sum2;
              }
            }
            for(j=1;j<=sub[p-1][0];j++)
            arr[sub[p-1][j]]=-arr[sub[p-1][j]];
            i=i+(2*p)-1;
          }
          else
          {
            if(arr[i]>arr[i+2])
            arr[i]=-arr[i];
            else
            arr[i+2]=-arr[i+2];
            i+=3;
          }
        }
        else
        {
          arr[i]=-arr[i];
          i+=1;
        }
      }
    }
    }
    for(i=0;i<n-1;i++)
    printf("%d ",arr[i]);
    printf("%d\n",arr[n-1]);
  }
  return 0;
}
