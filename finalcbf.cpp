#include<iostream>
#include<cstdlib>

using namespace std;
typedef struct cdval
{
      int cval;
      int dval;
}cdval;
struct node
{
      int cnum;
      int dnum;
    long long int rsum;
      int lsum;
    struct node *left, *right;
};
struct node *newNode(  int ckey,  int dkey)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->cnum = ckey;
    temp->dnum = dkey;
    temp->lsum =0;
    temp->rsum =0;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node,   int ckey,  int dkey)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(ckey,dkey);

    /* Otherwise, recur down the tree */
    if (ckey < node->cnum)
    {
        node->lsum+=dkey;
        node->left  = insert(node->left, ckey,dkey);
    }
    else if (ckey > node->cnum)
    {
        node->rsum+=dkey;
        node->right = insert(node->right, ckey,dkey);
    }
    else if(ckey == node->cnum)
    {
        node->dnum+=dkey;
    }
    /* return the (unchanged) node pointer */
    return node;
}
  int maxSubArraySum(int a[], int size)
{
    int max_so_far = -99999999, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->cnum<<","<<root->dnum<<"   ";
        inorder(root->right);
    }
}
  int getcnt(struct node *root,  int lval,  int rval)
{
    int cnt=0;
    struct node* arr[10000];
    struct node *node;
    //cout<<"getcnt\n"<<root;

    for(node=root;node!=NULL;)
    {
        arr[cnt]=node;
      //  cout<<"node "<<node->cnum;
        cnt++;
        if(node->cnum==lval)
        {
            break;
        }
        else if(node->cnum>lval)
        {
            node=node->left;
        }
        else if(node->cnum<lval)
        {
            node=node->right;
        }
    }
    //cout<<"searchrd\n"<<cnt<<endl;
    int i;
    for(i=cnt-1;i>=0;i--)
    {
      //  cout<<i<<" "<<arr[i]->cnum<<endl;
        if(arr[i]->cnum>=lval)
            break;
    }
    //cout<<i<<"lb\n";
    //cout<<arr[i]<<endl;
      int sum1;
    if(i>=0) {sum1=(arr[i]->dnum+arr[i]->rsum);}
    else sum1=0;
    //i--;
   // cout<<"fckkhtcl"<<endl;
   /* for(;i>0;i--)
    {
        cout<<arr[i]<<arr[i]->left<<endl;
    }*/
    for(;i>0;i--)
    {
        if(arr[i-1]->left==arr[i])
            sum1+=(arr[i-1]->dnum+arr[i-1]->rsum);
    }
    //cout<<"sum1="<<sum1<<"\n";
    cnt=0;
    for(node=root;node!=NULL;)
    {
        arr[cnt]=node;
        cnt++;
        if(node->cnum==rval)
        {
            break;
        }
        else if(node->cnum>rval)
        {
            node=node->left;
        }
        else if(node->cnum<rval)
        {
            node=node->right;
        }
    }
    for(i=cnt-1;i>=0;i--)
    {
        if(arr[i]->cnum<=rval)
            break;
    }
      int sum2;
    if(i>=0)
        sum2=(arr[i]->dnum+arr[i]->lsum);
    else sum2=0;
    //i--;
    for(;i>0;i--)
    {
        if(arr[i-1]->right==arr[i])
            sum2+=(arr[i-1]->dnum+arr[i-1]->lsum);
    }
    //cout<<"sum2="<<sum2<<endl;
    return (sum1+sum2);
}
int main()
{
      int k,b[2002],c[2002],d[2002],xor1,allpos,procarr[2002];
    cdval arr[2002];
    int i,j,fron,rear,fronadds,q;
    cin>>q>>k;
    allpos=1;
    for(i=0;i<q;i++)
    {
        cin>>b[i]>>c[i];
        if(b[i]==2 || b[i]==1)
        {
            cin>>d[i];
            if(d[i]<0)
            {
                allpos=0;
            }
        }
        else
            d[i]=-1;
    }
    if(q<20001)
    {
        fronadds=0;
        for(i=0;i<q;i++)
        {
            if(b[i]==1)
            {
                fronadds++;
            }
        }
    //cout<<fronadds<<endl;
        int ans=0;
        int xor1=0;
        for(fron=fronadds+1,rear=fronadds+1,i=0;i<q;i++)
        {
        //cout<<"strart  "<<fron<<"        "<<rear<<endl;
        /*for(int i=fron;i<rear;i++)
        {
            cout<<arr[i].cval<<"  "<<arr[i].dval<<endl;
        }*/
            xor1=ans;
        //cout<<"xor  "<<xor1<<endl;
            if(b[i]==1)
            {
                fron--;
                arr[fron].cval=(c[i]^xor1);
            //cout<<"calc xor  "<<c[i]<<"   "<<xor1<<"   "<<(c[i]^xor1)<<endl;
                arr[fron].dval=d[i];
            }
            if(b[i]==2)
            {
                arr[rear].cval=(c[i]^xor1);
                arr[rear].dval=d[i];
                rear++;
            }
            if(b[i]==3)
            {
            //cout<<fron<<"        "<<rear<<endl<<"arr[]i  \n";
            /*for(int i=fron;i<rear;i++)
            {
                cout<<arr[i].cval<<"  "<<arr[i].dval<<endl;
            }
            cout<<endl;*/
                int m;
                for(j=fron,m=0;j<rear;j++,m++)
                {
                //cout<<arr[j].cval<<" "<<(c[i]^xor1)-k<<"-"<<(c[i]^xor1)+k<<endl;
                    if(arr[j].cval>=(c[i]^xor1)-k && arr[j].cval<=(c[i]^xor1)+k)
                        procarr[m]=arr[j].dval;
                    else
                        procarr[m]=0;
                }
                int l;
            //cout<<"procar  ";
           /* for(l=0;l<m;l++)
                cout<<procarr[l]<<" ";
            cout<<endl<<endl;*/
                ans=maxSubArraySum(procarr,m);
                cout<<ans<<endl;

            }
        }

    }
    else
    {
      //  cout<<"inelse\n"<<endl;
          int totsum=0;
        xor1=0;
        struct node *root = NULL;
        for(i=0;i<q;i++)
        {
        //    cout<<"i="<<i<<endl;
            if(b[i]!=3)
            {
                root=insert(root,(c[i]^xor1),d[i]);
          //      inorder(root);
            //    cout<<endl;
                totsum+=d[i];
            }
            else
            {
              //  cout<<(c[i]^xor1)-k<<"  "<<(c[i]^xor1)+k<<"  "<<totsum<<endl;
                xor1=getcnt(root,(c[i]^xor1)-k,(c[i]^xor1)+k)-totsum;
                cout<<xor1<<endl;
            }
        }
    }
}
