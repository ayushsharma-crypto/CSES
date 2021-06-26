#include <iostream>
#include <queue>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin >> n >> m ;
    vector<ll> Graph[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    queue<pair<ll,ll>> Q;
    Q.push({1,1});
    ll parent[n+1]={0};
    while (!Q.empty())
    {
        pair<ll,ll> ft = Q.front();
        ll node = ft.first;
        ll prt = ft.second;
        Q.pop();
        if(parent[node]) continue;
        parent[node]=prt;
        for(auto it:Graph[node]) Q.push({it,node});
    }
    if(parent[n])
    {
        vector<ll> ans;
        ans.push_back(n);
        while(parent[ans[ans.size()-1]]!=ans[ans.size()-1]) ans.push_back(parent[ans[ans.size()-1]]);
        cout << ans.size() << endl;
        for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}