#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    while(k--)
    {
        long long int x,y;
        cin >> x >> y;
        if((x+y)%3)
            cout << "NO" << endl;
        else if( (2*x >= y) && (2*y >= x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
