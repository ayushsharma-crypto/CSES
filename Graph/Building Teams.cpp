#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

ll DFS(ll color[], ll node, vector<ll> Graph[], ll col)
{
    color[node] = col;
    ll nxt = col+1;
    if(nxt==3) nxt=1;
    for(auto it:Graph[node])
    {
        ll ret=0;
        if(!color[it]) ret=DFS(color,it,Graph,nxt);
        else if(color[it]==1 && nxt==2) return -1;
        else if(color[it]==2 && nxt==1) return -1;
        if(ret==-1) return -1;
    }
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
    ll color[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(color[i]) continue;
        if(DFS(color,i,Graph,1)==-1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++) cout << color[i] << " ";
    cout << endl;
    return 0;
}