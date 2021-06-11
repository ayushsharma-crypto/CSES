#include <iostream>
using namespace std;
#define ll long long int
ll n,k,arr[200005],z=1000000000000000001,st=-1;

bool subarray(ll max_sum)
{
    // if temp_k>k then true else false;
    ll temp_k=0,i=0,sum=0;
    while(i<n)
    {  
        if(arr[i]>max_sum) return true;
        if(sum+arr[i]<=max_sum) sum+=arr[i++];
        else
        {
            temp_k++;
            sum=arr[i++];
        }
    }
    if(++temp_k>k) return true;
    else return false;
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(ll b=z;b>0;b/=2) while(subarray(b+st)) st+=b;
    st++;
    ll i=0,max_sum=-z,sum=0;
    while(i<n)
    {
        if(sum+arr[i]<=st) sum+=arr[i++];
        else sum=arr[i++];
        if(sum>max_sum) max_sum=sum;
    }
    cout << max_sum << endl;
    return 0;
}