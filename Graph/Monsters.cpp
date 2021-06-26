#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

int di[4] = {-1,0,1,0};
int dj[4] = {0,-1,0,1};
char dr[4] = {'U','L','D','R'};

int main()
{
    ll n,m;
    cin >> n >> m;
    char Input[n][m];
    ll monster_pos[n][m],player_pos[n][m];
    queue<pair<ll,ll>> monster_queue,player_queue;
    pair<ll,ll> parent[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            monster_pos[i][j]=0;
            player_pos[i][j]=0;
            parent[i][j]={-1,-1};
            cin >> Input[i][j];
            if(Input[i][j]=='A') 
            {
                player_queue.push({i,j});
                player_pos[i][j]=1;
                parent[i][j]={i,j};
            }
            else if(Input[i][j]=='M') 
            {
                monster_pos[i][j]=1;
                monster_queue.push({i,j});
            }
        }
    }
    ll flag=1,I=-1,J=-1;
    while(flag)
    {
        // print_q(monster_queue,1);
        // print_q(player_queue,0);
        ll msz = monster_queue.size();
        while(msz--)
        {
            pair<ll,ll> X = monster_queue.front();
            monster_queue.pop();
            for(int i=0;i<4;i++)
            {
                ll a = X.first+di[i];
                ll b = X.second+dj[i];
                if((monster_pos[a][b]==1) || a<0 || a>=n || b<0 || b>=m || (Input[a][b]=='#')) continue;
                monster_pos[a][b]=1;
                monster_queue.push({a,b});
            }
        }

        ll psz = player_queue.size();
        if(psz==0) break;
        while(psz--)
        {
            pair<ll,ll> X = player_queue.front();
            player_queue.pop();
            if(X.first==0 || X.second==0 || X.first==n-1 || X.second==m-1)
            {
                I=X.first,J=X.second;
                flag=0;
                break;
            }
            for(int i=0;i<4;i++)
            {
                ll a = X.first+di[i];
                ll b = X.second+dj[i];
                if((monster_pos[a][b]==1) || (player_pos[a][b]==1) || a<0 || a>=n || b<0 || b>=m || (Input[a][b]=='#')) continue;
                player_pos[a][b]=1;
                player_queue.push({a,b});
                parent[a][b]={X.first,X.second};
            }            
        }
    }
    if(I!=-1)
    {
        cout << "YES\n";
        int x=I,y=J;
        string ans="";
        while(parent[x][y].first!=x || parent[x][y].second!=y)
        {
            ll X = parent[x][y].first;
            ll Y = parent[x][y].second;
            for(int i=0;i<4;i++)
            {
                if(X+di[i]!=x || Y+dj[i]!=y) continue;
                ans+=dr[i];
            }
            x = X;
            y = Y;
        }
        cout << ans.size() << endl;
        for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
        if(ans.size()) cout <<  endl;
    }
    else cout << "NO\n";

    return 0;
}