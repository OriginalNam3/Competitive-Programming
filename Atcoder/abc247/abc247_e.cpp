// Problem: E - Max Min
// Contest: AtCoder - AtCoder Beginner Contest 247
// URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-04 22:00:22
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    each(x, a) cin >> x;
    
    vector<vi> v(n+1, vi(4));
    v[n][0] = v[n][1] = v[n][2] = v[n][3] = n;
    
    rofn(i, 0, n){
    	v[i][0] = v[i+1][0];
    	v[i][1] = v[i+1][1];
    	v[i][2] = v[i+1][2];
    	v[i][3] = v[i+1][3];
    	if (a[i] == x) v[i][0] = i;
    	if (a[i] == y) v[i][1] = i;
    	if (a[i] > x) v[i][2] = i;
    	if (a[i] < y) v[i][3] = i;
    }
    
    ll ans = 0;
    forn(i, 0, n){
    	ans += max(0, min(v[i][2], v[i][3]) - max(v[i][0], v[i][1]));
    }
    
    cout << ans;
}
