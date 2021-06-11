#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n,k,arr[200005],set_type[200005];
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    multiset<int> set1,set2;
    for(int i=0;i<n;i++)
    {
        if(i+1>k)
        {
            if (set1.find(arr[i-k])!=set1.end()) set1.erase(set1.find(arr[i-k]));
            else set2.erase(set2.find(arr[i-k]));
        }
        set2.insert(arr[i]);
        while(set2.size()>set1.size())
        {
            set1.insert((*set2.begin()));
            set2.erase(set2.begin());
        }

        auto ans = set1.end();
        ans--;
        if((set2.size()>0)&&(*ans > (*set2.begin())))
        {
            set1.insert((*set2.begin()));
            set2.erase(set2.begin());
            set2.insert((*ans));
            set1.erase(ans);
        }

        if(i+1>=k)
        {
            ans = set1.end();
            ans--;
            cout << *ans << " ";
        }
    }
    cout << endl;
    return 0;
}