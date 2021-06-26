#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

ll flag=0,flag1=0,nodeR = -1;
vector <ll> ans;

ll DFS(ll visited[], ll node, vector<ll> Graph[], ll parent)
{
    visited[node] = 1;
    for(auto it:Graph[node])
    {
        if(flag) break;
        if(parent==it) continue;
        if(!visited[it]) DFS(visited,it,Graph,node);
        else 
        {
            flag=1;
            flag1=1;
            ans.push_back(it);
            nodeR=it;
        }
    }
    if(flag && flag1) ans.push_back(node);
    if(nodeR==node) flag1=0;
    return 0;
}

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
    ll visited[n+1]={0};
    flag=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        DFS(visited,i,Graph,-1);
        if(flag)
        {
            cout << ans.size() << endl;
            for(auto it:ans) cout << it << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}