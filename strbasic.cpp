#include <iostream>
#include<cstdio>
#include <string>

using namespace std;

string myStr;
string newVal;
//int i;

int main()
{
    char Arr[100],a;
    int n,i;
    cout << "Enter: ";
    cin >>n;

    for (i = 0; i<n ; i++)
    {
        scanf("%c",&a);
        Arr[i]=a;
    }
    for (i = 0; i<n ; i++)
    {
      cout<<Arr[i];
    }
    cout << endl;

    return 0;
}
