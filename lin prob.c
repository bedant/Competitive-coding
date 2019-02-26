#include<stdio.h>
void insert(int a,int arr[],int ind,int m)
{
    int i;
    for(i=ind;i<ind+m;i++)
    {
        if(arr[i%m]==-1 || arr[i%m]==-2)
        {
            arr[i%m]=a;
            return;
        }
    }
    printf("already full");
}
int search(int a,int arr[],int ind,int m)
{
    int i;
    for(i=ind;i<ind+m;i++)
    {
        if(arr[i%m]==a) return 1;
        if(arr[i%m]==-1) return 0;
    }
    return 0;
}
void delete(int a,int arr[],int ind,int m)
{
    int i;
    for(i=ind;i<ind+m;i++)
    {
        if(arr[i%m]==a)
        {
            arr[i%m]=-2;
            return;
        }
        if(arr[i%m]==-1)
            return;
    }
}
int main()
{
    int i,n,j,a,m,hashno,flag;
    int arr[1001],*temp;
    scanf("%d",&n);
    m=2*n+1;
    for(i=0;i<1001;i++)
        arr[i]=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);;
        hashno=a%m;
        //printf("okay\n");
        insert( a,arr,hashno ,m);
    }
    //scanf("%d",&n);
    for(i=0;i<m;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&a);
        hashno=(a%m);
        delete(a,arr,hashno,m);
        for(i=0;i<m;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&a);
        hashno=(a%m);
        flag=search(a,arr,hashno,m);
        printf("        %d",flag);
    }

}

