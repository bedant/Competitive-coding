#include<stdio.h>
//#include<math.h>
struct entint
{
    long long int a;
    int ind;
};
void insertionSort(struct entint arr[], int n)
{
   int i, key, j;
   struct entint arrkey;
   for (i = 1; i < n; i++)
   {
       key = arr[i].a;
       arrkey=arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j].a > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = arrkey;
   }
}
int partition (struct entint arr[],int low,int high)
{
    // pivot (Element to be placed at right position)
    long long int pivot = arr[high].a;

    int j,i = (low - 1) ; // Index of smaller element
    struct entint temp;
    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].a <= pivot)
        {
            i++;    // increment index of smaller element
            temp= arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    temp= arr[i + 1];arr[i+1]=arr[high];arr[high]=temp;
    return (i + 1);
}

void quickSort(struct entint arr[],int low,int high)
{
	int pi;
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
long long int perime(long long int b[],int low,int high)
{
	int i,j;
	//quickSort(b,low,high);
	for(i=high;i>=low+2 && b[i-2]>0 && b[i-1]>0;i--)
	 {
	 	if(b[i]<b[i-1]+b[i-2])
	 	{
	 		//printf(" %d %d %d\n",b[i],b[i-1],b[i-2]);
	 		//printf("%lld %lld %lld",b[i],b[i-1],b[i-2]);
			return b[i]+b[i-1]+b[i-2];
		}
	 }
	return 0;
}
int main()
{
	int i,j,n,q,k,opt,n1,n2,temp;
	struct entint b[100000];
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		{
		    scanf("%d",&b[i].a);
		    b[i].ind=i;
        }
    quickSort(b,0,n-1);
	for(j=0;j<q;j++)
	{
		scanf("%d%d%d",&opt,&n1,&n2);
		if(opt==1)
        {
            for(i=0;i<n;i++)
            {

                if(b[i].ind==n1-1)
                {
                    //printf("%lld %d\n",b[i],ind[b[i]]);
                    b[i].a=n2;
                    //for(k=0;k<n;k++) printf("     %lld",b[k]);
                    //ind[b[i]]=n1-1;ind[temp]=0;
                    //printf("ind[%lld]=%d\n",b[i],ind[b[i]]);
                    insertionSort(b,n);
                    //for(k=0;k<n;k++) printf("  sorted   %lld",b[k]);
                    break;
                }
            }
        }
        if(opt==2)
		{
		    long long int c[n2-n1+1];
			if(n<3 || n2-n1<2) printf("0\n");
			else
			{
            //for(k=0;k<n;k++) printf("  b[]= %lld\n",b[k]);
			for(k=0,i=0;i<n;i++)
            {
                if(b[i].ind<n2 && b[i].ind>=n1-1)
                    {c[k]=b[i].a;k++;}
            }
			//for(i=0;i<n;i++) printf(" %lld",b[i]);
			//for(i=n1-1;i<n2;i++) b[i]*=-1;
			printf("%lld\n",perime(c,0,n2-n1));
			}
		}
	}
}
