#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n,ans=0;
    cin >> n;
    multiset<int> cube_stack;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        auto pos = cube_stack.insert(x);
        auto it = cube_stack.upper_bound(x);
        if( (cube_stack.empty()) || (it==cube_stack.end())) ans++;
        else cube_stack.erase(it++,it);
    }
    cout << ans << endl;

    return 0;
}