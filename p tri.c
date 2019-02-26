    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    typedef struct sorted
    {
    	int a,index;
    }sorted;

    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(sorted arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        /* create temp arrays */
        sorted L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i].a <= R[j].a)
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
    void mergeSort(sorted arr[], int l, int r)
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

    int main()
    {
    	int n,q,i,choice,x,y;
    	scanf("%d %d",&n,&q);
    	struct sorted b[n];
    	for(i=0;i<n;i++)
    	{
    		scanf("%d",&b[i].a);
    		b[i].index=i;
    	}
    	mergeSort(b,0,n-1);
    	for(;q>0;q--)
    	{
    		scanf("%d %d %d",&choice,&x,&y);
    		if(choice==2)
    		{
    			int c[y-x+1],j=y-x,f=0;
    			for(i=n-1;i>=0;i--)
    			{
    				if((b[i].index>=x-1)&&(b[i].index<=y-1))
    				{
    					c[j]=b[i].a;
    					if(j<=(y-x-2))
    					{
    						if(c[j+2]<(c[j+1]+c[j]))
    						{
    							long int e=c[j];
    							e+=c[j+1];
    							e+=c[j+2];
    							printf("%ld\n",e);
    							f=1;
    							break;
    						}
    					}
    					j--;
    				}
    			}
    			if(f==0)
    			{
    				printf("0\n");
    			}
    		}
    		else
    		{
    			int pos;
    			for(i=0;i<n;i++)
    			{
    				if(b[i].index==x-1)
    				{
    					pos=i;
    					break;
    				}
    			}
    			int t =b[pos].a;
    			b[pos].a=y;
    			sorted temp={y,x-1};
    			if(y>t)
    			{
    				// i=pos+1;
    				// while((b[i].a<y)&&(i!=n))
    				// {
    				// 	b[i-1]=b[i];
    				// 	b[i]=temp;
    				// 	i++;
    				// }
    				int beg=pos,end=n-1,mid;
    				while(beg<=end)
    				{
    					mid=(beg+end)/2;
    					if((y>=b[mid].a)&&(y<b[mid+1].a))
    					{
    						break;
    					}
    					else if(y>b[mid].a)
    					{
    						beg=mid+1;

    					}
    					else
    					{
    						end=mid-1;
    					}
    				}
    				memmove(&b[pos],&b[pos+1],(mid-pos)*sizeof(sorted));
    				b[mid]=temp;
    				// for(i=0;i<n;i++)
    				// {
    				// 	printf("%d ",b[i].a);
    				// }
    				continue;
    			}
    			if(y<t)
    			{
    				// i=pos-1;
    				// while((b[i].a>y)&&(i!=-1))
    				// {
    				// 	b[i+1]=b[i];
    				// 	b[i]=temp;
    				// 	i--;
    				// }
    				int beg=0,end=pos,mid;
    				while(beg<=end)
    				{
    					mid=(beg+end)/2;
    					if((y>=b[mid-1].a)&&(y<b[mid].a))
    					{
    						break;
    					}
    					else if(y>b[mid].a)
    					{
    						beg=mid+1;

    					}
    					else
    					{
    						end=mid-1;
    					}
    				}
    				memmove(&b[mid+1],&b[mid],(pos-mid)*sizeof(sorted));
    				b[mid]=temp;
    				continue;
    			}
    		}
    	}
    	return 0;
    }
