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
    int t,w,n,k,i,j,alen,blen,temp,givk;
    long long int suma,sumb;
    scanf("%d",&t);
    for(w=0;w<t;w++)
{
    suma=0;sumb=0;
    int a[100000]={0},b[100000]={0};
        scanf("%d%d",&n,&givk);
        for(i=0,j=0,k=0;k<n;k++)
    {
        if(k%2==0) {scanf("%d",&a[i]);i++;}
        if(k%2) {scanf("%d",&b[j]);j++;}
    }
    alen=i;blen=j;
    quickSort(a,0,alen-1);
    quickSort(b,0,blen-1);
    for(i=0,j=alen-1,k=0;k<givk && i<blen && j>=0; i++ , j--,k++)
    {
        if(b[i]<a[j])
        {
            temp=b[i];b[i]=a[j];a[j]=temp;
        }
    }
    for(i=0;i<alen;i++)
        {
            suma+=a[i];
        //    printf("%d ",a[i]);
        }
    for(i=0;i<blen;i++)
        {
            sumb+=b[i];
        //    printf("%d ",b[i]);
        }
    //printf("\n%d   %d\n",suma,sumb);
    if(sumb>suma) printf("YES\n");
    else printf("NO\n");
}
}
