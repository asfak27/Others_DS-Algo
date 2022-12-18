#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000000007
#define N        1000005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
///x=a^b^c;
///Eluer Totient Function
ll bigmod(ll a,ll b,ll MOD) ///a=base,b=power;
{
    ll res=1LL;
    while(b)
    {
        if(b%2==1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return res;
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
    x=bigmod(b,c,mod-1);
    y=bigmod(a,x,mod);
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

