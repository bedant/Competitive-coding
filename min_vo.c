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
int revsearch(int *array,int start_idx,int end_idx,int search_val)
{
    int a2[end_idx-start_idx+1],i,j;
    for(i=end_idx,j=0;i>=start_idx;i--,j++)
    {
        a2[j]=array[i];
    }
    return (end_idx-search(a2,0,end_idx-start_idx,search_val));
}
int main()
{
  int t,n,i,s[10002],sum[10002],sumrev[10002],r[10002],l[10002],out[100005];
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
    /*for(i=0;i<n;i++)
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

