#include <iostream>
using namespace std;
int visited[7][7]={0};
string str;

bool pruned(int r, int c)
{
    if(r==0 && c>0 && c<6 && visited[r+1][c]==1 && visited[r][c-1]==0 && visited[r][c+1]==0) return true;
    if(r==6 && c>0 && c<6 && visited[r-1][c]==1 && visited[r][c-1]==0 && visited[r][c+1]==0) return true;
    if(c==0 && r>0 && r<6 && visited[r][c+1]==1 && visited[r-1][c]==0 && visited[r+1][c]==0) return true;
    if(c==6 && r>0 && r<6 && visited[r][c-1]==1 && visited[r-1][c]==0 && visited[r+1][c]==0) return true;
    
	if(r==0||r==6||c==0||c==6)return false;
	if(visited[r][c+1]==1&&visited[r][c-1]==1&&visited[r-1][c]==0&&visited[r+1][c]==0)return true;
	if(visited[r+1][c]==1&&visited[r-1][c]==1&&visited[r][c+1]==0&&visited[r][c-1]==0)return true;
    return false;
}

int count_ways(int index,int r, int c)
{
    if(r==6 && c==0) return (index==48);
    if(index>47) return 0;
    if(pruned(r,c)) return 0;
    visited[r][c]=1;
    int a=0,b=0,k=0,d=0;
    if( (r>0) && (visited[r-1][c]==0) && (str[index]=='?' || str[index]=='U')) a=count_ways(index+1,r-1,c);
    if( (r<6) && (visited[r+1][c]==0) && (str[index]=='?' || str[index]=='D')) b=count_ways(index+1,r+1,c);
    if( (c>0) && (visited[r][c-1]==0) && (str[index]=='?' || str[index]=='L')) k=count_ways(index+1,r,c-1);
    if( (c<6) && (visited[r][c+1]==0) && (str[index]=='?' || str[index]=='R')) d=count_ways(index+1,r,c+1);
    visited[r][c]=0;
    return (a+b+k+d);
}

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    cout << count_ways(0,0,0) << endl;
    return 0;
}
