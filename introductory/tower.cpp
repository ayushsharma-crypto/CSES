#include <iostream>
#include <cmath>
using namespace std;

void TOH(int t,int A,int B, int C)
{
    if(t==1)
    {
        cout << A << " " << C << endl;
        return;
    }
    TOH(t-1,A,C,B);
    cout << A << " " << C << endl;
    TOH(t-1,B,A,C);
}

int main() {
    int t,min;
    cin >> t;
    min = (int)pow(2,t)-1;
    cout << min << endl;
    TOH(t,1,2,3);
    return 0;
}