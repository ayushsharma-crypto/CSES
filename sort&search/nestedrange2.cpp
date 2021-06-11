#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define PPS pair<pair<int,int>,int>
#define VPS vector<pair<pair<int,int>,int>>
#define ff(val) val.first.first
#define fs(val) val.first.second
#define ss(val) val.second
#define print(range) for(auto it : range) cout << ff(it) << " " << fs(it) << " " << ss(it) << endl;

bool cmp(PPS &A, PPS &B)
{
    return ff(A)==ff(B)?fs(A)>fs(B):ff(A)<ff(B);
}

int main()
{
    int n;
    cin >> n;
    VPS range;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >>y;
        range.push_back({{x,y},i});
    }
    sort(range.begin(),range.end(),cmp);
	ordered_set<pair<int,int>> set1,set2;
    int has_range[n]={0},in_range[n]={0};
    for(int j=n-1;j>=0;j--)
    {
        int index = ss(range[j]);
        has_range[index] = set1.order_of_key({fs(range[j])+1,-1});
        set1.insert({fs(range[j]),j});
        index = ss(range[n-1-j]);
        in_range[index] = (set2.size()) - set2.order_of_key({fs(range[n-1-j]),-1});
        set2.insert({fs(range[n-1-j]),n-1-j});

        // cout << "i = " << n-1-j << " ans = " <<in_range[index] << endl;
        // for(auto it:set2) cout << it.first << " " << it.second << endl;
    }
    for(int i=0;i<n;i++) cout << has_range[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << in_range[i] << " ";
    cout << endl;
    return 0;
}