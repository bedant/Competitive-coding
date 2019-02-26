#include<stdio.h>
#include<stdlib.h>
void fill(int out[][102],int st[][102],int r,int c,char ch,n,m)
{
    for(i=0;i<)
}
int main()
{
    int t,n,i,j,k,m,len,h;
    char oper[20002],new[20002],st[102][102],prev;
    char out_st[102][102]={'0'},last_lat,last_ud;
    int lat_mirr=0,ud_mirr=0;
    scanf("%d",&t);
    while(t--)
    {
        //lat_mirr=0,ud_mirr=0;
        int r[102]={0},c[102]={0};
        scanf("%d%d",&n,&m);
       // printf("\n\n");
        for(h=0;h<n;h++)
        {
            for(j=0;j<m;j++)
            {
                out_st[h][j]='0';
            }
        }
        for(h=0;h<n;h++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c",out_st[h][j]);
            }
            printf("\n");
        }
        for(i=0;i<n;i++)
            scanf("%s",st[i]);
        scanf("%s",oper);
        len=strlen(oper);
       // prev=oper[0];
        //new[0]=oper[0];
        eff[1]='N';
        eff[0]=oper[0];
        for(i=1 ; i<len ;i++)
        {
            if( (eff[0]=='L' || eff[0]=='R') && (oper[i]=='U'|| oper[i]=='D') )
            {
                eff[1]=oper[i];
                break;
            }
            if( (eff[0]=='D' || eff[0]=='U') && (oper[i]=='L'|| oper[i]=='R') )
            {
                eff[1]=oper[i];
                break;
            }
        }
        for(i=0 ; i<len ;i++)
        {
            if(oper[len-1-i]=='L' || oper[len-1-i]=='R')
            {
                last_lr=oper[len-1-i];
                break;
            }
        }
        for(i=0 ; i<len ;i++)
        {
            if(oper[len-1-i]=='D' || oper[len-1-i]=='L')
            {
                last_ud=oper[len-1-i];
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='1')
                {
                    r[i]++;c[j]++;
                }
            }
        }
        fill(out_st,st,r,c,eff[0],n,m);
        fill(out_st,st,r,c,eff[1],n,m);
        if(last_lr!=eff[0] && last_lr!=eff[1]) fill(out_st,st,r,c,last_lr,n,m);
        if(last_ud!=eff[0] && last_ud!=eff[1]) fill(out_st,st,r,c,last_ud,n,m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("i=%d,j=%d,   %c    ",i,j,out_st[i][j]);
            }
            printf("\n");
        }
    }
}
