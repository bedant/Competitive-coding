#include<stdio.h>
int search(long long int *array, int start_idx, int end_idx,long long int search_val) {

   if( start_idx == end_idx )
      return array[start_idx] <= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < array[mid_idx] )
      return search( array, start_idx, mid_idx, search_val );

   int ret = search( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}
int revsearch(long long int *array,int start_idx,int end_idx,long long int search_val)
{
     if( start_idx == end_idx )
      return array[start_idx] >= search_val ? start_idx : -1;

   int mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val > array[mid_idx] )
      return revsearch( array, start_idx, mid_idx, search_val );

   int ret = revsearch( array, mid_idx+1, end_idx, search_val );
   return ret == -1 ? mid_idx : ret;
}
int main()
{
  int t,n,i,s[100002],r[100002],l[100002],out[100005];
  long long int sum[100002],sumrev[100002];
  scanf("%d",&t);
  while(t--)
    {
    int inter[100005]={0};
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
	 /*for(i=0;i<n;i++)
        printf("in %d ",inter[i]);
        printf("\n");*/
       for(i=0;i<n;i++)
	 {
	   r[i]=search(sum,i,n-1,sum[i]+s[i])+1;//r[i] is index
	   l[i]=revsearch(sumrev,0,i,sumrev[i]+s[i])-1;
	   if(l[i]>=0 && sumrev[l[i]+1]!=sumrev[i]+s[i]) l[i]++;
	   if(l[i]>=0) inter[l[i]]++;
	   else inter[0]++;
	   if(r[i]<n-1)  inter[r[i]+1]--;
	   //else inter[n-1]--;
	 }
	 out[0]=inter[0];
       for(i=1;i<n;i++)
	 {
	   out[i]=inter[i]+out[i-1];
	 }
   /* for(i=0;i<n;i++)
        printf(" ou %d ",out[i]);
        printf("\n");
       for(i=0;i<n;i++)
        printf("s %d ",s[i]);
	 printf("\n");
       for(i=0;i<n;i++)
        printf("sum %d ",sum[i]);
	 printf("\n");
       for(i=0;i<n;i++)
        printf("%d ",sumrev[i]);
	 printf("\n");
       for(i=0;i<n;i++)
        printf("l %d ",l[i]);
        printf("\n");
       for(i=0;i<n;i++)
        printf("r %d ",r[i]);
        printf("\n");
       for(i=0;i<n;i++)
        printf("%d ",inter[i]);
        printf("\n");
    */
       for(i=0;i<n;i++)
        printf("%d ",out[i]-1);
        printf("\n");
    }
}

