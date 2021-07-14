#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

// Complete the hurdleRace function below.
int hurdleRace(int k, vector<int> height) {
    int mini=0;
    sort(height.begin(),height.end());
    auto it =height[height.size()-1];
    int res=0;
    if(k<it) 
    {res= it-k;}
    return res;
}

int main()
{
    int k,i;
    cin>>k;
    vector<int >height;
    while(k--)
    {
        cin>>i;
        height.push_back(i);
    }
    int result = hurdleRace(k,height);
    cout<<result<<endl;
}
   