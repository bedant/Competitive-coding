#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
/*void merge(int arr[],int l,int m,int r)
{
    int brr[r-l+1],cnt,k,i,j;
    for(int i=l;i<=r;i++)
        brr[i-l]=arr[i];
    for(cnt=l,k=m+1,i=0,j=0;i<=m && k+j<=r;cnt++)
    {
        if(brr[i]>brr[k+j]) {arr[cnt]=brr[k+j];j++;}
        else {arr[cnt]=brr[i];i++;}
    }
    for(int x=i;x<=m;x++)
        arr[cnt]=brr[x];
    for(int x=j;k+x<=r;x++)
        arr[cnt]=brr[k+x];
}
void mergeSort(int arr[],int l,int r)
{
    int m=l+(r-l)/2;
    if(l<r)
    {
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
    }
    merge(arr,l,m,r);
}*/
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
long long int power(long long int x, unsigned int y, int p)
{
    long long int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    int t,q,i,j,n,s[100001],max,k;
    long long int ans=0;
    cin>>t;
    f(w,t)
    {
        cin>>n;
        f(i,n)
        {
            cin>>s[i];
        }
        mergeSort(s,0,n-1);
       for(i=0;i<n;i++)
       {
           for(j=i+1;j<n;j++)
           {
               ans+=((power(2,j-i-1,mod))*(s[j]-s[i]))%mod;
               ans=ans%mod;
               //cout<<ans<<endl;
           }
       }
       cout<<ans<<endl;
       ans=0;
    }
}
