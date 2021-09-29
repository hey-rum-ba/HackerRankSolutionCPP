#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    size_t result = 0;
    char ch = '0';
    char oldCh = '0';
    size_t counter = 0;
    size_t oldCounter = 0;
    size_t leftCounter = 0;
    bool special = false;
    for_each(s.begin(), s.end(),
             [&result, &ch, &oldCh, &counter, &oldCounter, &leftCounter, &special](char& val) {
        if (val == ch) ++counter;
        else
        {
            if (special)
                result += counter < leftCounter ? counter : leftCounter;
            special = counter == 1 && val == oldCh;
            if (special)
                leftCounter = oldCounter;
            result += counter * (counter + 1) / 2;
            oldCh = ch;
            ch = val;
            oldCounter = counter;
            counter = 1;
        }
    });
    if (special)
        result += counter < leftCounter ? counter : leftCounter;
    result += counter * (counter + 1) / 2;
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
