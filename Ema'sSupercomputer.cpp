#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int onePluse(vector<string> grid)
{
    int m = 0;
    for(int i=0;i<grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 'B') continue;
            int k = 0;
            while(i-k>=0 && j-k >=0 && i+k < grid.size() && j +k < grid[0].size() && grid[i-k][j] == 'G' && grid[i+k][j] == 'G' && grid[i][j-k] == 'G' && grid[i][j+k] == 'G')
            {
                k++;
            }
            if(4*k-3 > m) m = 4*k-3;
        }
    }
    return m;
}
int twoPluses(vector<string> grid) {
    int m = 0;
    for(int i=0;i<grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 'B') continue;
            vector<string> grid2(grid);
            int k = 0;
            while(i-k>=0 && j-k >=0 && i+k < grid.size() && j +k < grid[0].size() &&
            grid[i-k][j] == 'G' && grid[i+k][j] == 'G' && grid[i][j-k] == 'G' && grid[i][j+k] == 'G')
            {
                grid2[i-k][j] = 'B';
                grid2[i+k][j] = 'B';
                grid2[i][j-k] = 'B';
                grid2[i][j+k] = 'B';
                k++;
                int temp = 4*k-3;
                int temp2 = onePluse(grid2);
                if(temp * temp2 > m) m = temp *temp2;
            }
        }
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
