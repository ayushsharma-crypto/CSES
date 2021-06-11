#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
int main()
{
    ll n,sum=1;
    cin >> n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int q;
        cin >> q;
        arr.push_back(q);
    }
    sort(arr.begin(),arr.end());
    if(arr[0]!=1) cout << 1 << endl;
    else
    {
        ll i=1;
        while((i<n)&&(arr[i]-sum<2)) sum+=arr[i++];
        sum+=1;
        cout << sum << endl;
    }
    return 0;
}