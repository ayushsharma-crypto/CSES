#include <iostream>
using namespace std;
#define ll long long int

ll min_diff(ll arr[],ll n,ll c_sum,ll total, ll index)
{
    if(index==n-1)
        return min(abs(total-2*c_sum),abs(total-2*(c_sum+arr[index])));
    ll a = min_diff(arr,n,c_sum,total,index+1);
    ll b = min_diff(arr,n,c_sum+arr[index],total,index+1);
    return min(a,b);
}


int main() {
    ll n,sum=0;
    cin >> n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    cout << min_diff(arr,n,0,sum,0) << endl;
    return 0;
}