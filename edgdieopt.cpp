#include<iostream>
#include<cstdlib>
#include<algorithm>
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
    int idx;
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
int ispresent(stedge ed,stedge finaledge[],int m)
{
    int low,high,mid;
    low=0;high=m-1;
    while(low<high)
    {
        mid=(low+high)/2;
        /*if(ed.u==3)
        {cout<<mid<<"\n";}*/
        if(finaledge[mid].u==ed.u && finaledge[mid].v==ed.v)
            return 1;
        else if(finaledge[mid].u<ed.u)
            low=mid+1;
        else if(finaledge[mid].u==ed.u && finaledge[mid].v<ed.v)
            low=mid+1;
        else
            high=mid-1;
    }
    if(finaledge[low].u==ed.u && finaledge[low].v==ed.v)
            return 1;
    return 0;
}
bool sorter(stedge const& lhs, stedge const& rhs) {
    if (lhs.u != rhs.u)
        return lhs.u < rhs.u;
    if (lhs.v != rhs.v)
        return lhs.v < rhs.v;
    return 1;
    //return lhs.AmountDue < rhs.AmountDue;
}
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
    int t,n,m,i,u,v,visited[10005],pie[10005],d[10005],fron,rear,a[10005],cnt_ver_at_d[10005],indeg[10005],j,vertex,edcnt,out[10005];
    ver **edgelist,*temp1,*temp2,*temp,*prev,**ver_at_d;
    stedge edge[10005],finaledge[10005];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ver_at_d=(ver**)malloc(10005*sizeof(ver*));
        for(i=0;i<=10005;i++)
        {
            cnt_ver_at_d[i]=0;
            ver_at_d[i]=NULL;
            indeg[i]=0;
            out[i]=-1;
        }

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
            edge[i].idx=i;
            temp1=(ver *)malloc(sizeof(ver));
            temp1->verno=v;
            temp1->next=edgelist[u];
            edgelist[u]=temp1;

            temp2=(ver *)malloc(sizeof(ver));
            temp2->verno=u;
            temp2->next=edgelist[v];
            edgelist[v]=temp2;
        }
        //cout<<"done"<<endl;
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
        edcnt=0;
        for(i=1;i<=n;i++)
        {
            //cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                if(pie[i]!=temp->verno && pie[temp->verno]!=i &&  temp->verno>i)
                {
                    finaledge[edcnt].u=temp->verno;
                    finaledge[edcnt].v=i;
                    finaledge[edcnt].idx=-1;
                    edcnt++;
                }
              //  cout<<temp->verno<<" ";

            }
        //    cout<<endl;
        }
       // cout<<edcnt<<" m "<<m<<endl;
        for(i=0;i<edcnt;i++)
        {
            //cout<<finaledge[i].u<<" "<<finaledge[i].v<<endl;
            indeg[finaledge[i].v]++;
        }
        //cout<<"done"<<endl;
       /* for(i=1;i<=n;i++)
        {
            cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                cout<<temp->verno<<" ";
            }
            cout<<endl;
        }*/
   /*     for(i=2;i<=n;i++)
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
        }*/
        //cout<<"fefv"<<endl;
       /* for(i=1;i<=n;i++)
        {
            cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                cout<<temp->verno<<" ";
            }
            cout<<endl;
        }*/
      /*  for(i=1;i<=n;i++)
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
        }
        //cout<<"hello"<<endl;
        for(i=1;i<=n;i++)
        {
            //cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                indeg[i]++;
              //  cout<<temp->verno<<" ";
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
        for(depth=n;depth>=1;depth--)
        {
            for(temp=ver_at_d[depth];temp!=NULL;temp=temp->next)
            {
                vertex=temp->verno;
                if(indeg[vertex]%2==1)
                {
                    finaledge[edcnt].u=pie[vertex];
                    finaledge[edcnt].v=vertex;
                    edcnt++;
                    indeg[vertex]++;
                }
                else
                {
                    finaledge[edcnt].u=vertex;
                    finaledge[edcnt].v=pie[vertex];
                    edcnt++;
                    indeg[pie[vertex]]++;
                }
            }
        }
        /*edcnt=0;
        for(i=1;i<=n;i++)
        {
            //cout<<"indeg "<<indeg[i]<<"  ";
            //cout<<i<<" :: ";
            for(temp=edgelist[i];temp!=NULL;temp=temp->next)
            {
                //indeg[i]++;
                finaledge[edcnt].u=temp->verno;
                finaledge[edcnt].v=i;
                finaledge[edcnt].idx=-1;
                edcnt++;
              //  cout<<temp->verno<<" ";

            }*/
        //    cout<<endl;

        /*for(i=0;i<m;i++)
           cout<<"("<<edge[i].u<<","<<edge[i].v<<") ";
        cout<<endl;
        for(i=0;i<m;i++)
           cout<<"("<<finaledge[i].u<<","<<finaledge[i].v<<") ";
        cout<<endl;*/
        sort(edge,edge+m,&sorter);
        sort(finaledge,finaledge+m,&sorter);
        /*for(i=0;i<m;i++)
           cout<<"("<<edge[i].u<<","<<edge[i].v<<") ";
        cout<<endl;
        for(i=0;i<m;i++)
           cout<<"("<<finaledge[i].u<<","<<finaledge[i].v<<") ";
        cout<<endl;
        */
        if(indeg[1]%2==1) cout<<"-1";
        else
        {
            for(i=0;i<m;i++)
            {
                //cout<<edge[i].u<<","<<edge[i].v<<"   ";
                if(ispresent(edge[i],finaledge,m))
                {
                   // cout<<"present\n";
                    out[edge[i].idx]=0;
                }
                else
                {
                    //cout<<"not present\n";
                    out[edge[i].idx]=1;
                }
            }
            //cout<<endl;
            for(i=0;i<m;i++)
            {
                cout<<out[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}


