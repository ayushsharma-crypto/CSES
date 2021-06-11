#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
ll n,t,karr[200005],z=1000000000000000001,st=-1;

bool product(ll time)
{
    ll tp=0;
    for(ll i=0;i<n;i++)
    {
        tp+=(time/karr[i]);
        if(tp>=t) return false;
    }
    return true;
}

int main()
{
    cin >> n >> t;
    for(ll i=0;i<n;i++) cin >> karr[i];
    for(ll i=z;i>=1;i=i/2)
        while(product(i+st))
            st+=i;
    cout << st+1 << endl;
    return 0;
}