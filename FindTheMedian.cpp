#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int main()
{
    int n;
    cin >> n;
    int mv = 0;
    vector<int> counts(20001, 0);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v += 10000;
        ++counts[v];
        mv = min(mv, v);    
    }
    int c = 0;
    for (int i = mv; i < counts.size(); ++i) {
        c += counts[i];
        if (c * 2 > n) {
            cout << i - 10000 << endl;
            break;
        }
    }
    return 0;
}
