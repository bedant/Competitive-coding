#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,num,a,i;
    multiset<int> s;
    cin>>n>>x>>y;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s.insert(a);
    }
    //multiset<int> :: iterator it;
   //     for(it=s.begin();it!=s.end();it++)
     //       cout<<*it<<" ";
    //cout<<endl;
    if(x>y)
    {
        cout<<n<<endl;
    }
    else if(x<=y)
    {
        for(i=1;s.size()>0;i++)
        {
            if(i%2)
            {
                num=*(s.begin());
                s.erase(s.begin());
                num-=x;
      //          cout<<num+x<<"->"<<num<<endl;
                if(num>0)
                {
                    s.insert(num);
                    break;
                }
            }
            else
            {
                num=*(s.begin());
                s.erase(s.begin());
                num+=y;
        //        cout<<"2: "<<num-y<<"->"<<num<<endl;
                s.insert(num);
            }
          //          for(it=s.begin();it!=s.end();it++)
            //            cout<<*it<<" ";
              //      cout<<endl;
        }
       // set<int> :: iterator it;
       // for(it=s.begin();it!=s.end();it++)
         //   cout<<*it<<" ";
        //cout<<endl;
        cout<<n-s.size()<<endl;
    }
}
