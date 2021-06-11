#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int
int main() 
{
    ll q,count[18]={0};
    cin >> q;
    for(int i=1;i<18;i++)
    {
        ll a = i*(ll)pow(10,i);
        ll b = ((ll)pow(10,i)-1)/9;
        count[i] = a-b;
    }
    while (q--)
    {
        ll k;
        cin >> k;
        for(int i=1;i<19;i++)
        {
            if(count[i]<k) continue;
            else if(count[i]==k)
            {
                cout << 9 << endl;
                break;
            }
            ll temp = k-count[i-1];
            if(temp%i==0)
                cout << ((temp/i)+((ll)pow(10,i-1)-1))%10 << endl;
            else
            {
                int mod = temp%i;
                temp = (temp/i)+((ll)pow(10,i-1)-1)+1;
                for(int j=0;j<(i-mod);j++) temp= temp/10;

                cout << temp%10 << endl;
            }
            break;
        }
    }
    
    return 0;
}
