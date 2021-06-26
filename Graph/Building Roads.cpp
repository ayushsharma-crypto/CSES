#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

void dfs(ll node, ll visited[],vector<ll>Graph[])
{
    visited[node]=1;
    for(auto it:Graph[node])
    {
        if(visited[it]) continue;
        dfs(it,visited,Graph);
    }
}
int main()
{
    int n,m;
    cin >> n >> m ;
    vector<ll> Graph[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    ll visited[n+1]={0};
    vector<ll> cmpnt;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        cmpnt.push_back(i);
        dfs(i,visited,Graph);
    }
    int ans=cmpnt.size()-1;
    cout << ans << endl;
    vector<pair<ll,ll>> as;
    for(int i=1;i<=ans;i++)
        cout << cmpnt[0] << " " << cmpnt[i] << endl;
    return 0;
}