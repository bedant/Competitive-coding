#include<stdio.h>
int main()
{
    long long int t,w,n,i,j,v[11],d[11],s,y,l[11];
    double time,ct,p[11],q[11];
    scanf("%lld",&t);
    for(w=0;w<t;w++)
    {
        time=0;
        scanf("%lld%lld%lld",&n,&s,&y);
        ct=y/(s*1.0);
        //printf("%lf\n",ct);
        for(i=0;i<n;i++)
            scanf("%lld",&v[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&d[i]);
        for(i=0;i<n;i++)
            {scanf("%lf",&p[i]);q[i]=p[i];}
            for(i=0;i<n;i++)
            scanf("%lld",&l[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[j]==1)
                    p[j]=q[j]+time*v[j]*1.0;
                if(d[j]==0)
                p[j]=q[j]-time*v[j]*1.0;
            }
            //printf("in for %d\n",i);
            if(d[i]==1)
            {
                //printf("in if 1 %d\n",i);
                if(p[i]>=l[i])
                    {
                        time+=ct;
                //printf("in if a %lf\n",time);
                }
                else if(p[i]>=0 && p[i]<l[i])
                {
                    //printf("in if b %lf\n",time);
                    time+=(ct+(l[i]-p[i])/(v[i]*1.0));
                }
                else if(p[i]<-v[i]*ct-.000001)
                    {
                        time+=ct;
                //printf("in if c %lf\n",time);
                    }
                else if(p[i]>=-v[i]*ct-.000001 && p[i]<=0)
                    {time+=((-p[i]+l[i])/(v[i]*1.0)+ct);
                //printf("in if d %lf\n",time);
                }
            }
            if(d[i]==0)
            {
                //printf("in if 2 %d\n",i);
                if(p[i]<=(-l[i]))
                    {
                        time+=ct;
                //printf("in if a %lf\n",time);
                }
                else if(p[i]<=0 && -p[i]<l[i])
                {
                    //printf("in if b %lf\n",time);
                    time+=(ct+(l[i]+p[i])/(v[i]*1.0));
                }
                else if(p[i]>v[i]*ct+.000001)
                {
                    time+=ct;
                    //printf("in if c %lf\n",time);
                }
                else if(p[i]<=v[i]*ct+.000001 && p[i]>=0)
                    {
                        time+=((p[i]+l[i])/(v[i]*1.0)+ct);
                        //printf("in if 1 %lf\n",time);
                    }
            }
        }
       printf("%lf\n",time);
    }
}
