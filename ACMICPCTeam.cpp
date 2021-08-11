#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

char s[3001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    vvi v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j += 32) {
            v[i].push_back(0);
            for (int k = 0; k < 32 && j + k < m; ++k) if (s[i][j + k] == '1') {
                v[i].back() += (1 << k);
            }
        }
    }
    int ma = 0, cnt = 0;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        int cur = 0;
        for (int l = 0; l < v[i].size(); ++l) {
            cur += __builtin_popcount(v[i][l] | v[j][l]);
        }
        if (cur == ma) ++cnt;
        else if (cur > ma) {
            ma = cur;
            cnt = 1;
        }
    }
    cout << ma << endl << cnt << endl;
    return 0;
}