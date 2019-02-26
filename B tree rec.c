#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;
    struct node *left,*right;
}bt_node;
bt_node** left_rst(bt_node **curr_node)
{
    bt_node **ptr_ptr;
    ptr_ptr=&((*curr_node)->right);
    for(;  (*ptr_ptr)->left!=NULL  ; ptr_ptr=&((*ptr_ptr)->left) );
    return ptr_ptr;
}
int fir_anc(bt_node *root,int num)
{
    printf("first_anc\n");
    bt_node *ptr;
    for(ptr=root;ptr!=NULL;)
    {
        printf("iin for %d\n",ptr->key);
        if(ptr->left->key==num || ptr->right->key==num)
        {
            printf("returned %d\n",ptr->key);
            return ptr->key;
        }
        else if(ptr->key>num) ptr=ptr->left;
        else if(ptr->key<num) ptr=ptr->right;
    }
    return -1;
}
int r_anc(bt_node *root,int num)
{
    printf("right anc\n");
    if(root->key==num) return -1;
    int a=fir_anc(root,num);
    if(a>num) return a;
    r_anc(root,a);
}
bt_node* search(bt_node *root,int num)
{
    printf("search\n");
    if(root==NULL) {printf("returned\n"); return NULL;}
    if(root->key==num) return root;
    if(root->key>num) return (search(root->left,num));
    if(root->key<num) return (search(root->right,num));
}
int find_suc(bt_node *root,int val)
{
    printf("find_suc\n");
    bt_node *ptr;
    ptr=search(root,val);
    if(!ptr) return -1;
    if(ptr->right!=NULL)
    {
        return ( (*(left_rst(&ptr)))->key);
    }
    return r_anc(root,val);
}
void delete(bt_node **cur_root,bt_node **cur_node,int num)
{
    bt_node **ptr_ptr;
    int temp;
    if(cur_root==NULL)
    {
        if( (*cur_node)->key==num )
        {
            if( (*cur_node)->left==NULL && (*cur_node)->right==NULL )
                *cur_node=NULL;
            else if( (*cur_node)->left==NULL )
            {
                *cur_node=(*cur_node)->right;
            }
            else if( (*cur_node)->right==NULL )
            {
                *cur_node=(*cur_node)->left;
            }
            else
            {
                ptr_ptr=left_rst(cur_node);
                temp=(*cur_node)->key;
                (*cur_node)->key=(*ptr_ptr)->key;
                (*ptr_ptr)->key=temp;
                delete(cur_node, &( (*cur_node)->right),temp);
            }
           return;
        }
        else if(num>(*cur_node)->key)
        {
            cur_root=cur_node;
            cur_node=&( (*cur_node)->right);
        }
        else if((*cur_node)->key>num)
        {
            cur_root=cur_node;
            cur_node=&( (*cur_node)->left);
        }
    }
    if( (*cur_node)!=NULL)
    {
        //if( cur_root && (*cur_root)!=NULL )   printf("       %d %d %d\n",(*cur_root)->key,(*cur_node)->key,num);
        if( (*cur_node)->key==num )
        {
            if( (*cur_node)->left==NULL && (*cur_node)->right==NULL )
            {
                (*cur_node)=NULL;
            }
            else if( (*cur_node)->left==NULL )
            {
                //printf("in if\n");
                if( (*cur_root)->left==(*cur_node) )
                {
                    //printf("one\n");
                    (*cur_root)->left=(*cur_node)->right;
                }
                if( (*cur_root)->right==(*cur_node) )
                {
                   // printf("two\n");
                    (*cur_root)->right=(*cur_node)->right;
                }
            }
            else if( (*cur_node)->right==NULL )
            {
                if( (*cur_root)->left==(*cur_node) )
                {
                    (*cur_root)->left=(*cur_node)->left;
                }
                if( (*cur_root)->right==(*cur_node) )
                {
                    (*cur_root)->right=(*cur_node)->left;
                }
            }
            else
            {
                ptr_ptr=left_rst(cur_node);
                temp=(*cur_node)->key;
                (*cur_node)->key=(*ptr_ptr)->key;
                (*ptr_ptr)->key=temp;
                delete(cur_node, &( (*cur_node)->right),temp);
            }
            return;
        }
        if(num>(*cur_node)->key)
        {
            delete(cur_node,  & ( (*cur_node)->right) , num);
            return;
        }
        if((*cur_node)->key>num)
        {
            delete(cur_node,  &( (*cur_node)->left ) , num);
            return;
        }
    }
    return;
}
void print_inor(bt_node *root)
{
    if (root!=NULL)
    {
        print_inor(root->left);
        printf(" %d",root->key);
        print_inor(root->right);
    }
}
void insert(bt_node **curr_node,int val)
{
    if( (*curr_node)!=NULL)
    {
        if(val<(*curr_node)->key)
            insert( &( (*curr_node) ->left) , val);
        if(val>(*curr_node)->key)
            insert(&( (*curr_node)->right),val);
    }
    else if( (*curr_node) == NULL)
    {
        *curr_node=malloc(sizeof(bt_node));
        (*curr_node)->left=(*curr_node)->right=NULL;
         (*curr_node)->key=val;
    }
    return;
}
int main()
{
    int n,i,num,res;
    bt_node *root;
    root=malloc(sizeof(bt_node));
    scanf("%d",&n);
    scanf("%d",&root->key);
    root->left=root->right=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&num);
        insert(&root,num);
    }
    print_inor(root);
    printf("\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        delete(NULL,&root,num);
        //print_inor(root);
        //printf("\n");
    }
    print_inor(root);
    printf("\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        res=find_suc(root,num);
        printf(" %d\n",res);
    }
}
