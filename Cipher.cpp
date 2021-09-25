#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. STRING s
 */

string cipher(int k, string str) {
    int n = str.length() ;
    int len = n-k+1 ;

    int arr[len] ;
    memset(arr, 0, sizeof(len)) ;
    int val = str[0]-'0'  ;
    arr[0] = val ;

    for(int i=1; i<k; i++)
    {
        int temp = str[i]-48 ;
        arr[i] = (val xor temp) ;
        val = (val xor arr[i]) ;
    }

    int index = 0 ;

    for(int i=k; i<len; i++)
    {
        val = (val xor arr[index++]) ;
        int temp = str[i]-48 ;
        arr[i] = (val xor temp) ;
        val = (val xor arr[i]) ;
    }

    string ans = "" ;

    for(int i=0; i<len; i++)
        ans += (arr[i]+48) ;

    return ans ;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = cipher(k, s);

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
