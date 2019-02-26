#include<stdio.h>
#include<math.h>
int isPerfect(int number)
{
    int i;
    for(i=1;number>0;i+=2)
        number-=i;
   if(number==0)
        return 1;
    else
        return 0;
}
typedef struct node
{
    int val;
    short int check;
}node;
int main()
{
    int n,w,q,l,r,i,j,k,tabfinal,a[101],len;
    int t;
    node tab[101][101];
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            tab[i][i].val=a[i];
            if(isPerfect(a[i]) || a[i]==0)
            {
                tab[i][i].check=1;
            }
            else tab[i][i].check=0;
        }
        //printf("okay\n");
        for(len=1;len<n;len++)
        {
            for(i=0;i<n;i++)
            {
                j=i+len;
                tab[i][j].val=(tab[i][j-1].val)&a[j];
                //pintf("%d & %d =%d\n",tab[i][j-1].val,a[j],tab[i][j].val);
                if( (tab[i][j].val)==0 || isPerfect(tab[i][j].val))
                    tab[i][j].check=1;
                else tab[i][j].check=0;
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d,%d   ",tab[i][j].val,tab[i][j].check);
            printf("\n");
        }
        printf("okay1\n");
        */
       /* for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d  ",tabfinal[i][j]);
            printf("\n");
        }
    */
        for(w=0;w<q;w++)
        {
            scanf("%d%d",&l,&r);
            i=l-1,j=r-1;
            tabfinal=0;
            for(k=i;k<=j;k++)
            {
                for(l=k;l<=j;l++)
                    tabfinal+=tab[k][l].check;
            }
            printf("%d\n",tabfinal);
        }

    }
}
