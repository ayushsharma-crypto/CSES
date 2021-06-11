#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    multiset<int, greater<int>> h;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        h.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        auto it = h.lower_bound(x);
        if(it==h.end()) cout << -1 << endl;
        else
        {
            cout << *it << endl;
            h.erase(it);
        }
    }
    return 0;
}