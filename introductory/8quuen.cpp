#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int arr[8][8]={0},fs[8][8]={0},bs[8][8]={0};
int row_lookup[8]={0},fs_lookup[15]={0},bs_lookup[15]={0};

int count_ways(int column)
{
    if(column>7) return 1;
    int way=0;
    for(int i=0;i<8;i++)
    {
        if (arr[i][column]==-1) continue;
        int r=row_lookup[i];
        int b=bs_lookup[bs[i][column]];
        int f=fs_lookup[fs[i][column]];
        if(r || b || f) continue;

        row_lookup[i] = 1;
        bs_lookup[bs[i][column]] = 1;
        fs_lookup[fs[i][column]] = 1;

        way+=count_ways(column+1);
        row_lookup[i] = 0;
        bs_lookup[bs[i][column]] = 0;
        fs_lookup[fs[i][column]] = 0;
    }
    return way;
}

int main() {
    for(int i=0;i<8;i++) 
    {
        for(int j=0;j<8;j++) 
        {
            // filling `arr`
            char x;
            cin >> x;
            if(x=='*') arr[i][j]=-1;

            // filling `bs`
            bs[i][j]=i+j;

            // filling `fs`
            fs[i][j]=i-j+7;
        }
    }
    cout << count_ways(0) << endl;
    return 0;
}