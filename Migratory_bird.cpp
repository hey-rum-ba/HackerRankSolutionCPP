#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n , t , maxi=0;
    cin >> n;
    int freq[5]={0};
    
    while(n--){
        cin >> t;
        freq[t-1]++;
    }
    
    for(int i=1 ; i<5 ; i++){
        if(freq[i]>freq[maxi]) maxi=i;
    } for(int j: freq){ cout<<*freq;j++;}
    cout << maxi+1 << endl;
    return 0;
}

