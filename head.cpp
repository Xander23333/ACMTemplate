#include<bits/stdc++.h>
using namespace std;

#define llp(i,x,y) for(int i=x;i<y;++i) // [x,y) x->y
#define REP llp
#define rlp(i,x,y) for(int i=y-1;i>=x;--i)  // [x,y) y->x
#define PER rlp
#define lp(i,x) for(int i=0;i<x;++i) //[0,x）0->x
#define mem(a,x) memset(a,x,sizeof a)
#define endl "\n"

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int,int> pii;
typedef __int128 ull;

#define fi first
#define se second
#define pb push_back

const ll MOD=1e9+7;
const ll N=1e3+50;
const db eps=1e-9;

ll qpower(ll x,ll p){ll ans=1;while(p){if (p&1) ans=ans*x%MOD;p>>=1;x=x*x%MOD;}return ans;}
ll gcd(ll a,ll b){ll x;while(b){x = a%b;a = b;b = x;}return a;}
ll modp(ll x,ll p){return (x%p+p)%p;}
// std::ios::sync_with_stdio(false);
// srand((unsigned)time(NULL));
