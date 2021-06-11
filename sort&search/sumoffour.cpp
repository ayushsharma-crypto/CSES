#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,target;
    cin >> n >> target;
    vector<pair<int,int>> arr;
    vector<pair<int,pair<int,int>>> aux;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        arr.push_back({x,i});
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            aux.push_back({arr[i].first+arr[j].first,{arr[i].second,arr[j].second}});
    sort(aux.begin(),aux.end());
    int i=0,j=(n*(n-1))/2-1;
    while(i<j)
    {
        if(aux[i].first+aux[j].first==target)
        {
            if( (aux[i].second.first==aux[j].second.first)
             || (aux[i].second.first==aux[j].second.second)
             || (aux[i].second.second==aux[j].second.first)
             || (aux[i].second.second==aux[j].second.second))
            {
                j--;
                continue;
            }
            cout <<  1+(aux[i].second.first) << " " << 1+(aux[i].second.second) << " " << 1+(aux[j].second.first) << " " << 1+(aux[j].second.second) << endl;
            return 0;
        }
        else if (aux[i].first+aux[j].first>target) j--;
        else i++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}