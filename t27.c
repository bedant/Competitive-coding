#include<stdio.h>
void merge(long long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        {L[i] = arr[l + i];}
    for (j = 0; j < n2; j++)
        {R[j] = arr[m + 1+ j];}

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int bin_srch(long long int a[],long long int val,int l,int r)
{
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[mid]==val) {return mid;}
        if(a[mid]>val)  r=mid-1;
        if(a[mid]<val)  l=mid+1;
    }
    if(a[l]==val) return l;
    return -1;
}
int main()
{
    int t,n,i,k,a[1001],j,last,ind;
    long long int arr1[1000001],res,arr2[1000001];
    scanf("%d",&t);
    while(t--)
    {
        res=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                arr1[k]=1LL*a[i]*a[i]+a[j]*a[j];
                arr2[k]=1LL*a[i]+a[j]*a[j];
                k++;
            }
        }
        last=k;
        k=0;
        mergeSort(arr2,0,last-1);
        //printf("%d\n",last);
        //for(i=0;i<last;i++) printf("%lld  ",arr1[i]);
        long long int brr[2][1000001]={0};
        brr[0][0]=arr2[0];brr[1][0]=1;
        for(i=1;i<last;i++)
        {
            if(arr2[i]!=arr2[i-1])
            {
                k++;
                brr[0][k]=arr2[i];
            }
            brr[1][k]++;
        }
        //for(i=0;i<=k;i++) printf("\n%lld  %lld",brr[0][i],brr[1][i]);
        for(i=0;i<last;i++)
        {
            ind=bin_srch(brr[0],arr1[i],0,k);

            if(ind>=0) {res+=brr[1][ind];}
        }
        printf("%lld\n",res);
    }
}
