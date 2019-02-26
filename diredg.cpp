#include<iostream>
using namespace std;
typedef struct neig
{
    int verno;
    struct neig *next;
}neigh;
int  main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>a[i].u>>a[i].v;
            temp=a[i].v;
            temp->next=listofv[a[i].u]
            listofv[a[i].u]=temp;
            temp=a[i].u;
            temp->next=listofv[a[i].v]
            listofv[a[i].v]=temp;

        }
        for(i=0;i<m;i++)
        {
            cnt[a[i].u]++;
            cnt[a[i].v]++;
        }
        for(j=1;j<n;j++)
        {
            if(cnt[j]==1)
            cnt[j]=0;
            i=listofv[j].verno;
            if(listofv[i].verno==j)
                listofv[i]=listofv[i]->next;
            else
            {
                prev=NULL;
                temp=listofv[i];
                for(;temp!=NULL;prev=temp,temp=temp->next)
                {
                    if(temp.verno==j)
                    {
                        prev->next=temp->next;
                        break;
                    }
                }
            }
        }
        while(1)
        {

        }
    }
}
