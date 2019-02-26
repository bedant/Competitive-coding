#include<stdio.h>
//#include<math.h>
int partition (long long int arr[],int low,int high)
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

void quickSort(long long int arr[],int low,int high)
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
long long int perime(long long int b[],int l,int r)
{
	int i;
	quickSort(b+l,0,r-l);
	for(i=r;i>=2;i--)
	 {
	 	if(b[r]<=b[r-1]+b[r-2])
		return b[r]+b[r-1]+b[r-2];
	 }
	return 0;
}
int main()
{
	int i,j,n,q,opt,n1,n2;
	long long int a[100000],b[100000];
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(j=0;j<q;j++)
	{
		scanf("%d%d%d",&opt,&n1,&n2);
		if(opt==1)
			a[n1-1]=n2;
		if(opt==2)
		{
			if(n<3) printf("0\n");
			else
			{
			for(i=0;i<n;i++) b[i]=a[i];
			printf("%lld\n",perime(b,n1-1,n2-1));
			}
		}
	}
}
