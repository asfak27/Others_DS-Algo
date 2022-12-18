#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        int
#define  mod      1000000007
#define  N         1000005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll ar[N];
ll segment[N];
void init(ll sz,ll n)
{
    ll idx=-1;
    for(ll i=0;i<n;i++)
    {
        if(i%sz==0)
        {
            idx++;
        }
        segment[idx]+=ar[i];
    }
}
ll query(ll sz,ll l,ll r)///sz=size of segment
{
    ll sum=0;

    while(l<r && l%sz!=0)
    {
        sum+=ar[l];
        l++;
    }
    while(l+sz<=r)
    {
        sum+=segment[l/sz];
        l+=sz;
    }

    while(l<=r)
    {
        sum+=ar[l];
        l++;
    }
    return sum;
}
void update(ll sz,ll idx,ll val)
{
    ll x=idx/sz;///x=update x'th segment

    segment[x]-=ar[idx];
    segment[x]+=val;
    ar[idx]=val;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z,x,k,r;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll sz=sqrt(n);
    init(sz,n);

    for(i=0;i<=sz+1;i++)
    {
        cout<<segment[i]<<" ";
    }
    cout<<endl;
    cin>>m;
    while(m--)
    {
        cin>>l>>r;
        l--;
        r--;
        ll ans=query(sz,l,r);
        cout<<ans<<endl;
    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

