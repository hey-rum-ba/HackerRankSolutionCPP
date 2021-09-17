#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s)
{
    int n = s.length();
    vector<int> f(26, 0);
    for (int i = 0; i < n; i++)
    {
        f[s[i] - 'a']++;
    }
    int count1 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (f[i] % 2 != 0 && count1 == 1)
            return "NO";
        if (f[i] % 2 != 0)
            count1++;
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
