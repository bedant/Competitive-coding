#include<stdio.h>
typedef struct node
{
    int key;
    struct node *next;
}node;
int hash(int a,int n)
{
    return a%n;
}
node* delete(int a,node *strt )
{
    if(strt->key==a) return strt->next;
    node *temp,*prev=strt;
    for(temp=strt;temp!=NULL;prev=temp,temp=temp->next)
    {
        if(temp->key==a)
        {
            prev->next=temp->next;
        }
    }
    return strt;
}
void insert(int a,node **strt )
{
    node *temp;
    if(*strt==NULL)
    {
        *strt=(node *)malloc(sizeof(node));
        printf(" ins\n");
        (*strt)->key=a;
        printf("  ins\n");
        (*strt)->next=NULL;
        printf("   ins\n");
    }
    else
    {
        temp=(*strt)->next;
        (*strt)->next=(node *)malloc(sizeof(node));
        (*strt)->next->key=a;
        (*strt)->next->next=temp;
    }
}
int main()
{
    int i,n,j,a,m,hashno;
    node *arr[1001]={NULL},*temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);;
        hashno=hash(a,n);
        printf("okay\n");
        insert( a,&(arr[hashno]) );
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("arr[%d] :: ",i);
       for(temp=arr[i];temp!=NULL;temp=temp->next)
            printf("%d ",temp->key);
       printf("\n");
    }
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        scanf("%d",&a);
        hashno=hash(a,n);
        arr[hashno]=delete(a,arr[hashno]);
        for(i=0;i<n;i++)
        {
            printf("arr[%d] :: ",i);
            for(temp=arr[i];temp!=NULL;temp=temp->next)
                printf("%d ",temp->key);
            printf("\n");
        }
    }

}
