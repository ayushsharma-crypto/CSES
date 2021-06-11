#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long int factorial(int n)
{
    long long int ans=1;
    for(int i=1;i<=n;i++) ans*=i;
    return ans;
}

void permutation(string str,int index)
{
    if(index==str.length()-1)
    {
        cout << str << endl;
        return;
    }
    set<char> present;
    for(int i=index;i<str.length();i++)
    {
        if(present.find(str[i])==present.end())
        {
            swap(str[i],str[index]);
            sort(str.begin()+1+index,str.end());
            permutation(str,index+1);
            swap(str[index],str[i]);
        }
        present.insert(str[i]);
    }
}

int main() {
    string str;
    cin >> str;
    int hash[26] = {0};
    for(int i=0;i<str.length();i++) hash[str[i]-'a']++;
    int total = factorial(str.length());
    for(int i=0;i<26;i++) total/=factorial(hash[i]);
    cout << total << endl;
    permutation(str,0);
    return 0;
}