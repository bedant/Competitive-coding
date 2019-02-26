#include<stdio.h>
int min(int a,int b)
{
    if(a>b) return b;
    return a;
}
int partition ( int arr[],int low,int high)
{
    // pivot (Element to be placed at right position)
    int pivot = arr[high];

    int j,temp,i = (low - 1) ; // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp= arr[i]; arr[i]=arr[j]; arr[j]=temp;
        }
    }
    temp= arr[i + 1];arr[i+1]=arr[high];arr[high]=temp;
    return (i + 1);
}

void quickSort( int arr[],int low,int high)
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
int main()
{
    int n,s[50005],t[50005],m,term1,term2,x,pos,j,i,ans,max1,max2,dif,k,t1,t2,mt1,w,mt2;
    scanf("%d%d%d",&n,&m,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        s[i]=s[i]%x;
    }
    for(j=0;j<m;j++)
    {
        scanf("%d",&t[j]);
        t[j]=t[j]%x;
    }
    mt1=100000000;mt2=100000000;
    for(w=0;w<500;w++)
    {
    quickSort(s,0,n-1);
    quickSort(t,0,m-1);
    term1=s[n-1]-s[0];
    term2=t[m-1]-t[0];
    if(term1<mt1) mt1=term1;
    if(term2<mt2) mt2=term2;
    //t1=s[n-1]-s[0];
    max1=0;
    for(i=1;i<n;i++)
    {
        dif=s[i]-s[i-1];
        if(dif>max1)
        {
            max1=dif;
            pos=i;
        }
    }
    for(k=0;k<pos;k++)
    {
        s[k]+=x;
    }
    max2=0;
    //t2=t[n-1]-t[0];
    for(j=1;j<m;j++)
    {
        dif=t[j]-t[j-1];
        if(dif>max2)
        {
            max2=dif;
            pos=j;
        }
    }
    for(k=0;k<pos;k++)
    {
        t[k]+=x;
    }
    }
    /*for(i=0;i<n;i++)
    {
        printf("%d  ",s[i]);
    }
    printf("\n");
    for(j=0;j<m;j++)
    {
        printf("%d  ",t[j]);
    }
    printf("max1=%d max2=%d\n",max1,max2);*/
    ans=mt1+mt2;

    printf("%d\n",ans);
}
