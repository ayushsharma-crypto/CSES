#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int,int>,pair<int,int>>> timeline;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        timeline.push_back({{x,-1},{y,i}});
        timeline.push_back({{y,1},{y,i}});
    }
    sort(timeline.begin(),timeline.end());
    // for(auto it:timeline) 
    //     cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << endl;
    int k=0,max=0;
    for(auto it:timeline) 
    {
        k-=it.first.second;
        if(max<k) max=k;
    }
    cout << max << endl;
    int ans[n];
    set<pair<int,int>> used,free;
    for(int i=1;i<=max;i++) free.insert({-1,i});
    for(auto it:timeline) 
    {
        if(it.first.second==-1)
        {
            auto use = free.begin();
            used.insert({it.second.first,(*use).second});
            free.erase(use);
            ans[it.second.second]=(*use).second;
        }
        else
        {
            auto use = used.begin();
            free.insert({-1,(*use).second});
            used.erase(use);
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}