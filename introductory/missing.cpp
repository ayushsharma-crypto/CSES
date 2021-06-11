#include <iostream>
using namespace std;
int main() {
    long long int t,sum=0;
    cin >> t;
    for(int i=0;i<t-1;i++){
        int x;
        cin >> x;
        sum+=x;
    }
    cout << (t*(t+1)/2)-sum << endl;
    return 0;
}
