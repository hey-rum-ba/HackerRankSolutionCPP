#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main() {
    long long t;
    while(~scanf("%lld", &t)) {
        -- t;
        long long x = 3;
        while(t >= x) {
            t -= x;
            x *= 2;
        }
        printf("%lld\n", x - t);
    }
    return 0;
}