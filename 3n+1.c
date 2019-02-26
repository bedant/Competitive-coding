#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int l,r;
    struct node *next;
}node;
  int partition (  int arr[],  int  low,  int  high)
{
    // pivot (Element to be placed at right position)
      int temp,pivot = arr[high];

      int j,i = (low - 1);  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp=arr[i]; arr[i]=arr[j];  arr[j]=temp;
        }
    }
    temp=arr[i+1]; arr[i+1]=arr[high];  arr[high]=temp;
    return (i + 1);
}
void quickSort(  int arr[],  int low,  int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
          int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
int bin_sear( int a[],int val,int l,int r)
{
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[mid]==val) return mid;
        if(a[mid]<val)  l=mid+1;
        if(a[mid]>val)  r=mid-1;
    }
    if(a[l]==val) return 1;
    return 0;
}
int main()
{
    int t,i,n,k,l[1000000],r[1000000],flag,req_l,req_r,lpt,rmax;
    node *temp;
    scanf("%d",&t);
    while(t--)
    {
        node *list[1000000]={NULL};
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            if(list[l[i]]==NULL)
            {
                list[l[i]]=malloc(sizeof(node));
                list[l[i]]->l=l[i];
                list[l[i]]->r=r[i];
                list[l[i]]->next=NULL;
            }
            else
            {
                temp=malloc(sizeof(node));
                temp->l=l[i];
                temp->r=r[i];
                temp->next=list[l[i]];
                list[l[i]]=temp;
            }
        }
        /*for(i=0;i<10;i++)
        {
            printf("\nlist[%d]::",i);
            for(temp=list[i];temp!=NULL;temp=temp->next)
                printf("(%d,%d) ",temp->l,temp->r);
            printf("\n");
        }*/
        quickSort(r,0,n-1);
        flag=0;
        for(i=0;i<n;i++)
        {
            //printf("i=%d\n",i);
            req_l=l[i];
            req_r=l[i]+k;
            lpt=l[i];
            rmax=lpt;
            if(bin_sear(r,req_r,0,n-1))
            {
                //printf("in if 1\n");
                for(lpt=l[i];lpt<=rmax;lpt++)
                {
                    //printf("lpt=%d rmax=%d\n",lpt,rmax);
                    for(temp=list[lpt];temp!=NULL;temp=temp->next)
                    {
                      //  printf("%d\n",temp->r);
                        if(temp->r > rmax && temp->r<=req_r)
                        {
                            rmax=temp->r;
                            if(rmax==req_r)
                            {
                                flag=1;break;
                            }
                        }
                    }
                    if(flag==1) break;
                }
                if(flag==1) break;
            }
        }
        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }
}
