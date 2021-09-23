#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairCut' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int fairCut(int k, vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    size_t n = arr.size();
    size_t m = n - k;
    vector<long long> w1(k), w2(m);
    for (size_t i=0; i<k; i++)
        w1[i] = k-1 - 2*i;
    for (size_t i=0; i<m; i++)
        w2[i] = m-1 - 2*i;
    size_t p = 0, i = 0, j = 0;
    vector<long long> v1, v2;
    while (i<k && j<m) {
        long a = arr[p++];
        if (w1[i] > w2[j]) {
            v1.push_back(a);
            i++;
        } else {
            v2.push_back(a);
            j++;
        }
    }
    if (i == k) {
        while (p < n) {
            v2.push_back(arr[p++]);
        }
    }
    if (j == m) {
        while (p < n) {
            v1.push_back(arr[p++]);
        }
    }
    long long sum = 0;
    for (auto i : v1) {
        for (auto j : v2) {
            sum += abs(i-j);
        }
    }
    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = fairCut(k, arr);

    fout << result << "\n";

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
