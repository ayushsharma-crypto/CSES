#include <iostream>
using namespace std;
#define ll long long int
#define M 1000000007
int main()
{
    ll n;
    cin >> n;
    ll grid[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        string x;
        cin >> x;
        for(int j=1;j<=x.length();j++)
        {
            if(x[j-1]=='.') grid[i][j]=0;
            else grid[i][j]=-1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        grid[0][i]=0;
        grid[i][0]=0;
    }
    if(grid[1][1]!=-1) grid[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(grid[i][j]==-1) continue;
            if(grid[i-1][j]!=-1) grid[i][j]=(grid[i][j]+grid[i-1][j])%M;
            if(grid[i][j-1]!=-1) grid[i][j]=(grid[i][j]+grid[i][j-1])%M;
        }
    }
    if(grid[n][n]<=0) cout << 0 << endl;
    else cout << grid[n][n] << endl;
    return 0;
}