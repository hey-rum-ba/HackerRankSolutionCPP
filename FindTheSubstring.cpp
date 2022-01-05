//
//String s consists of lowercase letters in the range ascii[a-z].String x consists of lowercase letters and may also contain a single wildcard character, *, that represents any one character.

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'firstOccurrence' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING x
 */

int firstOccurrence(string s, string x) {
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string x;
    getline(cin, x);

    int result = firstOccurrence(s, x);

    fout << result << "\n";

    fout.close();

    return 0;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string x;
    getline(cin, x);

    int result = firstOccurrence(s, x);

    fout << result << "\n";

    fout.close();

    return 0;
}
