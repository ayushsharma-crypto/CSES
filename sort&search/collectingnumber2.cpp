#include <iostream>
using namespace std;
int main()
{
    int n,ans=0,m;
    cin >> n >> m;
    int arr[n],present[n+1],hash[n+1];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<=n;i++) present[i]=0;
    for(int i=0;i<n;i++)
    {
        present[arr[i]]=1;
        if(present[arr[i]-1]!=0) continue;
        else ans++;
    }
    for(int i=0;i<n;i++) hash[arr[i]]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(a>b) swap(a,b);
        int element = arr[a];
        if((hash[element-1]>a) && (hash[element-1]<=b) && arr[a]!=1) ans--;
        if((hash[element+1]>a) && (hash[element+1]<=b) && arr[a]!=n) ans++;
        element = arr[b];
        if((hash[element-1]>=a) && (hash[element-1]<b) && arr[b]!=1) ans++;
        if((hash[element+1]>=a) && (hash[element+1]<b) && arr[b]!=n) ans--;
        if(abs(arr[a]-arr[b])==1 && (arr[b]<arr[a])) ans++;
        if(abs(arr[a]-arr[b])==1 && (arr[b]>arr[a])) ans--;
        swap(arr[a],arr[b]);
        swap(hash[arr[a]],hash[arr[b]]);
        cout << ans << endl;
    }
    return 0;
}