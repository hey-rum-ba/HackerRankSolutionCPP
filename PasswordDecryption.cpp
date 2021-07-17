#include<bits/stdc++.h>
using namespace std;

/*
 * Complete the 'decryptPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string decryptPassword(string s) {
for (int i = 0; i < s.size(); i++)
{ 
    vector<string>v,v1={};
    if (s[i] >= 'a' && s[i] <= 'z' && s[i+1] >= 'A' && s[i+1] <= 'Z')
    {v.push_back(s[i+1],"*",s[i]);}
    //if s[i] is a number replace it with 0, place the original number at the start, and move to i+1
    if(s[i] >= '0' && s[i] <= '9') 
    {v.push_back("0");v.push_back(s[i]) for(auto i:v) v1.push_back(s[i])
}
}