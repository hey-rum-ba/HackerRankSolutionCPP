#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
      queue<int>q;
      int t;
      cin>>t;
      int cse,data,temp;
      for(int i=0;i<t;i++)
      {
          cin>>cse;
          switch (cse) {
          case 1:
          {
              cin>>data;
              q.push(data);
              break;
          }
          case 2:
          {
              q.pop();
              break;
          }
          case 3:
          {
              temp=q.front();
              cout<<temp<<endl;
              break;
          }
      }
      }
    return 0;
}
