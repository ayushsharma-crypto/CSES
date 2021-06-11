#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void print_gray_code(vector<vector<int>> g_code)
{
    for(auto line:g_code)
    {
        for(auto bit:line)
            cout << bit;
        cout << endl;
    }
}

vector<vector<int>> gray_code(int n)
{
    if(n==1)
    {
        vector<int> t1;
        t1.push_back(1);
        vector<int> t0;
        t0.push_back(0);
        vector<vector<int>> s;
        s.push_back(t1);
        s.push_back(t0);
        return s;
    }

    vector<vector<int>> g_code1 = gray_code(n-1);
    for(int i=0;i<g_code1.size();i++) g_code1[i].push_back(0);

    vector<vector<int>> g_code2 = gray_code(n-1);
    reverse(g_code2.begin(),g_code2.end());
    for(int i=0;i<g_code2.size();i++) g_code2[i].push_back(1);

    for(int i=0;i<g_code2.size();i++) g_code1.push_back(g_code2[i]);
    return g_code1;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> g_code = gray_code(t);
    print_gray_code(g_code);
    return 0;
}