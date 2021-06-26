#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define ll int
#define INF 1e9
#define f(pair) pair.first
#define s(pair) pair.second


ll dx[4] = {-1,0,1,0};
ll dy[4] = {0,-1,0,1};
string dr = "DRUL";
int main()
{
    ll n,m;
    cin >> n >> m;
    char Input[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> Input[i][j];

    pair<ll,ll> A={-1,-1},B={-1,-1};
    vector<vector<pair<ll,ll>>> parent;
    for(int i=0;i<n;i++)
    {
        vector<pair<ll,ll>> temp;
        for(int j=0;j<m;j++)
        {
            temp.push_back({-1,-1});
            if(Input[i][j]=='A') A = {i,j};
            if(Input[i][j]=='B') B = {i,j};
        }
        parent.push_back(temp);
    }

    if(f(A)==-1 || f(B)==-1)
    {
        cout << "NO" << endl;
        return 0;
    }

    queue<pair<pair<ll,ll>,pair<ll,ll>>> Q;
    Q.push({A,A});
    while(!Q.empty())
    {
        pair<pair<ll,ll>,pair<ll,ll>> front = Q.front();
        pair<ll,ll> top = f(front);
        pair<ll,ll> prt = s(front);
        Q.pop();
        if(f(parent[f(top)][s(top)])!=-1) continue;
        parent[f(top)][s(top)] = prt;
        ll r = f(top);
        ll c = s(top);
        for(int i=0;i<4;i++)
        {
            ll x = r+dx[i];
            ll y = c+dy[i];
            if(x<0 || x>=n || y<0 || y>=m || Input[x][y]=='#') continue;
            if(f(parent[x][y])!=-1) continue;
            Q.push({{x,y},top});
        }
    }


    if(f(parent[f(B)][s(B)])==-1)
    {
        cout << "NO" << endl;
        return 0;
    }
    pair<ll,ll> v=B;
    string ans="";
    while(f(v)!=f(parent[f(v)][s(v)]) || s(v)!=s(parent[f(v)][s(v)]))
    {
        pair<ll,ll> prt = parent[f(v)][s(v)];
        for(int i=0;i<4;i++)
        {
            if(f(v)+dx[i]!=f(prt) || s(v)+dy[i]!=s(prt)) continue;
            ans+=dr[i];
        }
        v = prt;
    }
    cout << "YES" << endl ;
    cout << ans.size() << endl;
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
    if(ans.size()) cout <<  endl;
    return 0;
}