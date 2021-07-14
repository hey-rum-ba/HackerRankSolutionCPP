#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n,x;
    cin >>n;
    set<int> s1,s2;
    for(int i=0;i<n;i++) {cin>>x;s1.insert(x);s2.insert(x);}
    int m,y;
    int a=0;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>y;
        s1.insert(y);
        auto aa= s1.find(y);
        auto it2 =s1.begin();
        for(int l: s2)
        {
            l++;
           while(&it2<= &aa); {a++;}
            it2++;
        }
        s1= s2;
        cout<< s2.size()-a+1<<endl;
    }
    for(auto l: s2)
        {
            cout<<l<<endl;
        }


    return 0;
}