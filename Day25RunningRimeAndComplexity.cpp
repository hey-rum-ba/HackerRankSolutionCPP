#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
    int count=0;
    if(n==1) {cout<<"Not prime"<<endl;}
    else{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) count++;
    }
    if(count>0) cout<<"Not prime"<<endl;
    else cout<<"Prime"<<endl;
        }}
    return 0;
}
