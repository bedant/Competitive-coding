#include<stdio.h>
long long int multiply (long long int a,long long int b,long long int c)
{
    a=a%c;
	long long int result=0;
	{
		for(;b>0;b/=2)
		{
			if(b%2) result=(result+a%c)%c;
			a=(2*a)%c;
		}
	}
	return result;
}
long long int power (long long int a,long long int b,long long int c)
{
	long long int result=1;
	{
		for(;b>0;b/=2)
		{
			if(b%2) result=multiply(result,a,c);
			a=multiply(a,a,c);
		}
	}
	return result;
}
/*void rev(long long int l[],int i,int n)
{
	int j;
	long long int m[1001];
	for(j=i;j<n;j++)
	{
		m[j]=l[j];
	}
	for(j=i;j<n;j++)
	{
		l[j]=m[n-j+i-1];
	}
}
void add(long long int l[],int i,int n,long long int a,long long int c)
{
	int j;
	for(j=i;j<n;j++)
	{
		printf("%lld+%lld=%lld ;",l[i],a,l[i]+a);
		l[j]=(l[j]+a)%c;

	}
}
void mult(long long int l[],int i,int n,long long int b,long long int c)
{
	int j;
	for(j=i;j<n;j++)
	{
		l[j]=multiply(l[j],b,c)%c;
	}
}
*/
int main()
{
	int t,n,i,j,flag,lptr,rptr;
	long long int a,b,c,l[1005],term[1005],factpow[1005],arr[1005];
	char s[1006];
	scanf("%d",&t);
	while(t--)
	{
	    flag=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&l[i]);
		}
		scanf("%lld%lld%lld%s",&a,&b,&c,s);
		term[0]=0;factpow[0]=0;
		lptr=0;rptr=n-1;
		if(s[0]=='R')
        {
            flag=-flag;
        }
        if(flag==-1)
        {
            arr[0]=l[n-1];
            rptr--;
        }
        else
        {
            arr[0]=l[0];
            lptr++;
        }
        if(s[0]=='A')
        {
            term[0]=1;
        }
        if(s[0]=='M')
        {
            factpow[0]=1;
        }
        //printf("%d %d  flag %d\n",lptr,rptr,flag);
		for(i=1;i<n;i++)
		{
		    //printf("%d %d %d\n",lptr,rptr,flag);
		    term[i]=term[i-1];
		    factpow[i]=factpow[i-1];
			if(s[i]=='R')
			{
				flag=-flag;
			}
			if(flag==1)
            {
                arr[i]=l[lptr];
                lptr++;
            }
            else if(flag==-1)
            {
                arr[i]=l[rptr];
                rptr--;
            }
			if(s[i]=='A')
			{
				term[i]=term[i-1]+1;
			}
			if(s[i]=='M')
			{
				factpow[i]=factpow[i-1]+1;
				term[i]=multiply(term[i],b,c);
			}
			/*for(j=0;j<n;j++)
			{
				printf("arr %lld ",arr[j]);
			}
			printf("\n");
			for(j=0;j<n;j++)
			{
				printf("term %lld ",term[j]%c);
			}
			printf("\n");
			for(j=0;j<n;j++)
			{
				printf("factpow %lld ",factpow[j]%c);
			}
			printf("\n");
			*/
		}
		for(i=0;i<n;i++)
		{
		    arr[i]=multiply(arr[i],power( b,factpow[i],c ),c );
		    arr[i]+=multiply(term[i],a,c);
		}
		for(i=0;i<n;i++)
		{
			printf("%lld ",arr[i]%c);
		}
		printf("\n");
	}
}
