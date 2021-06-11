#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> stack;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        while(!stack.empty() && stack[stack.size()-1].first>=x) stack.pop_back();
        if(stack.empty()) cout << 0 << " ";
        else cout << stack[stack.size()-1].second << " ";
        stack.push_back({x,i+1});
    }
    cout << endl;
    return 0;
}