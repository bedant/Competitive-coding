#include<stdio.h>
void insert(int a,int arr[],int ind,int fact,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        j=ind+i*fact;
        if(arr[j%m]==-1 || arr[j%m]==-2)
        {
            arr[j%m]=a;
            return;
        }
    }
    printf("already full");
}
int search(int a,int arr[],int ind,int fact,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        j=ind+i*fact;
        if(arr[j%m]==a) return 1;
        if(arr[j%m]==-1) return 0;
    }
    return 0;
}
void delete(int a,int arr[],int ind,int fact,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        j=ind+i*fact;
        if(arr[j%m]==a)
        {
            arr[j%m]=-2;
            return;
        }
        if(arr[j%m]==-1)
            return;
    }
}
int main()
{
    int i,n,j,a,m,hash_1,hash_2,flag;
    int arr[1001],*temp;
    scanf("%d",&n);
    m=2*n+1;
    for(i=0;i<1001;i++)
        arr[i]=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);;
        hash_1=a%m;
        hash_2=a%(m+2);
        //printf("okay\n");
        insert( a,arr,hash_1,hash_2,m );
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
        hash_1=(a%m);
        hash_2=a%(m+2);
        delete(a,arr,hash_1,hash_2,m);
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
        hash_1=(a%m);
        hash_2=a%(m+2);
        flag=search(a,arr,hash_1,hash_2,m);
        printf("        %d",flag);
    }

}


