#include <iostream>
using namespace std;
#define M 1000000007
#define ll long long int
int main()
{
    ll MTH = 1000000;
    ll dp[MTH+1]={0},bw=1;
    dp[1]=2;
    for(int i=2;i<=MTH;i++)
    {
        dp[i] = (2*dp[i-1])%M;
        dp[i] = ( dp[i] + ((3*(dp[i-1]-bw))%M) + M )%M;
        dp[i] = (dp[i] + bw)%M;
        bw = (bw+dp[i-1])%M;
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}