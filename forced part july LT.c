#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t,n,i,j,k,m,len,h;
    char oper[20002],new[20002],st[102][102],prev;
    char out_st[102][102]={'0'},last_lat,last_ud;
    int lat_mirr=0,ud_mirr=0;
    scanf("%d",&t);
    while(t--)
    {
        int r[102]={0},c[102]={0};
        scanf("%d%d",&n,&m);
        for(h=0;h<n;h++)
        {
            for(j=0;j<m;j++)
            {
                out_st[h][j]='0';
            }
        }

        for(i=0;i<n;i++)
            scanf("%s",st[i]);
        scanf("%s",oper);
        len=strlen(oper);

        new[0]=oper[0];
        for(k=0,i=1;i<len;i++)
        {
            if( (oper[i-1]=='L' || oper[i-1]=='R') && (oper[i]=='L' || oper[i]=='R') )
                new[k]=oper[i];
            else if( (oper[i-1]=='D' || oper[i-1]=='U') && (oper[i]=='D' || oper[i]=='U') )
                new[k]=oper[i];
            else
            {
                k++;
                new[k]=oper[i];
            }
        }
        new[k+1]='\0';
        len=k+1;
        //for(i=0;i<len;i++)
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
        for(i=0;i<2 && i<len;i++)
        {
            for(h=0;h<n;h++)
            {
                for(j=0;j<m;j++)
                {
                    out_st[h][j]='0';
                }
            }
            if(new[i]=='L')
            {
                last_lat='L';
                for(h=0;h<n;h++)
                {
                    for(j=0;j<r[h];j++)
                        out_st[h][j]='1';
                }
            }
            else if(new[i]=='R')
            {
                last_lat='R';
                for(h=0;h<n;h++)
                {
                    for(j=0;j<r[h];j++)
                        out_st[h][m-1-j]='1';
                }
            }
            else if(new[i]=='U')
            {
                last_ud='U';
                for(j=0;j<m;j++)
                {
                    for(h=0;h<c[j];h++)
                        out_st[h][j]='1';
                }
            }
            else if(new[i]=='D')
            {
                last_ud='D';
                for(j=0;j<m;j++)
                {
                    for(h=0;h<c[j];h++)
                        out_st[n-1-h][j]='1';
                }
            }
            for(h=0;h<n;h++)
            {
                r[h]=0;
            }
            for(j=0;j<m;j++)
            {
                c[j]=0;
            }
            for(h=0;h<n;h++)
            {
                for(j=0;j<m;j++)
                {
                    if(out_st[h][j]=='1')
                    {
                        r[h]++;c[j]++;
                    }
                }
            }
        }
        for(i=2;i<len;i++)
        {
            if(new[i]=='L')
            {
                if(last_lat=='R')
                {
                    lat_mirr=(!(lat_mirr));
                    last_lat='L';
                }
            }
            else if(new[i]=='R')
            {
                if(last_lat=='L')
                {
                    lat_mirr=(!(lat_mirr));
                    last_lat='R';
                }
            }
            else if(new[i]=='D')
            {
                if(last_ud=='U')
                {
                    ud_mirr=(!(ud_mirr));
                    last_ud='D';
                }
            }
            else if(new[i]=='U')
            {
                if(last_ud=='D')
                {
                    ud_mirr=(!(ud_mirr));
                    last_ud='U';
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                st[i][j]=out_st[i][j];
            }
        }
        if(ud_mirr)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    out_st[i][j]=st[n-1-i][j];
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    st[i][j]=out_st[i][j];
                }
            }
        }
        if(lat_mirr)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    out_st[i][j]=st[i][m-1-j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c",out_st[i][j]);
            }
            printf("\n");
        }
    }
}
