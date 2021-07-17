#include <bits/stdc++.h>

using namespace std;

 string s;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cin >> s;
        if (next_permutation(s.begin(), s.end())) printf("%s\n", s.c_str());
        else cout<<"no answer"<<endl;
    }
    return 0;
}
