#include<stdio.h>
int minm(int a,int b)
{
    if(a<b) return a;
    return b;
}
int prev(int p_sort[][100],int p[][100],int d[][100],int i,int *ind,int m)
{
    int j;
    int min=p[i][0],jvar=*ind;
    for(i=j;j<m;j++)
    {
        if(p[i][j]<min)
        {
            min=p[i][j];
            *ind=j;
        }
    }
    if( p_sort[i-1][0]+p[i][jvar] > p[i-1][jvar]+p[i][jvar]-minm(d[i-1][jvar],p[i][jvar]) )
        {
            *ind=jvar;
            return p[i-1][jvar]-minm(d[i-1][jvar],p[i][jvar]);
        }
    else return p_sort[i-1][0];
}
int next(int p_sort[][100],int p[][100],int d[][100],int i,int *ind,int m)
{
    int max=p[i][0],jvar=*ind,j;
    for(i=j;j<m;j++)
    {
        if(p[i][j]>max)
        {
            max=p[i][j];
            *ind=j;
        }
    }
    if( p_sort[i+1][0]+p[i][jvar] > p[i][jvar]+p[i+1][jvar]-min(d[i][jvar],p[i+1][jvar]) )
        {
            *ind=jvar;
            return p[i+1][jvar]-min(d[i][jvar],p[i+1][jvar]);
        }
    else return p_sort[i+1][0];
}
//int m,n;
int find_min(int p[][100],int p_sort[][100],int d[][100],int m,int l,int h)
{
    int i,mid,minm2,pr2,ret1,posm,res,ind,ret2;
    if(l==h) return p_sort[l][0];
    if(l<h)
    {
        ret1=find_min(p,p_sort,d,m,l,(l+h)/2)+find_min(p,p_sort,d,m,(l+h)/2+1,h);
        mid=(l+h)/2;minm2=99999999;
        for(i=0;i<m;i++)
        {
            pr2=p[mid][i]+p[mid+1][i]-min(p[mid+1][i],d[mid][i]);
            if(pr2<minm2)
            {
                minm2=pr2;
                posm=m;
            }
        }
        res=minm2;
        ind = posm;
        for(i=mid;i>l;i--)
            res+=prev(p_sort,p,d,i,&ind,m);
        ind=posm;
        for(i=mid+1;i<h;i++)
            res+=next(p_sort,p,d,i,&ind,m);
        ret2=res;
    }
    return(min(ret1,ret2));
}

int main()
{
    int t,n,i,p[100][100],p_sort[100][100],j,d[100][100],m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&p[i][j]);
                p_sort[i][j]=p[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            mergeSort(p_sort[i],0,m-1);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&d[i][j]);
            }
        }
        find_min(p,p_sort,d,m,0,n);
    }
}
