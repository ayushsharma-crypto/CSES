#include <iostream>
#include <map>
using namespace std;
#define ll long long int

int main()
{
    ll n,x,arr[200005],current_sum=0,count=0;
    cin >> n >>x;
    for(ll i=0;i<n;i++) cin >> arr[i];
    map<ll,ll> hash;
    hash.insert({0,1});
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        auto itr = hash.find(current_sum-x);
        if(itr!=hash.end()) count+=itr->second;
        itr = hash.find(current_sum);
        if(itr!=hash.end()) itr->second+=1;
        else hash.insert({current_sum,1});
    }
    cout << count << endl;
    return 0;
}