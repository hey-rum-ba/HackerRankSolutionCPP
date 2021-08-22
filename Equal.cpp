#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int equal(vector<int> a) {
    int n=a.size();
    int min=*min_element(a.begin(),a.end());
        int numops=0;
        
        for (int i=0;i<n;i++) {
            int nChocs=floor((a[i]-min)/5.0);
            a[i]-=(5*floor((a[i]-min)/5.0));
            numops+=nChocs;
        }
        min=*min_element(a.begin(),a.end()); 
        
        vector <int> freq(5); 
        for (int i=0;i<n;i++) freq[a[i]-min]++; 
        
        int extra_numops=1*(freq[1]+freq[2])+2*(freq[3]+freq[4]);
        
        int extra_numops1=1*(freq[0]+freq[1]+freq[4])+
                          2*(freq[2]+freq[3]);
        if (extra_numops1<extra_numops) extra_numops=extra_numops1;
        
        int extra_numops2=1*(freq[0]+freq[3])+
                          2*(freq[1]+freq[2]+freq[4]);
        if (extra_numops2<extra_numops) extra_numops=extra_numops2;

        return numops+extra_numops;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int result = equal(arr);

        fout << result << "\n";
    }

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
