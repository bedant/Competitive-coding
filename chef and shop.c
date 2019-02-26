#include<stdio.h>
struct nod
{
    int c,wt;
    //float eff_c;
};
typedef struct nod nod;

int main()
{
    int n,i,wt,t,w,k,dec,j,a[1024][10],tot_wt,max_wt,av_cos;
    nod node[11];
    scanf("%d",&t);
    for(w=0;w<t;w++)
    {
        wt=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++) scanf("%d%d",&node[i].c,&node[i].wt);
        //for(i=0;i<n;i++) node[i].eff_c=node[i].c/(1.0*node[i].wt);
        for(i=0;i<pow(2,n);i++)
        {
            dec=i;
            for(j=0;j<=9;j++)
            {
                a[i][j]=dec%2;
                dec/=2;
            }
        }
        max_wt=0;
        for(i=0;i<pow(2,n);i++)
        {
            av_cos=k;
            tot_wt=0;
            for(j=0;j<=9;j++)
            {
                if(a[i][j]==1) {av_cos-=node[j].c;tot_wt+=node[j].wt;}
            }
            if(av_cos>=0 && tot_wt>max_wt) max_wt=tot_wt;
        }
            printf("%d\n",max_wt);
    }
    return 0;
}
