#include<stdio.h>
#include<stdlib.h>
int fir_anc(bt_node *root,int num)
{
    bt_node *ptr;
    for(ptr=root;ptr!=NULL;)
    {
        if(ptr->left->key==num || ptr->right->key==num)
            return ptr->key;
        if(ptr->key>num) ptr=ptr->left;
        if(ptr->key<num) ptr=ptr->right;
    }
    return -1;
}
int r_anc(bt_node *root,int num)
{
    if(root->key==num) return NULL;
    int a=fir_anc(root,num);
    if(a>num) return a;
    r_anc(root,a);
}
bt_node* search(bt_node *root,int num)
{
    if(root->key==num) return root;
    if(root->key>num) return (search(root->left,num));
    if(root->key<num) return (search(root->right,num));
}
int find_suc(bt_node *root,int val)
{
    bt_node *ptr;
    ptr=search(root,val);
    if(ptr->right!=NULL)
    {
        return (*(left_rst(&ptr))->key);
    }
    return r_anc(root,val);
}
