#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    bool poss=false;
        long long int ans=0;
        if(s[0]=='0'){
            string ns="0";
            long long int next=1;
            while(ns.size()<s.size()){
                ns+=to_string(next);
                next++;
            }
            if(ns==s) poss=true;
        }
        else{
            for(int i=1;i<=(s.size()/2);i++){
                ans*=10;
                ans+=(s[i-1]-'0');
                long long int next=ans+1;
                string ns=s.substr(0,i);
                while(ns.size()<s.size()){
                    ns+=to_string(next);
                    next++;
                }
                if(ns==s){
                    poss=true;
                    break;
                }
            }
        }
        if(poss&&s.size()>1) cout<<"YES "<<ans<<endl;
        else cout<<"NO"<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
