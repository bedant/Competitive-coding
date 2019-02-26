#include<stdio.h>
long long int partition (long long int arr[],long long int  low,long long int  high)
{
    // pivot (Element to be placed at right position)
    long long int temp,pivot = arr[low];

    long long int j=high,i = (low +1);  // Index of smaller element

    while(i<j)
    {
       for(;i<j;i++)
       {
           if(arr[i]>pivot) {break;}
       }
       if(i>=j)
       {
           if(arr[i]<pivot)
              i++;
            break;
       }
       for(;j>i;j--)
       {
           if(arr[j]<pivot) break;
       }
       if(i>=j) break;
       temp=arr[i]; arr[i]=arr[j];  arr[j]=temp;
    }
    temp=arr[i-1]; arr[i-1]=arr[low];  arr[low]=temp;
    return (i - 1);
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
     long long int n,a[100],i;
     scanf("%lld",&n);
     for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    quickSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%lld ",a[i]);
}
