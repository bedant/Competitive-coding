/*for(low=0,high=n-1;high-low>1;)
            {
                if(x>=lft_lsorted[n-1]) {low=n-1;break;}
                mid=(low+high)/2;
                //cout<<"mid="<<mid<<endl;
                if(x==lft_lsorted[mid])
                    {break;}
                if(x>lft_lsorted[mid])
                {
                    low=mid;
                    //cout<<"low=mid+1 "<<mid<<endl;
                }
                if(x<lft_lsorted[mid])
                {
                    //cout<<"high=mid-1 "<<mid<<endl;
                    high=mid;
                }
            }
            */
#include<iostream>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int search(int *array, int start_idx, int end_idx, int search_val) {

   if( start_idx == end_idx )
      return array[start_idx] <= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < array[mid_idx] )
      return search( array, start_idx, mid_idx, search_val );

   int ret = search( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}
void merge(int arr[], int l, int m, int r,int brr[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2],lb[n1],rb[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        {L[i] = arr[l + i];lb[i]=brr[l+i];}
    for (j = 0; j < n2; j++)
        {R[j] = arr[m + 1+ j];rb[j]=brr[m+1+j];}

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            brr[k] = lb[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            brr[k] = rb[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];brr[k]=lb[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];brr[k]=rb[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r,int brr[])
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m,brr);
        mergeSort(arr, m+1, r,brr);

        merge(arr, l, m, r,brr);
    }
}
int find_rfcl(int a,int n,int rt_rsorted[])
{
    int ans=search(rt_rsorted,0,n-1,a);
    if(ans<0 || rt_rsorted[ans]<a) ans++;
    return rt_rsorted[ans];
}
/*int minm(int a[],int left,int right)
{
    int min1=a[left];
    for(int i=left+1;i<=right;i++)
    {
        if(a[i]<min1) min1=a[i];
    }
    return min1;
}
*/
int main()
{
    int t,n,i,j,k,l,cnt,r,high,low,mid,w,m,term,b,x,rfcl[2002],sum=0,check=1,lft_lsorted[100000],rt_lsorted[100000],lft_rsorted[100000],rt_rsorted[100000];
    cin>>t;
    f(w,t)
    {
        int flag=0;
        cin>>n;
        f(i,n)
        {
            cin>>lft_lsorted[i]>>rt_lsorted[i];
            lft_rsorted[i]=lft_lsorted[i];
            rt_rsorted[i]=rt_lsorted[i];
        }
        mergeSort(lft_lsorted,0,n-1,rt_lsorted);
        mergeSort(rt_rsorted,0,n-1,lft_rsorted);
        for(i=0;i<n;i++)
        {
            rfcl[lft_lsorted[i]]=find_rfcl(lft_lsorted[i],n,rt_rsorted);
            //cout<<"rfcl["<<lft_lsorted[i]<<"]"<<"="<<rfcl[lft_lsorted[i]]<<endl;
        }
        //mergesort(rt_rsorted,lft_rsorted);
        low=0;
        for(l=0,cnt=0;l<n;cnt++)
        {
            //if(l==n-1) flag=1;
            x=rfcl[lft_lsorted[l]];
            low=search(lft_lsorted,0,n-1,x);
            cout<<"x="<<x<<endl;

            //cout<<"  low="<<low<<" mid= "<<mid<<endl;
            l=low+1;
            cout<<"ll "<<l<<endl;
            cout<<"cnt "<<cnt<<endl;
        }
        //f(i,n){//cout<<lft_lsorted[i]<<"   "<<rt_lsorted[i]<<endl;}
        cout<<cnt<<endl;
    }
}
