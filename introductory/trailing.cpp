#include <iostream>
using namespace std;
int main() {
    long long int n2,n5,s2=0,s5=0;
    cin >> n2;
    n5=n2;
    while(n2)
    {
        s2+=(n2/2);
        n2=n2/2;
    }
    while(n5)
    {
        s5+=(n5/5);
        n5=n5/5;
    }
    cout << (s2>s5?s5:s2) << endl;
    return 0;
}
