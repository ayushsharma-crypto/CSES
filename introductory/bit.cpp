#include <iostream>
using namespace std;
#define M 1000000007
int main() {
    long long int n,ans=2;
    cin >> n;
    for(int i=1;i<n;i++)
        ans = (ans*2)%M;
    cout << ans << endl;
    return 0;
}
