#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {

  map<char, int> mp;
  map<int, int> freq;  
  for(char c : s)
    mp[c]++;
  for(auto it=mp.begin(); it!=mp.end(); it++)
    freq[it->second]++; 
  int bal=0, maxf=0;
  for(auto it = freq.begin(); it != freq.end(); ++it) {
     
     if(it->second > maxf) {
     maxf=it->second;
     bal =it->first;  
     }
  }
  int count=0, del=0;
  for(auto it=mp.begin(); it!=mp.end(); it++) {
     
     if(it->second==1||it->second==bal-1||it->second==bal+1)
        del++;
     
     else if(abs(it->second-bal) > 0)
        count++;
  }
  if(del<=1 && count==0)
     return "YES";
  else
     return "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
