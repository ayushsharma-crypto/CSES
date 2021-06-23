#include <iostream>
#include <map>
using namespace std;

int lower_b(map<int,int> &list,int val)
{
    int s=1,e=list.size();
    while (s<e)
    {
        int mid = s+(e-s)/2;
        if(list[mid]<val) s=mid+1;
        else e=mid;
    }
    return s;    
}

int LIS(int n, int* arr)
{
    map<int,int> list;
    for(int i=0;i<n;i++)
    {
        if(!i) list.insert({1,arr[i]});
        else
        {
            auto last = list.end();last--;
            auto ft = list.begin();
            if((*last).second<arr[i]) list.insert({(*last).first+1,arr[i]});
            else if((*ft).second>arr[i]) list[1]=arr[i];
            else list[lower_b(list,arr[i])]=arr[i];
        }
    }
    auto last = list.end();last--;
    return (*last).first;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << LIS(n,arr) << endl;
    return 0;
}