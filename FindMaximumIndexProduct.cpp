#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long long solve(vector<int> arr) {
    int n = arr.size();
    vector<int>left(n) , right(n);
    stack<int> Stack;

    for(int i=0 ; i<n ; i++)
    {
        while(!Stack.empty() && arr[Stack.top()] <= arr[i])
            Stack.pop();
        if(!Stack.empty())
            left[i] = Stack.top() + 1;
            Stack.push(i);
    }

    while(!Stack.empty())Stack.pop();

    for(int i=n-1 ; i>=0 ; i--)
    {
        while(!Stack.empty() && arr[Stack.top()] <= arr[i])
            Stack.pop();
        if(!Stack.empty())
            right[i] = Stack.top() + 1;
        Stack.push(i);
    }

    long long ans = 0;

    for(int i=0 ; i<n ; i++)
    {
        ans = max(ans ,(long long)left[i] * right[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    long long result = solve(arr);

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
