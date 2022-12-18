#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define  ll       long long
#define  mod      1000000007
#define  M        1000005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
///a^phi(m) mod m=1
///for 1 number separated
ll Totient_Phi(ll n)
{
    if(n==1)return 1;
    ll res=n;
    for (ll i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            res-=res / i;
        }
    }
    if(n>1)res-=res / n;
    return res;
}


ll phi[M];
void totientSieve()
{
    for (ll i=1;i<M;i++)
    {
        phi[i]=i;
    }
    for (ll p=2;p<M;p++)
    {
        if (phi[p]==p)
        {
            for (ll k=p;k<M;k+=p)
            {
                phi[k]-=phi[k]/p;
            }
        }
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    set<ll>s;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    ll a,b,c;
    cin>>a>>b>>c;
    //x=bigmod(b,c,mod);
    //y=bigmod(a,x,mod);
    cout<<y<<endl;


}

int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}


