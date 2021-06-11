#include <iostream>
using namespace std;
int main()
{
    int n,x,arr[200005];
    cin >> n >>x;
    for(int i=0;i<n;i++) cin >> arr[i];
    int i=0,j=0,count=0,cs=0;
    while((i<=j)&&(j<n))
    {
        cs+=arr[j];
        if(cs==x)
        {
            count++;
            cs-=arr[i];
            i++;
        }
        else if (cs>x)
        {
            cs-=arr[i];
            i++;
            cs-=arr[j--];
        }
        j++;
    }
    cout << count << endl;
    return 0;
}