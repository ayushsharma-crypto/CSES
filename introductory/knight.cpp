#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    cout << 0 << endl;
    for(int n=2;n<=k;n++)
    {
        long long int ans = (n*n);
        ans = ans*((n*n)-1)/2;
        ans -= 4*(n-1)*(n-2);
        cout << ans << endl;
    }
    return 0;
}
