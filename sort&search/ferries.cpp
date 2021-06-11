#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> weight;
    for(int i=0;i<n;i++)
    {
        int q;
        cin >> q;
        weight.push_back(q);
    }
    sort(weight.begin(),weight.end());
    int ans=0,i=0,j=n-1;
    while(i<=j) 
    {
        if(weight[i]+weight[j]>x) j--;
        else
        {
            i++;
            j--;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}