#include<stdio.h>
void merge(int arr[], int l, int m, int r)
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
            //brr[k] = lb[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            //brr[k] = rb[j];
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
void mergeSort(int arr[], int l, int r)
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
int search(int *array, int start_idx, int end_idx, int search_val) {

   if( start_idx == end_idx )
      return array[start_idx] <= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < array[mid_idx] )
      return search( array, start_idx, mid_idx, search_val );

   int ret = search( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}
int main()
{
    int n=0,m,l,r,a[100001]={0},k,last_ind,ind,i,j,q;
    scanf("%d %d",&n,&m);
    //printf("scaned\n");
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        //printf("scaned\n");
        for(j=l-1;j<r;j++)
        {
            a[j]++;
        }
    }
     //for(i=0;i<n;i++) printf(" %d\n",a[i]);
    mergeSort(a,0,n-1);
    //for(i=0;i<n;i++) printf(" %d\n",a[i]);
    int b[2][100000]={0};
    b[0][0]=a[0];b[1][0]=1;
    k=0;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            //b[k][1]++;
        }
        if(a[i]!=a[i-1])
        {
            k++;b[0][k]=a[i];
        }
        b[1][k]++;
    }
    last_ind=k;
    for(i=last_ind-1;i>=0;i--)
    {
        b[1][i]+=b[1][i+1];
    }
    scanf("%d",&q);
    for(j=0;j<q;j++)
    {
        scanf("%d",&k);
        ind=search(b[0],0,last_ind,k);
        if(b[0][ind]==k) printf("%d\n",b[1][ind]);
        else if(b[0][ind]<k && ind!= last_ind) printf("%d\n",b[1][ind+1]);
        else printf("0\n");
    }
}
