//Bedant Agarwal 17CS10008
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int value;
struct node *left;
struct node *right;
struct node *parent;
}
node, *NODEPTR;
NODEPTR makeRoot(NODEPTR root, NODEPTR N)
{
  // printf("in make\n");
  // printf("ok\n");
   node *temp;
  if(N==N->parent->right)
    {
      //  printf("in make1\n");
      temp=N->left;
      N->left=N->parent;
      N->left->right=temp;
      if(temp)
	temp->parent=N->left;
      N->left->parent=N;
      N->parent=NULL;
      return N;
    }
   if(N==N->parent->left)
    {
      //  printf("in make2\n");
      temp=N->right;
      N->right=N->parent;
      N->right->left=temp;
      if(temp)
	temp->parent=N->left;
      N->right->parent=N;
      N->parent=NULL;
      return N;
    }
}
NODEPTR sameOrientation(NODEPTR root, NODEPTR N)
{
  // printf("in same\n");
  node *cur,*temp;
  cur=N->parent;
  if(N==N->parent->left)
    {
      // printf("in same 1\n");
      temp=cur->right;
      cur->right=cur->parent;
      cur->right->left=temp;
      if(temp)
	temp->parent=cur->right;
      if(cur->right->parent==NULL)
	root=cur;
      else if(cur->right==cur->right->parent->left)
	 cur->right->parent->left=cur;
      else if(cur->right==cur->right->parent->right)
	 cur->right->parent->right=cur;
      cur->parent=cur->right->parent;
      cur->right->parent=cur;
      if(cur==root) makeRoot(root,N);
      else
	{
	  cur=N;
	  temp=cur->right;
	  cur->right=cur->parent;
	  cur->right->left=temp;
	  if(temp)
	    temp->parent=N->right;
	  if(cur->right->parent==NULL)
	    root=cur;
	  else if(cur->right==cur->right->parent->left)
	    cur->right->parent->left=cur;
	  else if(cur->right==cur->right->parent->right)
	    cur->right->parent->right=cur;
	  cur->parent=cur->right->parent;
	  cur->right->parent=cur;
	}
    }
  else  if(N==N->parent->right)
    {
      //  printf("in same2\n");
      temp=cur->left;
      cur->left=cur->parent;
      cur->left->right=temp;
      if(temp)
	temp->parent=cur->left;
      if(cur->left->parent==NULL)
	root=cur;
      else if(cur->left==cur->left->parent->left)
	 cur->left->parent->left=cur;
      else if(cur->left==cur->left->parent->right)
	 cur->left->parent->right=cur;
      cur->parent=cur->left->parent;
      cur->left->parent=cur;
      if(cur==root) makeRoot(root,N);
      else
	{
	  cur=N;
	   temp=cur->left;
	   cur->left=cur->parent;
	   cur->left->right=temp;
	   if(temp)
	     temp->parent=cur->left;
	   if(cur->left->parent==NULL)
	     root=cur;
	   else if(cur->left==cur->left->parent->left)
	     cur->left->parent->left=cur;
	   else if(cur->left==cur->left->parent->right)
	     cur->left->parent->right=cur;
	   cur->parent=cur->left->parent;
	   cur->left->parent=cur;
	}
    }
  return root;
}

NODEPTR oppositeOrientation(NODEPTR root, NODEPTR N)
{
  // printf("in opp\n");
  node *temp;
  if(N==N->parent->right)
    {
      // printf("in opp 1\n");
      temp=N->left;
      N->parent->right=temp;
      N->left=N->parent;
      N->parent=N->parent->parent;
      N->left->parent=N;
      if(temp)
	temp->parent=N->left;
      N->parent->left=N;
      if(N->parent==root)
	makeRoot(root,N);
      else
	{
	  temp=N->right;
	  N->parent->left=temp;
	  if(temp)
	    temp->parent=N->parent;
	  N->right=N->parent;
	  if(N->parent==root)
	    root=N;
	  else  if(N->parent==N->parent->parent->right)
	    N->parent->parent->right=N;
	  else  if(N->parent==N->parent->parent->left)
	    N->parent->parent->left=N;
	  N->parent=N->right->parent;
	  N->right->parent=N;
	}
    }
  else if(N==N->parent->left)
    {
      // printf("in opp2\n");
      temp=N->right;
      N->parent->left=temp;
      N->right=N->parent;
      N->parent=N->parent->parent;
      N->right->parent=N;
      if(temp)
	temp->parent=N->right;
      N->parent->right=N;
      if(N->parent==root)
	root=makeRoot(root,N);
      else
	{
	  temp=N->left;
	  N->parent->right=temp;
	  if(temp)
	    temp->parent=N->parent;
	  N->left=N->parent;
	  if(N->parent==root)
	    root=N;
	  else  if(N->parent==N->parent->parent->left)
	    N->parent->parent->left=N;
	  else  if(N->parent==N->parent->parent->right)
	    N->parent->parent->right=N;
	  N->parent=N->left->parent;
	  N->left->parent=N;
	}
    }
  return root;
}
node *insert(node *root,int key)
{
  if(root==NULL)
    {
      root=(node *)malloc(sizeof(node));
      root->parent=root->left=root->right=NULL;
      root->value=key;
      return root;
    }
  if(key<root->value)
    {
      root->left=insert(root->left,key);
      root->left->parent=root;
    }
  else if(key>root->value)
    {
      root->right=insert(root->right,key);
      root->right->parent=root;
    }

   return root;
}

void preorder(node *root)
{
  if(root!=NULL)
    {
      printf("%d  ",root->value);
      preorder(root->left);
      preorder(root->right);
    }
}
void inorder(node *root)
{
  if(root!=NULL)
    {
      inorder(root->left);
      printf("%d   ",root->value);
      inorder(root->right);
    }
}
node * lift(node *root,int val)
{
  node *x;
  x=root;
  while(x!=NULL)
    {
      if(x->value>val)
	x=x->left;
      if(x->value<val)
	x=x->right;
      if(x->value==val)
	break;
    }
  while(x->parent!=NULL)
    {
      if(x->parent->parent==NULL)
	root=makeRoot(root,x);
      else if( (x->parent==x->parent->parent->left && x==x->parent->left ) ||(x->parent==x->parent->parent->right && x==x->parent->right) )
	root=sameOrientation(root,x);
      else if((x->parent==x->parent->parent->left && x==x->parent->right ) ||(x->parent==x->parent->parent->right && x==x->parent->left) )
	      root= oppositeOrientation(root,x);
    }
  return x;
}
node* minValueNode(node* node)
{
  NODEPTR curren;
  curren= node;
    while (curren->left != NULL)
        curren = curren->left;

    return curren;
}
NODEPTR delete(NODEPTR root, int key)
{
  node *par,*x;

  printf("in del %d\n",key);
    if (root == NULL) return root;

     if (key < root->value)
        root->left = delete(root->left, key);

     else if (key > root->value)
        root->right = delete(root->right, key);

     else
    {
         if (root->left == NULL)
        {
            struct node *temp = root->right;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            return temp;
        }
        struct node* temp = minValueNode(root->right);

         root->value = temp->value;

         root->right = delete(root->right, temp->value);
    }
    return root;
}
int main()
{
  int num,i,val,ke;
  node *root,*x;
  root=NULL;
  printf("enter the no. of numbers: ");
  scanf("%d",&num);
  for(i=0;i<num;i++)
    {
      scanf("%d",&val);
      root= insert(root,val);
      // preorder(root);
      // printf("\n");
      // inorder(root);
       //printf("aft ins\n");
     root= lift(root,val);
      preorder(root);
      printf("\n");
     // inorder(root);
    }
  printf("preorder :");
   preorder(root);
  printf("\n");
  printf("inorder :");
   inorder(root);
     printf("\n");
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
  scanf("%d",&ke);
  x=root;
  while(x!=NULL)
     {
      if(x->value>ke)
	x=x->left;
      if(x->value<ke)
	x=x->right;
      if(x->value==ke)
	break;
    }
  printf("out\n");
  val=x->parent->value;
  printf("out\n");
  root=delete(root,ke);
  printf("out\n");
  root= lift(root,val);
  printf("preorder :");
  preorder(root);
  printf("\n");
  printf("inorder :");
  inorder(root);
  }
}
