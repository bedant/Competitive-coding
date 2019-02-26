#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
typedef struct node node;
int main()
{
    int t,n,i;
    node *head,*ptr,*prev,*temp,*even_ind,*even,*prev_ev,*stop,*temp2;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        head=(node *)malloc(sizeof(node));
        scanf("%d",&head->val);
        head->next=NULL;
        if(n==1) printf("%d\n",head->val);
        else{
        for(i=1;i<n;i++)
        {
           // printf("1st\n");
            ptr=(node *)malloc(sizeof(node));
            scanf("%d",&ptr->val);
            if(i==1)
            {
                //prev=head;
                head->next=ptr;
                ptr->next=NULL;
                prev=ptr;
            }
            else
            {
                prev->next=ptr;
                ptr->next=NULL;
                prev=ptr;
            }
        }
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            //printf(" %d",temp->val);
        }
        //printf("\n");
        prev=NULL;
        even_ind=head;
        for(;even_ind!=NULL;prev=even_ind,even_ind=even_ind->next)
        {
            //printf("2nd\n");
            if(even_ind->val%2==0) break;
        }
        if(even_ind==NULL)
            {for(;;head=head->next)
            {
               printf("%d ",head->val);
                if(head->next==NULL) break;}
            }
        else{
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            //printf("a %d",temp->val);
        }
        even=even_ind;
        prev_ev=prev;
        prev=NULL;
        even_ind=head;
        for(;even_ind!=NULL;prev=even_ind,even_ind=even_ind->next)
        {if(even_ind->val%2) break;}
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            //printf("b %d",temp->val);
        }
        if(prev==NULL) {temp=head;head=even;temp2=prev_ev->next->next; head->next=temp;prev_ev->next=temp2;prev=head;}
        stop=prev;
        //printf("%d %d %d %d\n",head->val,prev->val,even_ind->val,even->val);
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            //printf("\nc %d",temp->val);
        }
        for(; even_ind!=NULL;i++,prev=even_ind,even_ind=even_ind->next)
        {
            //printf("4t\n");
            if(even_ind->val%2==0)
            {
                temp2=prev->next->next;
                temp=stop->next;
                //printf("a %d %d \n",temp2->val,temp->val);
                stop->next=even_ind;
                even_ind->next=temp;
                stop=stop->next;
                prev->next=temp2;
               // printf("b %d %d %d %d\n",stop->val,prev->val,even_ind->val,even->val);
            }
        }
        for(;;head=head->next)
        {printf("%d ",head->val);
        if(head->next==NULL) break;}
        }
        }
        t--;
    }
}
