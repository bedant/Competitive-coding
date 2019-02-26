#include<stdio.h>
struct node
{
    unsigned int val,xor;
};
typedef struct node node;
void print_list(node *head)
{
    printf(" %d\n",head->val);
    node *ptr,*prev;
    unsigned int temp;
    prev=head;
    ptr=head->xor;
    while(ptr->xor!=prev)
    {
        printf(" %d\n",ptr->val);
        temp=(int)prev^(int)ptr->xor;
        prev=ptr;
        ptr=temp;
    }
    printf(" %d\n",ptr->val);
}
void print_rev(node *head)
{
    node *ptr,*prev,*prnt;
    unsigned int temp;
    prev=head;
    ptr=head->xor;
    int cnt=1;
    while(ptr->xor!=prev)
    {
        //printf("%d\n",ptr->val);
        temp=(int)prev^(int)ptr->xor;
        prev=ptr;
        ptr=temp;
        cnt++;
    }
    cnt++;
//    last=ptr;lt2=prev
    printf("%d\n%d\n",ptr->val,prev->val);
    int i;
    for(i=0;i<cnt;i++)
    {
        prnt=prev->xor^(int)ptr;
        printf("%d\n",prnt->val);
        ptr=prev;
        prev=prnt;
        if(prnt==head) break;
    }
    return;
}
void reverse(node **headp,node** tailp)
{
    node *temp;
   // ptr_l=headp;ptr_r=tailp;
    //bef_l=headp;bef_r=tailp;
    temp=*headp;*headp=*tailp;*tailp=temp;
    printf("reversed\n");
}

int main()
{
    node *head,*ptr,*prev,*prev2,**tail_add;
    int n,i;
    head=(node *)malloc(sizeof(node));
    scanf("%d",&n);
    scanf("%d",&head->val);
    for(i=1;i<n;i++)
    {
        ptr=(node *)malloc(sizeof(node));
        scanf("%d",&ptr->val);
        if(i==1) {head->xor=ptr;prev2=head;prev=ptr;}
        else
        {
            prev->xor=(int)(prev2)^(int)ptr;
            prev2=prev;prev=ptr;
        }
    }
    ptr->xor=prev2;
    tail_add=&ptr;
    //end_xor=prev2;
    print_list(head);
    printf("\n");
    print_rev(head);
    reverse(&head,tail_add);
    print_list(head);
}
