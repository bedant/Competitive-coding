#include<stdio.h>
long long int minm(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
long long int partition (long long int arr[],long long int  low,long long int  high)
{
    // pivot (Element to be placed at right position)
    long long int temp,pivot = arr[high];

    long long int j,i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp=arr[i]; arr[i]=arr[j];  arr[j]=temp;
        }
    }
    temp=arr[i+1]; arr[i+1]=arr[high];  arr[high]=temp;
    return (i + 1);
}
void quickSort(long long int arr[],long long int low,long long int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        long long int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
int main()
{
    //short int b[1000000001]={0};
    long long int t,n,i,k,x,a[20002],min,temp,max,cnt,sum,temsum;
    scanf("%lld",&t);
    while(t--)
    {
        temsum=0;sum=0;
        //short int b[1000000001]={0};
        scanf("%lld%lld%lld",&n,&k,&x);
        for(i=0;i<k;i++)
        {
            scanf("%lld",&a[i]);
            temsum+=a[i];
            if(a[i]<min) min=a[i];
            //b[a[i]]=1;
        }
        max=min+x;
        //printf("%lld %lld\n",temsum,max);
        cnt=0;
        quickSort(a,0,k-1);

        for(i=k-1;i>=0;i--)
        { //printf("%lld ",a[i]);
            if(a[i]>=max-n+k+1-cnt )
            {
                cnt++;
                sum-=a[i];
            }
        }
        //printf("%lld  sum %lld\n",cnt,sum);
        sum+=temsum;
        temp=max-(n-k)-cnt;
        //printf("sum %lld  temp %lld\n",sum,temp);
        sum=sum+max*(max+1)/2-temp*(temp+1)/2;
        printf("%lld\n",sum);
    }
}
