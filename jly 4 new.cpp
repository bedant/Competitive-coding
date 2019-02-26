#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mods 1000000007
#define ll long long
long long int factorial[100002];
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
ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}

ll nCr(ll n, ll k, ll mod){
    if(k==0) return 1;
    if(k==1) return n%mod;
    if(n==k) return 1;
    if(n<k)  return 0;
    return (nCr(n-1,k-1,mod)+nCr(n-1,k,mod))%1000000006;
}
int main()
{
    int t,n,k,i,j,a[100005];
    long long int p,pro;
    cin>>t;
    factorial[0]=1;
    f(i,100000)
        i++;
        factorial[i]=i*factorial[i-1];
    f(w,t)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        mergeSort(a,1,n);
        for(i=2;i<n;i++)
        {
         p=1000000006*2+nCr(n-1,k-1,1000000006)-nCr(i-1,k-1,1000000006)-nCr(n-i,k-1,1000000006);
         p=p%1000000006;
         pro*=power(a[i],p,mods);
         pro=pro%mods;
        }
    }
}
