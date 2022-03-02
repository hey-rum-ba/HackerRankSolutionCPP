<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    int res=0;
    if(s.size()%2==1)return -1;
    else{
        int n=s.size();
        int first[26]={},second[26]={},i=0,k=n-1;
        while(i<n/2)
        {
            first[s[i++]-'a']++;
            second[s[k--]-'a']++;
        }
        for(i=0;i<26;i++)
        {

            if(first[i]>second[i]&&first[i]!=0)
                res+=abs(first[i]-second[i]);
        }
        
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

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
=======
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    int res=0;
    if(s.size()%2==1)return -1;
    else{
        int n=s.size();
        int first[26]={},second[26]={},i=0,k=n-1;
        while(i<n/2)
        {
            first[s[i++]-'a']++;
            second[s[k--]-'a']++;
        }
        for(i=0;i<26;i++)
        {

            if(first[i]>second[i]&&first[i]!=0)
                res+=abs(first[i]-second[i]);
        }
        
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

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
>>>>>>> bb81a0673c0d891452de444bec7090e3e5ab27f4
