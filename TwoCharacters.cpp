#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    if (s.empty())
    return s.size();

  string unique;
  for (auto c = s.cbegin(); c < s.cend(); ++c)
    if (unique.find(*c) == string::npos)
      unique.push_back(*c);

  unsigned crossIndex[26];
  for (auto i = 0; i < 26; ++i)
    crossIndex[i];
  for (auto i = 0; i < unique.size(); ++i)
    crossIndex[('z' - unique[i])] = i;

  const string::size_type ts = unique.size();
  char  letter[ts][ts];
  int   count[ts][ts];
  for (auto i = 0; i < ts; ++i)
    for (auto j = 0; j < ts; ++j)
      count[i][j] = 0;
      
  for (auto c = s.cbegin(); c < s.cend(); ++c)
  {
    const unsigned index = crossIndex['z' - *c];

    for (auto i = 0; i < ts; ++i)
    {
      if (count[index][i] != -1 && letter[index][i] != *c)
      {
        letter[index][i] = *c;
        ++count[index][i];
      }
      else
        count[index][i] = -1;

      if (count[i][index] != -1 && letter[i][index] != *c)
      {
        letter[i][index] = *c;
        ++count[i][index];
      }
      else
        count[i][index] = -1;
    }
  }

  int result = 0;
  for (auto i = 0; i < ts; ++i)
    for (auto j = 0; j < ts; ++j)
      result = max(result, count[i][j]);

  return (result > 1 ? result : 0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
