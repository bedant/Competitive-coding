
#include<stdio.h>
//using namespace std;
int main()
{
    int t,cnt,n,i,quo,th_f,o_tw_th,o_tw_f,th_f_fv,th_f_sx,a[50005]={0},xor1,iscor;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i=0;
        for(cnt=0;cnt<n-2;cnt++)
        {
            quo=cnt/2;
            printf("1 %d %d %d\n",2*quo+1,2*quo+2,cnt+3);
            fflush(stdout);
            if(cnt==0)
            {
                scanf("%d",&o_tw_th);
                //if(o_tw_th==-1) return;
            }
            else if(cnt==1)
            {
                scanf("%d",&o_tw_f);
                //if(o_tw_f==-1) return;
                th_f=o_tw_f^o_tw_th;
            }
            else if(cnt==2)
            {
                scanf("%d",&th_f_fv);
                //if(th_f_fv==-1) return;
                a[5]=th_f_fv^th_f;
            }
            else if(cnt==3)
            {
                scanf("%d",&th_f_sx);
                //if(th_f_sx==-1) return;
                a[6]=th_f_sx^th_f;
            }
            else
            {
                scanf("%d",&xor1);
                //if(xor1==-1) return;
                a[cnt+3]=xor1^a[2*quo+1]^a[2*quo+2];
            }
        }
        if(n%2==1)
        {
            printf("1 %d %d %d\n",1,n-1,n);
            fflush(stdout);
            scanf("%d",&xor1);
            //if(xor1==-1) return;
            a[1]=xor1^a[n-1]^a[n];
            printf("1 %d %d %d\n",2,n-2,n);
            fflush(stdout);
            scanf("%d",&xor1);
            if(xor1==-1) return;
            a[2]=xor1^a[n-2]^a[n];
        }
        if(n%2==0)
        {
            printf("1 %d %d %d\n",1,n-1,n);
            fflush(stdout);
            scanf("%d",&xor1);
            //if(xor1==-1) return;
            a[1]=xor1^a[n-1]^a[n];
            printf("1 %d %d %d\n",2,n-1,n);
            fflush(stdout);
            scanf("%d",&xor1);
            if(xor1==-1) return;
            a[2]=xor1^a[n-1]^a[n];
        }
        a[3]=o_tw_th^a[1]^a[2];
        a[4]=o_tw_f^a[1]^a[2];
        printf("2 ");
        fflush(stdout);
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",&iscor);
        if(iscor==-1) return;
    }
}
