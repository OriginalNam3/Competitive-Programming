// Problem: B. Zero Tree
// Contest: Codeforces - Codeforces Round #168 (Div. 1)
// URL: https://codeforces.com/problemset/problem/274/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-07 19:27:10
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

vector<vi> g;
vll incr, decr;
vi v;

void dfs(int u, int p){
	each(v, g[u]){
		if (v == p) continue;
		dfs(v, u);
		incr[u] = max(incr[u], incr[v]);
		decr[u] = min(decr[u], decr[v]);
	}
	v[u] += incr[u] + decr[u];
	if (v[u] > 0){
		decr[u] += -v[u];
	}
	if (v[u] < 0){
		incr[u] += -v[u];
	}
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    g.assign(n, vi());
    incr.assign(n, 0);
    decr.assign(n, 0);
    v.assign(n, 0);
    
    rep(n-1){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    
    each(x, v) cin >> x;
    
    dfs(0, 0);
    // vdebug(incr) vdebug(decr)
    cout << incr[0] - decr[0];
}
