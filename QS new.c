#include<stdio.h>
long long int partition (long long int arr[],long long int  low,long long int  high)
{
    // pivot (Element to be placed at right position)
    long long int temp,x = arr[(low+high)/2];

    long long int j=high  ,i = (low ),k;  // Index of smaller element

    while(1)
    {
       for(;(arr[j]>x);j--);
       for(;(arr[i]<x);i++);
        printf(" %lld i=%lld j=%lld\n",x,i,j);
       if(i<j)
            {
            temp=arr[i]; arr[i]=arr[j];  arr[j]=temp;
            for(k=0;k<8;k++)
                printf("%lld ",arr[k]);
            printf("\n");
            }
        else
        {
            for(k=0;k<8;k++)
                printf("%lld ",arr[k]);
            printf("\n%d\n",j);
            return (j);
        }
    }
}
void quickSort(long long int arr[],long long int low,long long int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        long long int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1 );  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
int main()
{
     long long int n,a[100],i;
     scanf("%lld",&n);
     for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    quickSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%lld ",a[i]);
}
