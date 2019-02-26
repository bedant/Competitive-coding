#include<iostream>
using namespace std
int finda(int a[],int i,int j)
{
    if(i>=j) return -100000;
    if(a[i][j]!=100000)
        return a[i][j];
    else
        return maxmm(0,maxmm(wt[i+1]+finda(a,i+1,j),wt[i+2]+finda(a,i+2,j)));

}
int findb(int b,int j)
{
    if(j==0) return 0;
    if(b[j]!=100000) return b[j];
    if(j==0) return 0;
    return maxm(findb[j-1],findb[j-2]);
}
int main()
{
    in t,n,k,wt[100005],maxmm,maxsc,j,i,a[][]
    cin>>n>>k;
    k--;
    for(i=0;i<n;i++)
        cin>>wt[i];
    for(i=0;i<n;i++)
        a[i][i]=0;
    for(j=k+1;j<n;j++)
    {
        if(k+1>=n) wt[k+1]=w[k+2]=-100000;
        if(k+2>=n) wt[k+2]=-100000;
        a[k][j]=maxmm(0,maxmm(wt[k+1]+finda(a,k+1,j),wt[k+2]+finda(a,k+2,j)));
    }
    for(j=n-1;j>=1;j++)
        b[j]=maxmm(findb(b,j-1),findb(b,j-2));
    maxsc=-100000000;
    for(j=k;j<n;j++)
    {
        if(maxsc<a[k][j]+b[j])
            maxsc=a[k][j]+b[j];
    }
    printf("%d\n",maxsc);
}
