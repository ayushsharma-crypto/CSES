#include <iostream>
using namespace std;
#define M 1000000007
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    ll mem[n+1]={0};mem[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<7;j++)
            if(i>=j) 
                mem[i] = (mem[i]+mem[i-j])%M;
    cout << mem[n] << endl;
    return 0;
}