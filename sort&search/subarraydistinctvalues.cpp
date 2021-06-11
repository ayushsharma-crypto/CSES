#include <iostream>
#include <map>
using namespace std;
#define ll long long int
int main()
{
    ll n,k,arr[200005];
    cin >> n >>k;
    for(ll i=0;i<n;i++) cin >> arr[i];
    ll i=0,j=0,count=0,dv=0;
    map<ll,ll> hash;
    while((i<=j)&&(j<n))
    {
        if((hash.find(arr[j])!=hash.end())) hash[arr[j]]+=1;
        else hash.insert({arr[j],1});
        
        if(hash.size()<=k)
        {
            count+=(j-i+1);
            j++;
        }
        else
        {
            hash[arr[i]]-=1;
            hash[arr[j]]-=1;
            if(hash[arr[i]]<1) hash.erase(arr[i]);
            i++;
        }
    }
    cout << count << endl;
    return 0;
}