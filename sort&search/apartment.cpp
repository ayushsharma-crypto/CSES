#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> apartment,people;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin >>x;
        people.push_back(x);
    }
    for(int i=0;i<m;i++) 
    {
        int x;
        cin >>x;
        apartment.push_back(x);
    }
    sort(people.begin(),people.end());
    sort(apartment.begin(),apartment.end());
    int a=0,b=0,ans=0;
    while( a<n && b<m )
    {
        if(abs(people[a]-apartment[b])<=k)
        {
            ans++;
            a++;
            b++;
        }
        else if(people[a]<apartment[b]) a++;
        else b++;
    }
    cout << ans << endl;
    return 0;
}