#include<stdio.h>
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
  int t,n,i,s[10002],sum[10002],sumrev[10000],r[10002],l[10002],inter[10005],out[10005];
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%d",&s[i]);
	}
      sum[0]=s[0];
       for(i=1;i<n;i++)
	{
	  sum[i]=s[i]+sum[i-1];
	}
       sumrev[n-1]=s[n-1];
       for(i=n-2;i>=0;i--)
	 {
	   sumrev[i]=s[i]+sumrev[i+1];
	 }
       for(i=0;i<n;i++)
	 {
	   r[i]=search(sum,i,n-1,sum[i]+s[i]);//r[i] is index
	   l[i]=search(sumrev,0,i,sumrev[i]+s[i]);
	   if(l[i]>=0) inter[l[i]]++;
	   if(r[i]<n-1)  inter[r[i]+1]--;
	 }
       for(i=0;i<n;i++)
	 {
	   out[i]+=inter[i]+out[i-1];
	 }
       for(i=0;i<n;i++)
	 printf("%d ",out[i]);
    }
}

