#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct vertex
{
    int id;
    int outdeg;
    int parno;
}vertex;
typedef struct ver
{
    //int u;
    int verno;
    struct ver *next;
}ver;
void siftd(vertex vertarr[],int add_ver[],int i,int n)
{
    vertex temp;
    int j,tempint;
    for(;i<=n/2;)
    {
        if(2*i+1<=n && vertarr[2*i+1].outdeg<vertarr[2*i].outdeg && vertarr[2*i+1].outdeg<vertarr[i].outdeg)
        {
            temp=vertarr[2*i+1];
            vertarr[2*i+1]=vertarr[i];
            vertarr[i]=temp;

            tempint=add_ver[vertarr[2*i+1].id];
            add_ver[vertarr[2*i+1].id]=add_ver[vertarr[i].id];
            add_ver[vertarr[i].id]=tempint;

            i=2*i+1;
            /*for(j=1;j<=n;j++)
                cout<<"("<<vertarr[j].id<<" "<<vertarr[j].outdeg<<")"<<"   ";*/
        }
        else if(vertarr[2*i].outdeg<vertarr[i].outdeg)
        {
            temp=vertarr[2*i];
            vertarr[2*i]=vertarr[i];
            vertarr[i]=temp;

            tempint=add_ver[vertarr[2*i].id];
            add_ver[vertarr[2*i].id]=add_ver[vertarr[i].id];
            add_ver[vertarr[i].id]=tempint;

            i=2*i;
            /*for(j=1;j<=n;j++)
                cout<<"("<<vertarr[j].id<<" "<<vertarr[j].outdeg<<")"<<"   ";*/
        }
        else if(2*i+1<=n && vertarr[2*i+1].outdeg==vertarr[2*i].outdeg && vertarr[2*i+1].outdeg==vertarr[i].outdeg)
        {
            if(vertarr[2*i+1].parno>=vertarr[2*i].parno && vertarr[2*i+1].parno>vertarr[i].parno)
            {
                temp=vertarr[2*i+1];
                vertarr[2*i+1]=vertarr[i];
                vertarr[i]=temp;

                tempint=add_ver[vertarr[2*i+1].id];
                add_ver[vertarr[2*i+1].id]=add_ver[vertarr[i].id];
                add_ver[vertarr[i].id]=tempint;

                i=2*i+1;
            }
            else if(vertarr[2*i].parno>=vertarr[2*i+1].parno && vertarr[2*i].parno>vertarr[i].parno)
            {
                temp=vertarr[2*i];
                vertarr[2*i]=vertarr[i];
                vertarr[i]=temp;

                tempint=add_ver[vertarr[2*i].id];
                add_ver[vertarr[2*i].id]=add_ver[vertarr[i].id];
                add_ver[vertarr[i].id]=tempint;

                i=2*i;
            }
        }
        else if(2*i+1<=n && vertarr[2*i+1].outdeg==vertarr[i].outdeg)
        {
            if(vertarr[2*i+1].parno>=vertarr[i].parno);
            {
                temp=vertarr[2*i+1];
                vertarr[2*i+1]=vertarr[i];
                vertarr[i]=temp;

                tempint=add_ver[vertarr[2*i+1].id];
                add_ver[vertarr[2*i+1].id]=add_ver[vertarr[i].id];
                add_ver[vertarr[i].id]=tempint;

                i=2*i+1;
            }
        }
        else if( vertarr[2*i].outdeg==vertarr[i].outdeg)
        {
            if(vertarr[2*i].parno>=vertarr[i].parno);
            {
                temp=vertarr[2*i];
                vertarr[2*i]=vertarr[i];
                vertarr[i]=temp;

                tempint=add_ver[vertarr[2*i].id];
                add_ver[vertarr[2*i].id]=add_ver[vertarr[i].id];
                add_ver[vertarr[i].id]=tempint;

                i=2*i;
            }
        }
        else return;
    }
    return;
}
int siftup(vertex vertarr[],int add_ver[],int i,int n)
{
    int tempint;
    vertex temp;
    for(;i>1;)
    {
        //cout<<i<<"siftu "<<vertarr[i].id<<" "<<vertarr[i/2].id<<endl;
        if(vertarr[i].outdeg<vertarr[i/2].outdeg || (vertarr[i].outdeg==vertarr[i/2].outdeg && vertarr[i].parno>vertarr[i/2].parno))
        {
          //  cout<<i<<"siftu if "<<vertarr[i].id<<" "<<vertarr[i/2].id<<endl;
            temp=vertarr[i/2];
            vertarr[i/2]=vertarr[i];
            vertarr[i]=temp;

            tempint=add_ver[vertarr[i/2].id];
            add_ver[vertarr[i/2].id]=add_ver[vertarr[i].id];
            add_ver[vertarr[i].id]=tempint;

            i=i/2;
        }
        else return i;
    }
    return i;
}
void buildheap(vertex vertarr[],int add_ver[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
        siftd(vertarr,add_ver,i,n);
}
vertex extractmin(vertex vertarr[],int add_ver[],int n)
{
    int i;
    /*for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
    vertex temp=vertarr[1];
    vertarr[1]=vertarr[n];
    add_ver[vertarr[1].id]=1;
    /*cout<<"emin\n";
    for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
    siftd(vertarr,add_ver,1,n-1);
    return temp;
}
int main()
{
    int n,m,i,u,v,add_vert[10006],outline=0,cnt,num[10006];
    vertex vertarr[10006],a,b,aval[10006],bval[10006];
    ver *temp1,**parlist,*temp;
    cin>>n>>m;
    parlist=(ver **)malloc((n+1)*sizeof(ver *));
    for(i=0;i<=n;i++)
    {
        parlist[i]=NULL;
    }
    for(i=1;i<=n;i++)
    {
        vertarr[i].id=i;
        vertarr[i].outdeg=0;
        vertarr[i].parno=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        temp1=(ver *)malloc(sizeof(ver));
        temp1->verno=u;
        temp1->next=parlist[v];
        parlist[v]=temp1;
        vertarr[u].parno++;
        vertarr[u].outdeg++;
    }
   /* for(i=1;i<=n;i++)
    {
        cout<<i<<":: ";
        for(temp=parlist[i];temp!=NULL;temp=temp->next)
        {
            cout<<temp->verno<<"  ";
        }
        cout<<endl;
    }*/
    buildheap(vertarr,add_vert,n);
    /*for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
    for(i=0;i<=n;i++)
    {
        add_vert[vertarr[i].id]=i;
    }
   /* for(i=1;i<=n;i++)
    {
        cout<<i<<" "<<add_vert[i]<<"    ";
    }*/
    outline=0;
    while(n>0)
    {
        cnt=0;
        //cout<<"herhe"<<endl;
        /*for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
        a=extractmin(vertarr,add_vert,n);
        //cout<<"\n"<<a.id<<" a  \n";
        n--;cnt++;
        /*for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
        if(n>0)
        {
            b=vertarr[1];
            if(b.outdeg==0)
            {
                extractmin(vertarr,add_vert,n);
                //cout<<"\n"<<b.id<<" b  \n";
                n--;cnt++;
               /* for(i=1;i<=n;i++)
                    cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
                for(temp=parlist[b.id];temp!=NULL;temp=temp->next)
                {
                    vertarr[add_vert[temp->verno]].outdeg--;
                    add_vert[temp->verno]=siftup(vertarr,add_vert,add_vert[temp->verno],n);
                }
            }
        }
        num[outline]=cnt;
        aval[outline]=a;
        bval[outline]=b;
        for(temp=parlist[a.id];temp!=NULL;temp=temp->next)
        {
            vertarr[add_vert[temp->verno]].outdeg--;
            add_vert[temp->verno]=siftup(vertarr,add_vert,add_vert[temp->verno],n);
        }
        //cout<<endl;
        /*for(i=1;i<=n;i++)
        cout<<"("<<vertarr[i].id<<" "<<vertarr[i].outdeg<<")"<<"   ";*/
        outline++;
    }
    cout<<outline<<endl;
    for(i=0;i<outline;i++)
    {
        if(num[i]==1)
            cout<<num[i]<<" "<<aval[i].id<<endl;
        if(num[i]==2)
            cout<<num[i]<<" "<<aval[i].id<<" "<<bval[i].id<<endl;
    }

}
