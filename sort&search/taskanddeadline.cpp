#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
using namespace std;
int main()
{
    ll n,sum=0,ans=0;
    cin >> n;
    vector<pair<ll,ll>> arr;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin >>a >>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    for(auto it:arr)
    {
        sum+=it.first;
        ans+=(it.second-sum);
    }
    cout << ans << endl;
    return 0;
}