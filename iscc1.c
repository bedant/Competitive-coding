#include<stdio.h>
#include<stdio.h>
int partition (int arr[],int  low,int  high)
{
    // pivot (Element to be placed at right position)
    int temp,pivot = arr[high];

    int j,i = (low - 1);  // Index of smaller element

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
void quickSort(int arr[],int  low,int  high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

int main()
{
  int w,t,n,i,min,flag,a[101];
  //node *head,*ptr,*prev;
  scanf("%d",&t);
  for(w=0;w<t;w++)
  {
    flag=0;min=101;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        if(a[i]!=1) break;
    }
    if(i>0 && i<n) printf("%d\n",a[i]);
    if(i==0 || i==n) printf("-1\n");
  }
}
