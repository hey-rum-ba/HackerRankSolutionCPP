#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'printShortestPath' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER i_start
 *  3. INTEGER j_start
 *  4. INTEGER i_end
 *  5. INTEGER j_end
 */

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    int  x = j_end - j_start, y = i_end - i_start;
    if (y % 2 != 0) {
        cout << "Impossible";
        return;
    }
    if ((x + y / 2) % 2 != 0) {
        cout << "Impossible";
        return;
    }
    int a = 0, b = -y / 2, c = (x - y / 2) / 2;

    vector<int> temp = { a,b,c };
    sort(temp.begin(), temp.end());
    a = temp[1];

    b = y / 2 + a;
    c = (x - y / 2) / 2 - a;

    int ul = 0, ur = 0, r = 0, lr = 0, ll = 0, l = 0;

    if (a > 0)ur = a;
    else {
        ll = -a;
        a = -a;
    }

    if (b > 0)lr = b;
    else {
        ul = -b;
        b = -b;
    }
    if (c > 0)r = c;
    else {
        l = -c;
        c = -c;
    }
    cout << a + b + c << endl;
    string re = "";
    for (int x = 0; x < ul; x++) re += " UL";
    for (int x = 0; x < ur; x++) re += " UR";
    for (int x = 0; x < r; x++) re += " R";
    for (int x = 0; x < lr; x++) re += " LR";
    for (int x = 0; x < ll; x++) re += " LL";
    for (int x = 0; x < l; x++) re += " L";
    re.erase(re.begin());
    cout << re;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i_start = stoi(first_multiple_input[0]);

    int j_start = stoi(first_multiple_input[1]);

    int i_end = stoi(first_multiple_input[2]);

    int j_end = stoi(first_multiple_input[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
