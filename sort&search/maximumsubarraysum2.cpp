#include <iostream>
#include <set>
#define ll long long int
using namespace std;
int main()
{
    ll n,a,b,prefix[200005],end_max[200005];
    cin >> n >> a >> b;
    prefix[0]=0;
    end_max[0]=-1000000000000000;
    for(int i=1;i<=n;i++)
    {
        cin >> prefix[i];
        prefix[i]+=prefix[i-1];
        end_max[i]=-1000000000000000;
    }
    int i=n-a,j=n-a,k=n;
    multiset<ll> set1;
    while((i>=0) && (j>=i) )
    {
        set1.insert(prefix[i--]);
        if ( (set1.size()>0) && (end_max[k]==-1000000000000000) ) end_max[k]=prefix[k]-(*set1.begin());
        else if( (set1.size()>0) && (prefix[k]-(*set1.begin())>end_max[k]) ) end_max[k]=prefix[k]-(*set1.begin());
        if( (j-i-1==b-a) || (i==-1) )
        {
            set1.erase(set1.find(prefix[++i]));
            if(i==j)
            {
                i--;
                j--;
            }
            else if(set1.find(prefix[j])!=set1.end()) set1.erase(set1.find(prefix[j--]));
            k--;
        }
        
    }
    ll ans=-1000000000000000;
    for(int i=1;i<=n;i++) ans=max(ans,end_max[i]);
    cout << ans << endl;
    return 0;
}