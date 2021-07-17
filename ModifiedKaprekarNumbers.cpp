#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    vector<long long> res;
    for(long long i=p; i<=q; ++i){
        long long square = i*i;
        string s = to_string(square);
        int d = s.size()/2;
        if(d == 0){
            if(i == square){
                res.push_back(i);
            }
            continue;
        }
        if(stoll(s.substr(0,d))+stoll(s.substr(d,s.size()-d)) == i){
            res.push_back(i);
        }
           }
    if(res.size()>0){
           for(int i=0; i<res.size(); ++i){
               cout<<res[i]<<" ";
           }
        cout<<endl;}
    else{
        cout<<"INVALID RANGE"<<endl;
    }

}


int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
