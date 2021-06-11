#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int sum = n*(n+1)/2;
    if(sum&1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        long long int temp = 0,i=0,arr[n+1]={0},slen=0;
        while(temp!=sum/2)
        {
            temp+=(n-i);
            arr[n-i]=1;
            slen++;
            if(temp==sum/2)
                break;
            temp+=(i+1);
            arr[i+1]=1;
            slen++;
            i++;
        }
        cout << slen << endl;
        for(long long int j=1;j<=n;j++)
            if(arr[j])
                cout << j << " ";
        
        cout << endl << n-slen << endl;
        for(long long int j=1;j<=n;j++)
            if(!arr[j])
                cout << j << " ";
        cout << endl;
    }
    return 0;
}
