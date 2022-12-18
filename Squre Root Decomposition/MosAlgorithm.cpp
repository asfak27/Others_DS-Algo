#include <bits/stdc++.h>/// O((N+Q)*sqrt(N))
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define  N         2000005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll ar[N];
ll rootN;
struct st{
    ll idx,l,r;
};
st q[N];
bool cmp(st q1,st q2)
{
    if(q1.l/rootN==q2.l/rootN)
    {
        return q1.r>q2.r;
    }
    else return q1.l/rootN<q2.l/rootN;
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z,x,k,r;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    //sort(ar,ar+n);
    rootN=sqrtl(n);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        q[i].l=l;
        q[i].r=r;
        q[i].idx=i;
    }
    sort(q,q+m,cmp);
    ll curr_l=0,curr_r=-1;
    ll ans=0;
    vector<ll>v(N);
    for(i=0;i<m;i++)
    {
        l=q[i].l;
        r=q[i].r;
        l--;
        r--;
        while(curr_r<r)
        {
            curr_r++;
            ans+=ar[curr_r];
        }
        while(curr_r>r)
        {
            ans-=ar[curr_r];
            curr_r--;
        }
        while(curr_l<l)
        {
            ans-=ar[curr_l];
            curr_l++;
        }
        while(curr_l>l)
        {
            curr_l--;
            ans+=ar[curr_l];
        }
        v[q[i].idx]=ans;
    }
    for(i=0;i<m;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}


