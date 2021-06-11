#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> time;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        time.push_back({a,1});
        time.push_back({b,-1});
    }
    sort(time.begin(),time.end());
    int ans=0,max=0;
    for(auto it: time)
    {
        ans+=it.second;
        if(ans>max) max=ans;
    }
    cout << max << endl;
    return 0;
}