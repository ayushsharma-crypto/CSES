#include <iostream>
using namespace std;
int main() 
{
    string str;
    cin >> str;
    int arr[26] = {0};
    for(int i=0;i<str.length();i++)
        arr[(int)str[i]-(int)'A']++;

    int odd = 0;
    for(int i=0;i<=25;i++)
    {
        if(arr[i]%2) odd++;
        if(odd>1){
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    

    for(int i=0;i<=25;i++)
    {
        if(arr[i]%2) continue;
        for(int j=0;j<arr[i]/2;j++)
            cout << (char)(i+65);
    }
    for(int i=0;i<=25;i++)
    {
        if(arr[i]%2==0) continue;
        for(int j=0;j<arr[i];j++)
            cout << (char)(i+65);
    }
    for(int i=25;i>=0;i--)
    {
        if(arr[i]%2) continue;
        for(int j=0;j<arr[i]/2;j++)
            cout << (char)(i+65);
    }
    cout << endl;
    
    return 0;
}
