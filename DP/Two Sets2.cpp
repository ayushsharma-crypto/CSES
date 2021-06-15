#include <iostream>
using namespace std;
#define ll long long int
#define M 1000000007
ll count(ll n,ll sum)
{
    if(sum&1) return 0;
    ll dp[(sum/2)+1]={0};
    dp[0]=1;
    for(int i=1;i<n;i++)
        for(int j=sum/2;j>=0;j--)
            if(dp[j] && (i+j<=(sum/2))) dp[i+j] = (dp[i+j]+dp[j])%M;

    return dp[sum/2];
}

int main()
{
    ll n;
    cin >> n;
    cout << count(n,(n*(n+1))/2) << endl;
    return 0;
}