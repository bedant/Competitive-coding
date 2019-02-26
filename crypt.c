#include<stdio.h>
int check(char b[][][],char arr[][],int cnt[],int arrsz)
{
    stacksz=0;
    for(i=0;i<arrsz;i++)
    {

        push(arr[i]);
        stacksz++;
        len=strlen(arr[i]);
        for(j=arrcnt[i]+1;j<cnt[len];j++)
        {
            idwrd=b[len][j];
            for(k=0;k<len;k++)
            {
                idch=idwrd[k];
                ch=arr[i][k];
                if(alpha[i][ch]=='%' || alpha[i][ch]==idch)
                    //alpha[ch]=idch;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                make alpha i+1 from alpha i;
                arrcnt[i]=j;
                break;
            }
        }
        if(j>=cnt[len])
        {
            pop(arr[i]);
            stacksz--;
            i--;
            if(stacksz<=0) return 0;
        }
    }
    return 1;
}
int main()
{

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        strcpy(b[strlen(a)][cnt[strlen(a)],a);
        cnt[strlen(a)]++;
    }
    while(1)
    {
        while(1)
        {
            scanf("%c",&ch);
            if(ch!=' ' || ch!='\n')
            {
                word[i]=ch;
                i++;
            }
            else if(ch==' ')
            {
                word[i]='\0';
                push(arr,word);
                i=0;
            }
            else if(ch=='\n')
            {
                check(b,arr,cnt,)
            }
        }
}
