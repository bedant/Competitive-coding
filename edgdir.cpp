#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct ver
{
    //int u;
    int verno;
    struct ver *next;
}ver;
typedef struct edge
{
    int u;
    int v;
}stedge;
/*void bfs(ver **edgelist,int *pie,int *visited,int *d,int parent)
{
    ver * temp;
    if(parent==0)
    {
        visited[1]=1;
        pie[1]=0;
        d[1]=0;
        enq(1);
    }
    for()


    }
}*/
ver* add(ver *ptr,int vertno)
{
    ver *temp2;
    temp2=(ver *)malloc(sizeof(ver));
    temp2->verno=vertno;
    temp2->next=ptr;
    return temp2;
}
int main()
{
    int t,n,m,i,u,v,visited[100005],pie[100005],d[100005],fron,rear,a[100005],cnt_ver_at_d[100005],indeg[100005],j,vertex;
    ver **edgelist,*temp1,*temp2,*temp,*prev,**ver_at_d;
    stedge edge[100005];
    cin>>t;
    while(t--)
    {
        for(i=0;i<100001;i++)
            cnt_ver_at_d[i]=0;
        ver_at_d=(ver**)malloc(100005*sizeof(ver*));
        for(i=0;i<100001;i++)
        {
            cnt_ver_at_d[i]=0;
            ver_at_d[i]=NULL;
            indeg[i]=0;
        }
        cin>>n>>m;
        edgelist=(ver **)malloc((n+1)*sizeof(ver*));
        for(i=1;i<=n;i++)
        {
            //edgelist=(ver *)malloc()
            edgelist[i]=NULL;
            visited[i]=0;
            pie[i]=0;
        }
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            edge[i].u=u;
            edge[i].v=v;
            temp1=(ver *)malloc(sizeof(ver));
            temp1->verno=v;
            temp1->next=edgelist[u];
            edgelist[u]=temp1;

            temp2=(ver *)malloc(sizeof(ver));
            temp2->verno=u;
            temp2->next=edgelist[v];
            edgelist[v]=temp2;
        }
        //bfs(edgelist,pie,visited,d,NULL);
        fron=0;rear=0;
        a[rear]=1;rear++;
        visited[1]=1;
        pie[1]=0;
        d[1]=0;

        while(rear>fron)
        {
            i=a[fron];
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                if(visited[temp->verno]==0)
                {
                    visited[temp->verno]=1;
                    d[temp->verno]=d[i]+1;
                    pie[temp->verno]=i;
                    a[rear]=temp->verno;
                    rear++;
                }
            }
            fron++;
        }

       /* for(i=1;i<=n;i++)
        {
            cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                cout<<temp->verno<<" ";
            }
            cout<<endl;
        }*/
        for(i=2;i<=n;i++)
        {
           // cout<<i<<" "<<pie[i]<<endl;
            if(edgelist[i]->verno==pie[i]) edgelist[i]=edgelist[i]->next;
            else
            {
                for(prev=edgelist[i],temp=edgelist[i]->next;temp!=NULL;prev=temp,temp=temp->next)
                {
                    //cout<<"loop";
                    if(temp->verno==pie[i])
                    {
                        prev->next=temp->next;
                        break;
                    }
                }
            }
            //cout<<"here"<<endl;
            j=pie[i];
            if(edgelist[j]->verno==i) edgelist[j]=edgelist[j]->next;
            else
            {
                for(prev=edgelist[j],temp=edgelist[j]->next;temp!=NULL;prev=temp,temp=temp->next)
                {
                    //cout<<"loop";
                    if(temp->verno==i)
                    {
                        prev->next=temp->next;
                        break;
                    }
                }
            }
        }
       // cout<<"fefv"<<endl;
       /* for(i=1;i<=n;i++)
        {
            cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                cout<<temp->verno<<" ";
            }
            cout<<endl;
        }*/
        /*for(i=1;i<=n;i++)
        {
            while(edgelist[i]!=NULL && edgelist[i]->verno>i)
                edgelist[i]=edgelist[i]->next;
            if(edgelist[i]!=NULL)
            {
                for(prev=edgelist[i],temp=edgelist[i]->next;temp!=NULL;prev=temp,temp=temp->next)
                {
                    if(temp->verno>i)
                    {
                        prev->next=temp->next;
                        temp=prev;
                    }
                }
            }
        }*/
        //cout<<"hello"<<endl;
        /*for(i=1;i<=n;i++)
        {
            //cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                indeg[i]++;
                //cout<<temp->verno<<" ";
            }
            //cout<<endl;
        }*/
        for(i=1;i<=n;i++)
        {
            ver_at_d[d[i]]=add(ver_at_d[d[i]],i);
            cnt_ver_at_d[d[i]]++;
        }
        //cout<<"okay"<<endl;
        int depth;
        /*for(depth=100000;depth>=1;depth--)
        {
            for(temp=ver_at_d[depth];temp!=NULL;temp=temp->next)
            {
                vertex=temp->verno;
                if(indeg[vertex]%2==1)
                {
                    temp1=(ver *)malloc(sizeof(ver));
                    temp1->verno=pie[vertex];
                    temp1->next=edgelist[vertex];
                    edgelist[vertex]=temp1;
                    indeg[vertex]++;
                }
                else
                {
                    temp1=(ver *)malloc(sizeof(ver));
                    temp1->verno=vertex;
                    temp1->next=edgelist[pie[vertex]];
                    edgelist[pie[vertex]]=temp1;
                    indeg[pie[vertex]]++;
                }
            }
        }*/
       /* for(i=1;i<=n;i++)
        {
            cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                //indeg[i]++;
                cout<<temp->verno<<" ";
            }
            cout<<endl;
        }*/
        cout<<"-1";

        cout<<endl;
    }
    return 0;
}


