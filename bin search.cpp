#include<iostream>
#include<cmath>
using namespace std;
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
    int i,n,a[100],val;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<5;i++)
    {
        cin>>val;
        cout<<search(a,0,n-1,val)<<endl;
    }
}
