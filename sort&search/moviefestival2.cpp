#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long int
int main()
{
    ll n,k,ans=0;
    pair<ll,ll> arr[200005];
    cin >> n >> k;
    for(ll i=0;i<n;i++) 
    {
        int x,y;
        cin >> x >> y; 
        arr[i]={y,x};
    }
    sort(arr,arr+n);
    multiset<ll>times;
    times.insert(arr[0].first);ans++;k--;
    for(int i=1;i<n;i++)
    {
        auto up = times.upper_bound(arr[i].second);
        if( (times.begin()!=up--) )
        {
            ans++;
            times.erase(up);
            times.insert(arr[i].first);
        }
        else if(k)
        {
            ans++;
            k--;
            times.insert(arr[i].first);
        }
    }
    cout << ans << endl;
    return 0;
}