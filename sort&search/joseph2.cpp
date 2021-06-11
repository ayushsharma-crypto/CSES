#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    int n,k;
    cin >> n >> k;
    ordered_set arr;
    for(int i=1;i<=n;i++) arr.insert(i);
    int index=k%n;
    while(arr.size())
    {
        auto a = arr.find_by_order(index);
        cout << *(a) << " ";
        arr.erase(a);
        if(arr.size()<index) index=0;
        if(arr.size()<=0) break;
        int shift = k%arr.size();
        if(shift>=arr.size()-index) 
        {
            shift-=(arr.size()-index);
            index=0;
        }
        index+=shift;
    }
    cout << endl;
    return 0;
}