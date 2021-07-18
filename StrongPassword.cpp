#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
int count = 0;
    
    bool a[4] = {false};
    
    for(int i = 0; i < password.size(); i++){
        if(password[i] >= 'A' && password[i] <= 'Z')
            a[2] = true;
        else if(password[i] >= 'a' && password[i] <= 'z')
            a[1] = true;
        else if(password[i] >= '0' && password[i] <= '9')
            a[0] = true;
        else
            a[3] = true;
    }
    for(int i = 0; i < 4; i++)
        if(!a[i]) count++;
    int lenght=6-password.size();    
    return max(count,lenght);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
