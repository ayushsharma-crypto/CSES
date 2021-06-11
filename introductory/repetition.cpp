#include <iostream>
using namespace std;
int main() 
{
    string str;
    cin >> str;
    char curr_char = str[0];
    int max = 1,curr_len = 1;
    for(int i=1;i<str.length();i++)
    {
        if (curr_char==str[i])
        {
            curr_len++;
            if ( (i==str.length()-1) && (max < curr_len))
                max = curr_len;
        }
        else
        {
            if(max < curr_len)
                max = curr_len;
            curr_char = str[i];
            curr_len = 1;
        }
    }
    cout << max << endl;
    return 0;
}
