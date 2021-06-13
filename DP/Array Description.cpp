#include <iostream>
using namespace std;
#define ll long long int
#define M 1000000007
int main()
{
    ll n,m;
    cin >> n >> m;
    ll dp[m+1]={0},x,ans=1;

    cin >> x;
    if(!x) for(int i=1;i<=m;i++) dp[i]=1;
    else dp[x]=1;

    if(n==1 && !x)
    {
        cout << m << endl;
        return 0;
    }

    for(ll i=1;i<n;i++)
    {
        cin >> x;
        if(x==0)
        {
            if(m==1) continue;
            else
            {
                ll temp_dp[m+1],w1;
                temp_dp[1] = (dp[1]+dp[2])%M;
                temp_dp[m] = (dp[m]+dp[m-1])%M;
                w1=temp_dp[1];
                if(m>2)
                {
                    for(ll j=3;j<=m;j++)
                    {
                        w1=(w1+dp[j])%M;
                        if(j>3) w1=(w1-dp[j-3]+M)%M;
                        temp_dp[j-1]=w1;
                    }       
                }
                for(int j=1;j<=m;j++) dp[j]=temp_dp[j];
            }

            if(i==n-1)
            {
                ll ans_add=0;
                for(int j=1;j<m+1;j++) ans_add = (ans_add + dp[j])%M;
                ans=(ans*ans_add)%M;
            }
        }
        else
        {
            ll add_ans;
            if(m>2)
            {
                if( ((x==1) && (dp[1]==0) && (dp[2]==0))
                || ((x==m) && (dp[m]==0) && (dp[m-1]==0) )
                || ((dp[x+1]==0) && (dp[x]==0) && (dp[x-1]==0)) )
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
            
            if(x==1)
            {
                add_ans = dp[1];
                if(m>1) add_ans = (add_ans + dp[2])%M;
            }
            else if (x==m) add_ans = (dp[m] + dp[m-1])%M;
            else add_ans = ((dp[x+1] + dp[x])%M + dp[x-1])%M;
            ans=(ans*add_ans)%M;
            for(ll j=0;j<=m;j++) dp[j]=0;
            dp[x]=1;
        }
    }
    cout << ans << endl;
    return 0;
}