#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    char color;
    struct node *left,*right,*parent;
}node;
void left_rot(node **root,node *cur)
{
    node *temp;
    temp=cur->right;
    temp->left=cur->right;
    cur->right->parent=cur;
    if(cur->parent==NULL)
        *root=temp;
    else if(cur==cur->parent->left)
        cur->parent->left=temp;
    else if(cur==cur->parent->right)
        cur->parent->right=temp;
    temp->parent=cur->parent;
    temp->right=cur;
    cur->parent=temp;

    //cur=cur->left;
}
void right_rot(node *par,node *cur)
{
    node *tr2;
    tr2=cur->right;
    cur->parent->parent->right=cur;
    cur->right=cur->parent;
    cur->parent=cur->parent->parent;
    cur->right->parent=cur;
    cur->right->left=tr2;
    tr2->parent=cur->right;
    //cur=cur->right;
}

void satis(node *root,node *cur)
{
  while(cur!=root && cur->parent->color=='r' && cur->color=='r')
  {
      gp=cur->parent->parent;
      par=cur->parent;
      if(cur->parent==cur->parent->parent->left)
      {
        unc=cur->parent->parent->right;
        if(unc->color=='r')
            cur=gp;
        else if(unc->color=='b')
        {
            if(cur==cur->parent->right)
            {
                left_rot(root,cur->parent);
                cur=cur->left;
            }
            right_rot(root,cur->parent->parent);
            t_col=cur->parent->color;
            cur->parent->color=cur->parent->parent->color;
            cur->parent->parent->color=t_col;
        }
        root->color=black;
      }
      if(cur->parent==cur->parent->parent->right)
      {
        unc=cur->parent->parent->left;
        if(unc->color=='r')
            cur=gp;
        else if(unc->color=='b')
        {
            if(cur==cur->parent->left)
            {
                right_rot(root,cur->parent);
                cur=cur->right;
            }
            left_rot(root,cur->parent->parent);
            t_col=par->color;
            par->color=gp->color;
            gp->color=t_col;
        }
      }
    }
}
void insert(node *root,int val)
{
    node *cur;
    cur=root;
    while(1)
    {
        if(cur->data>val)
        {
            if(cur->left) cur=cur->left;
            else
            {
                cur->left=malloc(sizeof(node));
                cur->left->data=val;
                cur->left->color='r';
                if(cur!=root && cur==cur->parent->left)
                {
                    cur->left->uncle=cur->parent->right;
                }
                else if(cur!=root && cur==cur->parent->right)
                {
                    cur->left->uncle=cur->parent->left;
                }
                //cur->left->uncle=cur->parent->;
                cur->left->left=cur->left->right=NULL;
                cur->left->parent=cur;
                cur=cur->left;
                break;
            }
        }
        else if(cur->data<val)
        {
            if(cur->right) cur=cur->right;
            else
            {
                cur->right=malloc(sizeof(node));
                cur->right->data=val;
                cur->right->color='r';
                if(cur==cur->parent->left)
                {
                    cur->right->uncle=cur->parent->right;
                }
                else if(cur==cur->parent->right)
                {
                    cur->right->uncle=cur->parent->left;
                }
                cur->right->left=cur->left->right=NULL;
                cur->right->parent=cur;
                cur=cur->right;
                break;
            }
        }
    }
        satis(root,cur);
}
int main()
{
    int n,i,a;
    node *root;
    scanf("%d",&a);
    root=malloc(sizeof(node));
    root->data=a;
    root->left=root->right=root->parent=root->uncle=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        insert(root,a);
    }
}
