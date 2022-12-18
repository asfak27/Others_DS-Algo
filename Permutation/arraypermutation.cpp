#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  N         100002
vector<vector<ll>>v;
void permute(vector<ll> &a,ll x)
{
    if(x==a.size())
    {
        v.push_back(a);
        return;
    }
    for(ll i=x;i<a.size();i++)
    {
        swap(a[i],a[x]);
        permute(a,x+1);
        swap(a[i],a[x]);
    }
    return;
}
void solve()
{
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y,d,r;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    permute(a,0);
    /*sort(a.begin(),a.end());
    do{
        v.push_back(a);
    }while(next_permutation(a.begin(),a.end()));*/

    for(i=0;i<v.size();i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    fast
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
//life began at the end of your comfort zone...

