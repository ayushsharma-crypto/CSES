#include <iostream>
using namespace std;
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int x,y,layer;
        cin >> x >> y;
        layer = y>x?y:x;
        long long int base = (layer-1)*(layer-1);
        if(layer&1)
        {
            if(x>=y)
                cout << base+y << endl;
            else
                cout << base+y+y-x << endl;
        }
        else
        {
            if(x<=y)
                cout << base+x << endl;
            else
                cout << base+x+x-y << endl;
        }
    }
    return 0;
}
