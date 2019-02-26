#include<stdio.h>
int partition ( int arr[],int low,int high)
{
    // pivot (Element to be placed at right position)
    int pivot = arr[high];

    int j,temp,i = (low - 1) ; // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp= arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    temp= arr[i + 1];arr[i+1]=arr[high];arr[high]=temp;
    return (i + 1);
}

void quickSort( int arr[],int low,int high)
{
	int pi;
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
int main()
{
    int n,s[50005],t[50005],m,x,j,i,ans;
    scanf("%d%d%d",&n,&m,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        s[i]=s[i]%x;
    }
    for(j=0;j<m;j++)
    {
        scanf("%d",&t[j]);
        t[j]=t[j]%x;
    }
    quickSort(s,0,n-1);
    quickSort(t,0,m-1);
    ans=s[n-1]+t[m-1]-s[0]-t[0];
    printf("%d\n",ans);
}
