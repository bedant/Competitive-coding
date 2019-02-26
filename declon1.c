#include<stdio.h>
int main()
{
    int a[500004],iscor,t,i,n,rem,o_tw_th,o_tw_f,o_th_f,tw_th_f,o,tw,th,f,th_f,th_f_fv,o_th_fv,tw_f_fv,fv,s,sn,o_th,o_f,th_f_s,o_fv_s,tw_fv_s,fv_s_sn,o_fv_sn,tw_s_sn;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        rem=n%4;
        if(rem!=0)
            rem=rem+4;
        for(i=1;i<=n-rem;i+=4)
        {
            printf("1 %d %d %d\n",i,i+1,i+2);
            fflush(stdout);
            scanf("%d",&o_tw_th);
            printf("1 %d %d %d\n",i,i+1,i+3);
            fflush(stdout);
            scanf("%d",&o_tw_f);
            printf("1 %d %d %d\n",i+1,i+2,i+3);
            fflush(stdout);
            scanf("%d",&tw_th_f);
            printf("1 %d %d %d\n",i,i+2,i+3);
            fflush(stdout);
            scanf("%d",&o_th_f);
            th_f=o_tw_th^o_tw_f;
            tw=th_f^tw_th_f;
            o= th_f^o_th_f;
            th=o_tw_f^tw_th_f^o;
            f=th_f^th;
            a[i]=o;
            a[i+1]=tw;
            a[i+2]=th;
            a[i+3]=f;
        }
        if(rem==5)
        {
            i=n-rem+1;
            printf("1 %d %d %d\n",i,i+1,i+2);
            fflush(stdout);
            scanf("%d",&o_tw_th);
            printf("1 %d %d %d\n",i,i+1,i+3);
            fflush(stdout);
            scanf("%d",&o_tw_f);
            printf("1 %d %d %d\n",i+2,i+3,i+4);
            fflush(stdout);
            scanf("%d",&th_f_fv);
            printf("1 %d %d %d\n",i,i+2,i+4);
            fflush(stdout);
            scanf("%d",&o_th_fv);
            printf("1 %d %d %d\n",i+1,i+3,i+4);
            fflush(stdout);
            scanf("%d",&tw_f_fv);
            th_f=o_tw_th^o_tw_f;
            fv=th_f^th_f_fv;
            o_th=o_th_fv^fv;
            o_f=o_th^th_f;
            tw=o_tw_f^o_f;
            f=tw_f_fv^tw^fv;
            th=th_f^f;
            o=o_f^f;
            a[i]=o;
            a[i+1]=tw;
            a[i+2]=th;
            a[i+3]=f;
            a[i+4]=fv;
            //printf("th_f=%d o_th=%d o_f=%d \n",th_f,o_th,o_f);
        }
        if(rem==6)
        {
            i=n-rem+1;
            printf("1 %d %d %d\n",i,i+1,i+2);
            fflush(stdout);
            scanf("%d",&o_tw_th);
            printf("1 %d %d %d\n",i,i+1,i+3);
            fflush(stdout);
            scanf("%d",&o_tw_f);
            printf("1 %d %d %d\n",i+2,i+3,i+4);
            fflush(stdout);
            scanf("%d",&th_f_fv);
            printf("1 %d %d %d\n",i+2,i+3,i+5);
            fflush(stdout);
            scanf("%d",&th_f_s);
            printf("1 %d %d %d\n",i,i+4,i+5);
            fflush(stdout);
            scanf("%d",&o_fv_s);
            printf("1 %d %d %d\n",i+1,i+4,i+5);
            fflush(stdout);
            scanf("%d",&tw_fv_s);

            th_f=o_tw_th^o_tw_f;
            fv=th_f^th_f_fv;
            s =th_f^th_f_s;
            o=o_fv_s^fv^s;
            tw=tw_fv_s^fv^s;
            th=o_tw_th^o^tw;
            f=o_tw_f^o^tw;

            a[i]=o;
            a[i+1]=tw;
            a[i+2]=th;
            a[i+3]=f;
            a[i+4]=fv;
            a[i+5]=s;
        }
        if(rem==7)
        {
            i=n-rem+1;
            printf("1 %d %d %d\n",i,i+1,i+2);
            fflush(stdout);
            scanf("%d",&o_tw_th);
            printf("1 %d %d %d\n",i,i+1,i+3);
            fflush(stdout);
            scanf("%d",&o_tw_f);
            printf("1 %d %d %d\n",i+2,i+3,i+4);
            fflush(stdout);
            scanf("%d",&th_f_fv);
            printf("1 %d %d %d\n",i+2,i+3,i+5);
            fflush(stdout);
            scanf("%d",&th_f_s);
            printf("1 %d %d %d\n",i+4,i+5,i+6);
            fflush(stdout);
            scanf("%d",&fv_s_sn);
            printf("1 %d %d %d\n",i,i+4,i+6);
            fflush(stdout);
            scanf("%d",&o_fv_sn);
            printf("1 %d %d %d\n",i+1,i+5,i+6);
            fflush(stdout);
            scanf("%d",&tw_s_sn);

            th_f=o_tw_th^o_tw_f;
            fv=th_f^th_f_fv;
            s =th_f^th_f_s;
            sn=fv_s_sn^s^fv;
            o=o_fv_sn^fv^sn;

            tw=tw_s_sn^sn^s;

            th=o_tw_th^o^tw;
            f=o_tw_f^o^tw;

            a[i]=o;
            a[i+1]=tw;
            a[i+2]=th;
            a[i+3]=f;
            a[i+4]=fv;
            a[i+5]=s;
            a[i+6]=sn;
        }
        printf("2 ");
        fflush(stdout);
        for(i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d",iscor);
    }
}
