#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,x1;
    cin >> n >> x1;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        arr.push_back({x,i});
    }
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[j].first+arr[i].first==x1)
        {
            cout << arr[i].second+1 << " " << arr[j].second+1 << endl;
            break;
        }
        else if (arr[j].first+arr[i].first>x1) j--;
        else i++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}