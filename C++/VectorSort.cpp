#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   vector<int> v;
     int t;cin>>t;
     while(t--)
     {
         int i;
         cin>>i;
         v.push_back(i);
     }
     sort(v.begin(),v.end());
    for(auto i :v) cout<<i<<" ";
    return 0;
}
