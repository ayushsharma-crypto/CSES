#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int dp[501][501]={0};
    for(int i=0;i<501;i++)
    {
        for(int j=0;j<501;j++)
        {
            if(i==j) dp[i][j]=0;
            else if(i>j) dp[i][j]=dp[j][i];
            else 
            {
                dp[i][j]=1e9;
                for(int k=1;k<i;k++)
                    dp[i][j]=min(1+dp[k][j]+dp[i-k][j],dp[i][j]);
                for(int k=1;k<j;k++)
                    dp[i][j]=min(1+dp[i][k]+dp[i][j-k],dp[i][j]);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}