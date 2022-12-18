#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  N         100002
void solve()
{
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,y,d,r,x;
    string s;
    cin>>s;
    ll c=0;
    vector<string>v;
    sort(s.begin(),s.end());
    do
    {
        x=stoi(s);
        if(x%7==0)c++;
    }
    while(next_permutation(s.begin(),s.end()));
    cout<<c<<endl;
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


