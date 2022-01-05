//In This Challenge, You Will Be Given An Array Of Sentences And An Array Of Queries. Determine Which Sentences Contain All Of The Words Of A Query. 

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'textQueries' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY sentences
 *  2. STRING_ARRAY queries
 */

vector<vector<int>> textQueries(vector<string> sentences, vector<string> queries) {
    vector<vector<int>> r;
    int n=sentences.size();
    int m=queries.size();
    if(m==0)
    {
        return r;
    }
    if(m==1)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(sentences[i].find(queries[0])!=string::npos)
            {
                v.push_back(i);
            }
        }
        r.push_back(v);
        return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string sentences_count_temp;
    getline(cin, sentences_count_temp);

    int sentences_count = stoi(ltrim(rtrim(sentences_count_temp)));

    vector<string> sentences(sentences_count);

    for (int i = 0; i < sentences_count; i++) {
        string sentences_item;
        getline(cin, sentences_item);

        sentences[i] = sentences_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<vector<int>> result = textQueries(sentences, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
