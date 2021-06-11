#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mem[n+1]={0};
    for(int i=1;i<=n;i++)
        for(char c: to_string(i))
            if(i>=(c-'0'))
                if((mem[i]>mem[i-(c-'0')]+1)||(mem[i]==0))
                    mem[i]=mem[i-(c-'0')]+1;
    cout << mem[n] << endl;
    return 0;
}