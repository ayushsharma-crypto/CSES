#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,k;
    cin >> k >> n;
    multiset<int> gap_stack;
    set<int> pos_stack;
    pos_stack.insert(0);
    pos_stack.insert(k);
    gap_stack.insert(k);
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(pos_stack.find(x)==pos_stack.end())
        {
            auto up = pos_stack.upper_bound(x);
            auto lw = up;
            int diff = (*up)-(*(--lw));
            auto pos = gap_stack.find(diff);
            pos_stack.insert(x);
            gap_stack.insert((*up)-x);
            gap_stack.insert(x-(*lw));
            gap_stack.erase(pos++,pos);
        }
        auto max = gap_stack.end();
        max--;
        cout << (*max) << " ";
    }
    cout << endl;
    return 0;
}