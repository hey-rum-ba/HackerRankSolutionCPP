#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    int N = a.size();
    multiset<int> r;
    multiset<int, greater<int> > l;
    vector<double>ans;
    for (int i = 0; i < N; ++i) {
        if (l.empty()) l.insert(a[i]);
        else {
            if (a[i] > *l.begin()) r.insert(a[i]);
            else l.insert(a[i]);
        }
        if (l.size() > r.size() + 1) {
            r.insert(*l.begin());
            l.erase(l.begin());
        } else if (r.size() > l.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        if (l.size() > r.size())
            ans.push_back(*l.begin());
        else
            ans.push_back(1.0*(*l.begin() + *r.begin())/ 2.0);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
