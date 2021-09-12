#include <bits/stdc++.h>

const int N = int(1e5) + 5;
int n, a[N], p[N];
bool used[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int solve() {
    memset(used, 0, sizeof(used));
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x = i;
        if (used[x])
            continue;
        while (!used[x]) {
            used[x] = true;
            x = p[x];
        }
        cur++;
    }
    return n - cur;
}

int main() {
    assert(scanf("%d", &n) == 1);
    for (int i = 0; i < n; ++i) {
        assert(scanf("%d", &a[i]) == 1);
        assert(1 <= a[i] && a[i] <= int(2e9));
        p[i] = i;
    }

    std::sort(p, p + n, cmp);
    for (int i = 0; i + 1 < n; ++i)
        assert(a[p[i]] != a[p[i + 1]]);

    int res = solve();  
    std::reverse(p, p + n);
    res = std::min(res, solve());
    printf("%d\n", res);
    return 0;
#include <bits/stdc++.h>

const int N = int(1e5) + 5;
int n, a[N], p[N];
bool used[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int solve() {
    memset(used, 0, sizeof(used));
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x = i;
        if (used[x])
            continue;
        while (!used[x]) {
            used[x] = true;
            x = p[x];
        }
        cur++;
    }
    return n - cur;
}

int main() {
    assert(scanf("%d", &n) == 1);
    for (int i = 0; i < n; ++i) {
        assert(scanf("%d", &a[i]) == 1);
        assert(1 <= a[i] && a[i] <= int(2e9));
        p[i] = i;
    }

    std::sort(p, p + n, cmp);
    for (int i = 0; i + 1 < n; ++i)
        assert(a[p[i]] != a[p[i + 1]]);

    int res = solve();  
    std::reverse(p, p + n);
    res = std::min(res, solve());
    printf("%d\n", res);
    return 0;
}