#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const mod = 1e9+7;
int const N=1e6;
ll fact[N+1], inv_fact[N+1];
///nCr=n!/r!*(n-r)! ---> n!*r^(-1)*(n-r)^(-1)
ll pow(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b)
    {
        if (b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void compute_factorials()
{
    fact[0]=1;
    for (ll i=1;i<=N;i++)
    {
        fact[i]=fact[i-1]*i%mod;
    }
}
void compute_inv_factorials()
{
    inv_fact[N]=pow(fact[N],mod-2);///from fermat's little theoram [a^(-1)%mod=a^(mod-2)%mod]
    for (ll i=N-1;i>=0;i--)
    {
        inv_fact[i]=inv_fact[i+1]*(i+1)%mod;
    }
}
ll nCr(ll n,ll r)///Binomial Coefficients
{
    if (n < r || r < 0)
        return 0;
    ll ans=(fact[n]*inv_fact[n-r]%mod)*inv_fact[r]%mod;///n!*r^(-1)*(n-r)^(-1)
    return ans;
}
void solve()
{
    ll a, b;
    cin>>a>>b;
    ll ans=nCr(a,b);
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    compute_factorials();
    compute_inv_factorials();
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
