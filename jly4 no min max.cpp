#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mods 1000000007
void merge(long long int arr[],long long  int l,long long  int m,long long  int r)
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
void mergeSort(long long int arr[],long long  int l,long long  int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long long  int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
long long int powers(long long int x, unsigned int y, int p)
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
/*unsigned long long int cmb(unsigned long long  int  n,unsigned long long int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

   //if(k==0) return 1;
    if(k==1) return n%(mods-1);
    if(n==k) return 1;
    //if(n<k)  return 0;
    return 1LL*(cmb(n-1,k-1)+cmb(n-1,k))%(mods-1);
}
*/
int main()
{
    long long int w,t,i,min,n,k,a[5003];
    unsigned long long int pro,po;
    long long int cmb[5000][5000];
    f(i,5001)
    {
        f(j,5001)
        {
            if(i<j)  {cmb[i][j]=0;continue;}
            if(i==j) {cmb[i][j]=1;continue;}
            if(j==0) {cmb[i][j]=1;continue;}
            if(i==0) {cmb[i][i]=0;continue;}

            cmb[i][j]=(cmb[i-1][j-1]+cmb[i-1][j])%(mods-1);
        }
    }
    //cout<<cmb[40][15];
    cin>>t;
    f(w,t)
    {
        pro=1;
        cin>>n>>k;
        for(i=1;i<=n;i++)
            cin>>a[i];
        mergeSort(a,1,n);
        for(i=2;i<n;i++)
        {
            po=(mods-1)*2+cmb[n-1][k-1]-cmb[i-1][k-1]-cmb[n-i][k-1];
            po=po%1000000006;
            pro=pro*powers(a[i],po,mods);
            pro=pro%mods;
        }
        cout<<pro<<endl;
    }
}
