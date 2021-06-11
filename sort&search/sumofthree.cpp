#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_triplet(vector<pair<int,int>> &arr,int index,int target,int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(i==index) i++;
        else if (j==index) j--;
        else
        {
            if(arr[index].first+arr[j].first+arr[i].first==target)
            {
                cout << arr[index].second+1 << " " << arr[i].second+1 << " " << arr[j].second+1 << endl;
                return true;
            }
            else if (arr[index].first+arr[j].first+arr[i].first>target) j--;
            else i++;
        }
    }
    return false;
}

int main()
{
    int n,target;
    cin >> n >> target;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        arr.push_back({x,i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        if(check_triplet(arr,i,target,n)) return 0;
    cout << "IMPOSSIBLE" << endl;
    return 0;
}