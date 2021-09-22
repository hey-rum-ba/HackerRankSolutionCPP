#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {
    long long n=s.size();
    multiset<long long> m,m1;
    for(long long i=0;i<n;i++){
        if(s[i]=='a'){
            if(m.size()==0 || (*m.rbegin())>=X[i]){
                m.insert(X[i]);
                if(m.size()-m1.size()==2){
                    long long x=*m.rbegin();
                    m.erase(m.find(x));
                    m1.insert(x);
                }   
            }
            else {
                m1.insert(X[i]);
                if(m1.size()>m.size()){
                    long long x=*m1.begin();
                    m1.erase(m1.find(x));
                    m.insert(x);
                }
            }   
        }
        else{
            if(m.find(X[i])==m.end() && m1.find(X[i])==m1.end()){
                cout<<"Wrong!\n";
                continue;
            }
            else if(m.find(X[i])!=m.end()){
                m.erase(m.find(X[i]));
                if(m.size()<m1.size()){
                    long long x=*m1.begin();
                    m1.erase(m1.find(x));
                    m.insert(x);
                } 
            }
            else {
                m1.erase(m1.find(X[i]));
                if(m.size()-m1.size() >=2){
                    long long x=*m.rbegin();
                    m.erase(m.find(x));
                    m1.insert(x);
                }
            }
        }
        if(m.size()==0 && m1.size()==0) {
            cout<<"Wrong!\n";
            continue;
        }
        if(m1.size()==0){
            cout<<*m.rbegin()<<endl;
            continue;
        }
        double db=((m.size()>m1.size() ? *m.rbegin(): (*m.rbegin()+*m1.begin())/2.0));
        if(ceil(db)!=db) cout<<fixed<<setprecision(1)<<db<<endl;
        else  cout<<fixed<<setprecision(0)<<db<<endl;
    }
}
int main(void){

//Helpers for input and output

    int N;
    cin >> N;
    
    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for(int i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }
    
    median(s,X);
    return 0;
}