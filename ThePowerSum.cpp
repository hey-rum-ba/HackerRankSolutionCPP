#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vpi vector<pair<int,int>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i > b; i--)
#define repit(i,a,b) for (int i = a; i >= b; i--)
#define iter(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define CIN(n) int n;cin>>n;while(n--) 

int k, cnt = 0;

void powsum(int n, int i) {
    if (n == 0) cnt++;
    if (n < 0) return;
    int n2 = 0;
    for (int j = i; n2 >= 0; ++j) {
        n2 = n - (int)pow(j, k);
        powsum(n2, j + 1);
    }
    return;
}

int main() {
    int r;
    cin >> r >> k;
    powsum(r, 1);
    cout << cnt;
    return 0;
}
