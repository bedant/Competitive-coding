#include<iostream>
#include<cmath>
using namespace std;
long long int modInverse(long long int a,long long int m)
{
    a = a%m;
    for (long long int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
int main()
{
long long int invs=modInverse(1,163577857);
cout<<invs<<endl;
}
