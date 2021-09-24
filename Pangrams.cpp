#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    char big[26] = {0};
    char small[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            small[s[i] - 'a'] = 1;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            big[s[i] - 'A'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!(big[i] == 1 || small[i] == 1)) {
            return "not pangram";
            
        }
    }

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
