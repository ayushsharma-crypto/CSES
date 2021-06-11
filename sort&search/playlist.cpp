#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int> current;
    int max_len=0,j=0;
    for(int i=0;i<n;i++)
    {    
        if(current.find(arr[i])!=current.end()) 
            for(;j<=current[arr[i]];j++) current.erase(arr[j]);
        current.insert({arr[i],i});
        current[arr[i]]=i;
        if(max_len<current.size()) max_len=current.size();
    }
    cout << max_len << endl;
    return 0;
}