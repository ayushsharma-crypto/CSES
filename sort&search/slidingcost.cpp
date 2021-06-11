#include <iostream>
#include <set>
using namespace std;
#define ll long long int
int main()
{
    ll n,k,arr[200005],set_type[200005],sum1=0,sum2=0;
    cin >> n >> k;
    for(ll i=0;i<n;i++) cin >> arr[i];
    multiset<ll> set1,set2;
    for(ll i=0;i<n;i++)
    {
        if(i+1>k)
        {
            if (set1.find(arr[i-k])!=set1.end())
            {
                set1.erase(set1.find(arr[i-k]));
                sum1-=arr[i-k];
            }
            else
            {
                set2.erase(set2.find(arr[i-k]));
                sum2-=arr[i-k];
            }
        }
        set2.insert(arr[i]);
        sum2+=arr[i];
        while(set2.size()>set1.size())
        {
            int temp = (*set2.begin());
            set1.insert(temp);
            set2.erase(set2.begin());
            sum2-=temp;
            sum1+=temp;
        }

        auto ans = set1.end();
        ans--;
        if((set2.size()>0)&&(*ans > (*set2.begin())))
        {
            int temp = (*set2.begin());
            set1.insert(temp);
            set2.erase(set2.begin());
            sum2-=temp;
            sum1+=temp;
            set2.insert((*ans));
            set1.erase(ans);
            sum2+=*ans;
            sum1-=*ans;
        }

        if(i+1>=k)
        {
            auto ans = set1.end();
            ans--;
            ll median = *ans;
            cout << sum2-((set2.size())*median) + (set1.size()*median) - sum1 << " ";
        }
    }
    cout << endl;
    return 0;
}