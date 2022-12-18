#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long int
#define mod 1000007
#define N 1000015
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll c;
ll vis[N];
vector<ll>prime;
void sieve()
{
    for(ll i=3; i<=N; i+=2)vis[i]=1;
    for(ll i=3; i*i<=N; i+=2)
    {
        if(vis[i]==1)
        {
            for(ll j=i*i; j<=N; j+=(i+i))
            {
                vis[j]=0;
            }
        }
    }
    vis[2]=1;
    prime.push_back(2);
    for(ll i=3; i<=N; i++)
    {
        if(vis[i]==1)
        {
            prime.push_back(i);
        }
    }
}
ll cnt_divisors(ll n)
{
    ll ans=1;
    ll sz = prime.size();
    for(ll i=0; i<sz && (prime[i]*prime[i])<=n ; i++)
    {
        ll cnt = 1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                ++cnt;
                n/=prime[i];
            }
        }
        ans *=cnt;
    }
    if(n>1) ans*=2;
    return ans;
}
void solve()
{
    // freopen("textnew.txt","r",stdin);
    ll n,k,i,j;
    cin>>n>>k;
    if(k>sqrt(n))
    {
        cout<<"Case "<<++c<<": "<<0<<'\n';
        return;
    }
    ll ans=cnt_divisors(n);
    ans/=2;
    //cout<<ans<<endl;
    for(i=1; i<k; i++)
    {
        if((n%i)==0)ans--;
    }
    cout<<"Case "<<++c<<": "<<ans<<'\n';
}
int main()
{
    fast;
    sieve();
    ll T = 1;
    cin>>T;
    while (T--)
        solve();
    return 0;
}
