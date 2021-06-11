#include <iostream>
using namespace std;
int main()
{
    int n,ans=0;
    cin >> n;
    int arr[n],hash[n+1];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<=n;i++) hash[i]=0;
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]=1;
        if(hash[arr[i]-1]!=0) continue;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}