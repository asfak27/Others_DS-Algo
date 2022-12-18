#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  N         100002
void helper(vector<ll> &a,vector<vector<ll>>&ans,ll x)
{
    if(x==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(ll i=x;i<a.size();i++)
    {
        if(i!=x && a[i]==a[x])continue;
        swap(a[i],a[x]);
        helper(a,ans,x+1);
    }
    return;
}

vector<vector<ll>>permute(vector<ll>v)
{
    sort(v.begin(),v.end());
    vector<vector<ll>>ans;
    helper(v,ans,0);
    return ans;
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
    vector<vector<ll>>v;
    v=permute(a);
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
