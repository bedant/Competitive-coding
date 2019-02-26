#include<stdio.h>
int main()
{
    int t,w,i,n,right,left,a[100001],cnt,max,k;
    long long int av_mon,unused;
    scanf("%d",&t);
    while(t--)
    {
        cnt=max=0;
        scanf("%d%d",&n,&k);
        unused=k;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        left=right=0;
        av_mon=k;
        while(1){
        for(;right<n;right++)
        {
            //printf("right= %d \n",right);
            av_mon-=a[right];
            cnt++;
            if(av_mon<0)
                {
                    //cnt++;
                  //  printf("left=%d right=%d %d\n",left,right,av_mon);
                    //right++;
                    break;
                }
            if(cnt>=max && av_mon>=0)
            {
                if(cnt==max && unused>av_mon) unused=av_mon;
                if(cnt>max)
                {max=cnt;
                unused=av_mon;}
                //printf("    %d %d %d %d\n",left,right,max,unused);
            }
        }
        if(right>=n)
            {
                if(cnt>=max && av_mon>=0)
                {
                    if(cnt==max && unused<av_mon) unused=av_mon;
                    if(cnt>max)
                        {
                            max=cnt;
                            unused=av_mon;
                        }
                //printf("    %d %d %d %d\n",left,right,max,unused);
                }
                break;
            }
        for(;av_mon<0 && left<n;)
        {
            av_mon+=a[left];
            cnt--;left++;
            //printf("left=%d right=%d cnt=%d av_mon=%d\n",left,right,cnt,av_mon);
        }
        right++;
        if(left>=n) break;
        }
        printf("%d %lld\n",max,unused);
    }
}
