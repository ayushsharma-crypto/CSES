#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    ll dp[n]={0};
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i-1]>0) dp[i]=dp[i-1]+arr[i];
        else dp[i]=arr[i];
    }
    ll max=dp[0];
    for(int i=1;i<n;i++)
        if(max<dp[i])
            max=dp[i];
    cout << max << endl;
    return 0;
}