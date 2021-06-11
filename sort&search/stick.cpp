#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
int main()
{
    ll n,median;
    cin >> n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int q;
        cin >> q;
        arr.push_back(q);
    }
    sort(arr.begin(),arr.end());
    median=(n/2);
    ll ans=0;
    for(int i=0;i<n;i++) ans+=abs(arr[i]-arr[median]);
    cout << ans << endl;
    return 0;
}