#include<stdio.h>
typedef struct node
{
    struct node * left;
    struct node * right;
    int key;
}node;
typedef struct que_nod
{
    struct node *bt_node;
    struct que_nod *next;
}que_nod;
typedef struct QUEUE
{
    struct que_nod* front;
    struct que_nod* rear;
}QUEUE;
void dequeue(QUEUE *qP)
{
    qP->front=qP->front->next;
}
void print_tree(node *root);
void enqueue(QUEUE *qP,node new)
{
    printf("fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
    que_nod *qn_ptr;
    node *temp_nod;
    temp_nod=malloc(sizeof(node));
    qn_ptr=malloc(sizeof(que_nod));
    qn_ptr->bt_node=temp_nod;
    *(qn_ptr->bt_node)=new;
    qn_ptr->next=NULL;
    qP->rear->next=qn_ptr;
    qP->rear=qP->rear->next;
    qP->rear->next=NULL;
    printf("fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
}
create_bt(QUEUE *qP,node *root,int a[],int n)
{
    int i;
    node *ptr,ch_node;
    que_nod *ptr2;
    ptr=malloc(sizeof(node));
    //ptr_ch=malloc(sizeof(node));
    ptr=root;
    printf("in crt\n");
    for(i=1;i<n;i++,ptr=qP->front->bt_node)
    {
        print_tree(root);
        printf("in for\n");
        printf("fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
        ch_node.key=a[i];
        printf("fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
        ch_node.left=ch_node.right=NULL;
        printf("fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
        if( ! (ptr->left) )
            {
                printf("left %d\n",a[i]);
                ptr->left=malloc(sizeof(node));
                *(ptr->left)=ch_node;enqueue(qP,ch_node);
                printf("                   ptrval=%d  ptr left=%d",ptr->key,ptr->left->key);
            }
        else if( !(ptr->right) )
            {
                printf("right %d\n",a[i]);
                printf(" r fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
                ptr->right=malloc(sizeof(node));
                printf("                   ptrval=%d  ptr right=%d",ptr->key,ch_node.key);
                *(ptr->right)=ch_node;
                printf("r2 fr=%d rear=%d\n",qP->front->bt_node->key,qP->rear->bt_node->key);
                enqueue(qP,ch_node);
            }
        else
            {
                printf("dequing\n");
                dequeue(qP);i--;
            }
        for(ptr2=qP->front;ptr2!=NULL;ptr2=ptr2->next)
            printf("  %d\n",ptr2->bt_node->key);
    }
}
void print_tree(node *root)

{
    if(root!=NULL)
    {
        if(root->left==NULL) printf("%d's left is null\n",root->key);
        if(root->right==NULL) printf("%d's right is null\n",root->key);
        print_tree(root->left);
        printf("printing  %d\n",root->key);
        print_tree(root->right);
    }
}
int main()
{
    int n,a[100],i;
    QUEUE *qP;
    que_nod *head_qnod,*ptr;
    qP=malloc(sizeof(QUEUE));
    head_qnod=malloc(sizeof(que_nod));
    node *root;
    root=malloc(sizeof(node));
    qP->front=qP->rear=head_qnod;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    root->key=a[0];
    printf("okay1\n");
    root->left=root->right=NULL;
    printf("okay2\n");
    qP->front->bt_node=root;
    qP->front->next=NULL;
    printf("okay3 %d\n",qP->rear->bt_node->key);
    create_bt(qP,root,a,n);
    printf("aft_crt\n");
    for(ptr=qP->front;ptr!=NULL;ptr=ptr->next)
        printf(" %d ",ptr->bt_node->key);
    print_tree(root);
}
