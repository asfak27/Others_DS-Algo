#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define  fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define  int       long long
#define  ll        long long
#define  mod       1000000007
#define  N         10000002
#define  all(v)    v.begin(),v.end()
#define  maxv(a)   *max_element(all(a))
#define  minv(a)   *min_element(all(a))
#define  sumv(a)    accumulate(all(a),0)
#define rep(i,a,n)  for (ll i=a;i<n;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/(gcd(a,b))
int const N=1e5+6;
ll MOD=1e9+7,fact[N];
const long long inf=(long long)1e18;
const long double PI=3.14159265358979;

/*
vector<ll>v;               // if the subtraction of two number is bigger it will come first then it decrease the order
ll a[N+1],b[N+1];
bool cmp(ll x,ll y)   ///x=first element y=second element
{
    return a[x]-b[x]>a[y]-b[y];     10>9>6>5>4  if(<)4<5<10
}
*/

/*remove element of a vector
 v.erase(std::remove(v.begin(),v.end(),v[i]),v.end());
*/
getline(cin,s);
cout<<fixed<<setprecision(12);
///convert string to integer
setprecision(15)
x=stoi(s);
x=stringstream(s);
///convert integer to string
to_string();
vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));
memset(vis,0,sizeof vis);

int dx[]= {-1,0,1,0,-1,-1,1,1};
int dy[]= {0,1,0,-1,-1,1,1,-1};

int dxx[8]                       = {2, 2, -2, -2, 1, 1, -1, -1};
int dyy[8]                       = {1, -1, 1, -1, -2, 2, 2, -2};

int dx[4]                        = {+1,-1,+0,-0};   // down, up, right, left
int dy[4]                        = {+0,-0,+1,-1};

int ddx[6]                          = {-1,-1,0,0,1,1,};
int ddy[6]                          = {-1,0,-1,1,0,1};

int di[8]                         = {1, 1, 1, 0, 0,-1,-1, -1};
int dj[8]                         = {1, 0,-1, 1,-1, 1, 0, -1};
///Decimal to Binary
string decToBinary(int n)
{
    string s="",t="";
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k&1)s+='1';
        else s+='0';
    }
    bool f=false;
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='1')f=true;
        if(f)t+=s[i];
    }
    return t;
}
/// binary to decimal number
ll binaryToDecimal(ll n)
{
    ll num = n;
    ll dec_value = 0;

    ll base = 1;

    ll temp = num;
    while (temp)
    {
        ll last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}
/// binary to decimal string
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    ll base = 1;
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
///count 32 bit in array element
ll b[33][n+5];
for(i=0; i<32; i++)
{
    ll c=0;
    for(j=0; j<n; j++)
    {
        if(a[j]&(1<<i))
        {
            c++;
            b[i][j]=c;
        }
        else
        {
            b[i][j]=c;
        }
    }
}
///Trailing_Zero
ll Trailing_Zero(ll n)
{
    ll zero=0;
    for(ll i=5; i<=n; i*=5)
    {
        zero+=(n/i);
    }
    return zero;
}

///perfect_square
bool perfect_square(ll val)
{
    double s=sqrt(val);
    ll i=sqrt(val);
    if(s==i)return true;
    else return false;
}
bool perfect_square(ll val)
{
    ll sq=sqrt(val);
    if(sq*sq==val)return true;
    return false;
}
///check prime
bool prime[N];
bool isPrime(ll n)
{
    if(n<=1)return false;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
///gcd
ll gcd(ll x,ll y)
{
    if(x==0)return y;
    else return gcd(y%x,x);
}
///lcm;
ll lcm(ll x,ll y)
{
    return x*y/gcd(x,y);
}

///combination nCr
ll nCr(ll n, ll r)
{
    ll ans=1;
    for(int i=1; i<=r; i++)
    {
        ans=ans*(n-r+i)/i;
    }
    return (long long)(ans);
}

///sieve of eratosthenes
void sieve(vector<ll> &v)
{
    memset(prime,true,N);
    prime[0]=prime[1]=false;
    for(ll i=2; i*i<N; i++)
    {
        if(prime[i]==true)
        {
            for(ll j=i+i; j<N; j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(ll i=0; i<N; i++)
    {
        if(prime[i]==true)
        {
            v.push_back(i);
        }
    }
}
void count_divisor()
{
    divisor[1]=1;
    for(ll i=2; i<=N; i++)
    {
        divisor[i]++;
        for(ll j=i; j<=N; j+=i)
        {
            divisor[j]++;
        }
    }
}
void sieve()
{
    memset(isPrime,1,sizeof(isPrime));
    for( int i = 3 ; i*i <= N ; i +=2 )
    {
        for( int j = i * i ; j <= N ; j += (2*i) )
        {
            isPrime[ j ] = 0 ;
        }
    }

    prime.PB(2);
    for(int i=3; i<=N; i+=2) if(isPrime[i]) prime.PB(i);

}
///Euler's Totient Function ==Co-Prime
ll a[N+1];
void Co-Prime(ll n)
{
    ll i,j;
    a[0] = 0;
    a[1] = 1;
    for(i=2; i<=N; i++)
    {
        a[i]=i;
    }
    for(i=2; i<=N; i++)
    {
        if(a[i]==i)
        {
            for(j=i; j<=N; j+=i)
            {
                a[j]-=a[j]/i;
            }
        }
    }
    return a[n];
}

///count sum & divisor
///kon number er divisor->oi number er prine factor er power+1 er multiple 2^3 3^2 5^2->(3+1)*(2+1)*(2+1)=all divisor
void countDivisor(vector<ll> &v,ll n)
{

    for(ll i=1; i*i<=n; i++)
    {
        if(i*i==n)
        {
            v.push_back(i);
        }
        else if(n%i==0)
        {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
}
///count all divisor 1 to n
int a[N];
ll cheak(ll n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            a[j]++;
        }
    }
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ans+=a[i];
    }
    return ans;
}
///primeFactorization
void primeFactorization(vector<ll> &v,ll n)
{
    while(n%2==0)
    {
        v.push_back(2);
        n/=2;
    }
    for(ll i=3; i*i<=n; i=i+2)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if(n>2)
    {
        v.push_back(n);
    }
}
///all permutation string
sort(s.begin(),s.end());
vector<string>v;
do
{
    v.push_back(s);
}
while(next_permutation(s.begin(),s.end()));


///Palindrome check string
bool isPalindrome(string s)
{
    int l=0;
    int h=s.size()-1;
    while(l<h)
    {
        if(s[l++]!=s[h--])
        {
            return false;
        }
    }
    return true;

}
int dp1[2001][2001];
bool isPalindrome(string& s, int i, int j)
{
    if (i >= j) return true;
    if (dp1[i][j] != -1) return dp1[i][j];
    if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
    return dp1[i][j] = false;
}
for(int i = n-1 ; i >= 0 ; i--)
{
    for(int j = i ; j < n ; j++)
    {
        if(i == j)
        {
            p[i][j] = true ;
        }
        else if((j-i == 1) && (s[i] == s[j]))
        {
            p[i][j] = true ;
        }
        else if(s[i] == s[j] && p[i+1][j-1])
        {
            p[i][j] = true ;
        }
    }
}
///number to string convert
string numbertostring(ll n)
{
    string s="";
    ll r;
    while(n!=0)
    {
        r=n%10;
        if(r==0)s+='0';
        else s+=char(r+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
///stringTointeger
ll stringTointeger(string str)
{
    ll temp = 0;
    for (ll i = 0; i < str.length(); i++)
    {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
//vector<pair<string,int> >v
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
{
    return (a.second < b.second);
}
//vector<pair<int,int> >v
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);//second increasing order
}

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.first-a.second < b.first-b.second);///decresing order minus
}

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.first != b.first) return a.first > b.first;
    else
        return a.second > b.second;
}
///string to int
///x=s[i]-48;
///x=s[i]-'0'
///transform(s.begin(), s.end(), s.begin(), ::tolower);

///sumofDigit
ll sumofDigit(ll n)
{
    ll sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
///or sum of all subset
class Solution
{
public:
    int subsetXORSum(vector<int>& a)
    {
        int i, j, m, res = 0, n = a.size();
        for (m = 0; m < (1<<n); ++m)  //1<<n = number of subset of n size array==2^(n-1)
        {
            j = 0;
            for (i = 0; i < n; ++i)
                if (m & (1<<i)) j ^= a[i]//sum+=a[i];
                                         res += j;
        }

        return res;
    }
};
///calculate a^b
ll fastPower(ll a,ll b)
{
    if(b==0)return 1;
    else return a*fastPower(a,b-1);
}
///calculate (x^p)%m
ll fastpowerMOD(ll x,ll p,ll m)
{
    if (p == 1) return x;
    if (p % 2 == 0)
        return 	fastpowerMOD((x%m)*(x%m), p / 2, m) % m;
    else
        return ((fastpowerMOD((x%m)*(x%m), p / 2, m) % m) *(x%m)) % m;
}
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
//vector<pair<string,int> >v
bool sortbysec(const pair<string,int> &a,const pair<string,int> &b)
{
    return (a.second < b.second);
}
//vector<pair<int,int> >v
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}



#include<bits/stdc++.h>
#include<stdio.h>
#include<unordered_set>

using namespace std;


//.....................Keywords..................>
#define ll              long long
#define lli             long long int
#define ull             unsigned long long
#define ld              long double
#define vi              vector<int>
#define vll             vector<ll>
#define pii             pair<int,int>
#define vii             vector<pii>
#define pii             pair<int,int>
#define tiii            tuple<int,int,int>

#define pb              push_back
#define F               first
#define S               second
#define mp              make_pair
#define I               insert
#define endl            "\n"
#define pob             pop_back
#define inf             1e9+9
#define setpoint(x)     setprecision(x)<<fixed

const int         N   = (int) 2e5 + 5;//100000
const int         MxN = (int) 1e6 + 5;
const int         MOD = (int) 1e9 + 7;
const int         INF = (int) 1e9 + 7;
const double      EPS = (double) 1e-9;
const long double PI  = 3.14159265358979;
const lli         M   =  1e6+2;  //998244353;

///.....................function..................>

#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loop(a,b)       for(ll i=a;i<b;i++)
#define loopr(a,b)      for(ll i=a-1;i>=b;i--)
#define Ssort(a)         sort(a.begin(),a.end())
//sort(a,a+3,greater<ll>());
#define rsort(v)        sort(v.rbegin(),v.rend())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define rev_sort(a)     sort(a.begin(),a.end(),greater<int>())
//#define reverse(a)      reverse(a.begin(),a.end())
#define sum_arr(a,n,s)  accumulate(a,a+n,s)
#define bin_one(n)      __builtin_popcount(n)
#define str(a)          a.begin(),a.end()
#define mem(a,b)        memset(a, b, sizeof(a) )
#define max_ele(a,n)    *max_element(a,a+n)
#define min_ele(a,n)    *min_element(a,a+n)
#define print(a,n)      for(ll i=0;i<n;i++)cout<<a<<" ";
#define pll             pair <ll, ll>
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"

vector<int> kmp(string s)
{
    //reverse(s.begin(),s.end());
    string ss=s;
    reverse(ss.begin(),ss.end());
    s+="$"+ss;
    int n= s.size();
    vector<int>lps(n,0);
    int i=1,idx=0;
    while(i<n)
    {
        if(s[i]==s[idx])
        {
            lps[i]=idx+1;
            i++;
            idx++;
        }
        else
        {
            if(idx)idx=lps[idx-1];
            else lps[i]=idx,i++;
        }
    }
    return lps;
}
bool ispalin(string& s,int k)
{
    int l=0,r=s.size()-1;
    //if(abs(k-l)<abs(k-r))

    while(l<r)
    {
        if(l==k)l++;
        else if(r==k)r--;
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}
void solve()
{
    lli n,m,mx2=0,ans = 0,i,j,sum=0,mn=100000000,l,k,mx=0,q,x=0,y=1,res=0,p,r;
    string s;
    cin>>s;
    n=s.size();
    l=0,r=n-1;
    int ff=0;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            if(ff==0)
            {
                if(s[l]==s[r-1])r--;
                else if(s[l+1]==s[r])l++;
                else
                {
                    cout<<"NO"<<endl;
                    return;
                }
                ff=1;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }

        }
        l++;
        r--;

    }
    cout<<"YES"<<endl;


}

int main()
{
    // fastio();

    ll tc;
    tc=1;
    cin>>tc;
    // seive();

    while(tc--)solve();


}
