#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

void dfs(ll node, ll *visited,vector<ll>Graph[])
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
    ll n,m;
    cin >> n >> m;
    vector<ll> Graph[n*m];
    vector<string> input;
    for(int i=0;i<n;i++)
    {
        string line;
        cin >> line;
        input.push_back(line);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(input[i][j]=='#') continue;
            Graph[m*i+j].push_back(m*i+j);
            if((j>0)&&(input[i][j-1]!='#')) Graph[m*i+j].push_back(m*i+j-1);
            if((i>0)&&(input[i-1][j]!='#')) Graph[m*i+j].push_back(m*i+j-m);
            if((j<m-1)&&(input[i][j+1]!='#')) Graph[m*i+j].push_back(m*i+j+1);
            if((i<n-1)&&(input[i+1][j]!='#')) Graph[m*i+j].push_back(m*i+j+m);
        }
    }
    // for(int i=0;i<n*m;i++)
    // {
    //     cout << "i = " << i <<  " : ";
    //     for(auto it:Graph[i]) cout << it << " ";
    //     cout << endl;
    // }
    ll count=0,visited[n*m]={0};
    for(int i=0;i<n*m;i++)
    {
        if(visited[i] || (Graph[i].size()==0)) continue;
        count++;
        dfs(i,visited,Graph);
    }
    cout << count << endl;
    return 0;
}