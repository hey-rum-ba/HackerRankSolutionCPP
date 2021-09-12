#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> v) {
    map<int,int> in1,in2;
    for(int i=0;i<v.size();i++)
    {
        in1[v[i]]=i;
        in2[v[i]]=i;
    }
    vector<int>v1,v2,v3,v4;
    v1=v;
    v2=v;
    v3=v;
    v4=v;
    int c1=0,c2=0;
    sort(v1.begin(),v1.end());
    sort(v3.begin(),v3.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    {
        if(v1[i]!=v2[i])
        {
            int index=in1[v1[i]];
            in2[v1[i]]=i;
            in2[v2[i]]=index;
            swap(v2[i],v2[index]);
            c1++;
        }
        if(v3[i]!=v4[i])
        {
            int ind=in1[v3[i]];
            in1[v3[i]]=i;
            in1[v4[i]]=ind;
            swap(v4[i],v4[ind]);
            c2++;
        }
    }
    if(c1<c2)
    {
        return c1;
    }
    else
    {
        return c2;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
