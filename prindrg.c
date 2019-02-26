#include<stdio.h>
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
void merge(  int arr[],   int l,   int m,   int r)
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
void mergeSort(  int arr[],   int l,   int r)
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
int finish_rem(int a[],int n,int rem)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(rem-a[i]<=0)
        {
            a[i]=0;
            break;
        }
    }
   /* printf("i=%d\n",i);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/
    return a[i];
}
int main()
{
    int t,n,i,a[100001],b[100001],c[100001],j,rem,p,cnt,cnt1,cnt2,maxm;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&p);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        mergeSort(a,0,n-1);
        maxm=a[n-1];
        /*for(i=0;i<n;i++)
            printf("%d ",a[i]);*/
        rem=p;
        for(i=n-1,cnt=0;i>=0;i--,cnt++)
        {
            if(rem>a[i])
            {
                rem-=a[i];
                a[i]=0;
            /*printf("\n");
            for(j=0;j<n;j++)
                printf("   %d ",a[j]);*/
            }
            else
            {
                finish_rem(a,n,rem);
                //cnt++;
                break;
            }
        }
        cnt1=cnt;
        cnt=1;
        mergeSort(a,0,n-1);
       /* printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);*/
        rem=p-maxm;
        for(i=n-1;i>=0 && rem>0;i--,cnt++)
        {
            if(rem>a[i])
            {
                rem-=a[i];
                a[i]=0;
            }
            else
            {
                rem=rem-finish_rem(a,n,rem);
                //cnt++;
                break;
            }
        }
       // printf("\n");
        /*for(i=0;i<n;i++)
            printf("%d ",a[i]);*/
        cnt2=cnt;
        //printf("\n%d %d\n",cnt1,cnt2);
        for(i=0;i<n;i++)
        {
            b[i]=max(i,n-i-1)-min(cnt1,cnt2)+1;
            c[i]=min(i,n-i-1)-max(cnt1,cnt2)+1;
            if(b[i]<0) b[i]=0;
            if(c[i]<0) c[i]=0;
            b[i]+=c[i];
            printf("%d ",b[i]);
        }
        printf("\n");
    }
}
