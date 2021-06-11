#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> time;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        time.push_back({b,a});
    }
    sort(time.begin(),time.end());
    int j=1,ans=1,et=time[0].first;
    while(j<n)
    {
        // cout << "j = " << j << " et = " << et << endl;
        if(time[j].second>=et)
        {
            ans++;
            et=time[j].first;
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}