#include <iostream>
using namespace std;
int main()
{
    long long int n,max=0,sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x>max) max=x;
        sum+=x;
    }
    cout << ((sum>2*max)?sum:(2*max)) << endl;
    return 0;
}