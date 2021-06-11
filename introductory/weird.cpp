#include <iostream>
using namespace std;
int main() {
    long long int t;
    cin >> t;
    while(t!=1)
    {
        cout << t << " ";
        if(t%2==0) t=t/2;
        else t = 3*t+1;
    }
    cout << 1 << endl;
    return 0;
}
