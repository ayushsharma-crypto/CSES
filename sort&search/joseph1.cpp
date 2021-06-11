#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;
    if(n==1)
    {
        cout << 1 << endl;
        return 0;
    }
    set<int>arr;
    for(int i=1;i<=n;i++) arr.insert(i);
    auto it = arr.begin();++it;
    while(arr.size()>0)
    {
        cout << *it << " ";
        arr.erase(it++,it);
        if(arr.size()<=0) break;
        if(it==arr.end()) it=arr.begin();
        it++;
        if(it==arr.end()) it=arr.begin();
    }
    cout << endl;
    return 0;
}