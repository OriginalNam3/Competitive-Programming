// Problem: E. Tree Shuffling
// Contest: Codeforces - Codeforces Round #646 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1363/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-04 14:50:00
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

const int N = 2e5 + 2;

vector<vi> d, g; // d: 0 = zeroes, 1 = ones, 2 = zeroes wanted, 3 = ones wanted
vi p, a;
vll c;

void dfs(int u, int mn){
	// debug(u)
	mn = min(mn, a[u]);
	// vdebug(g[u])
	each(v, g[u]){
		if (v == p[u]) continue;
		p[v] = u; 
		dfs(v, mn);
		forn(i, 0, 4) d[u][i] += d[v][i];
		c[u] += c[v];
	}
	int z = min(d[u][0], d[u][2]), o = min(d[u][1], d[u][3]);
	c[u] += 1LL * mn * (z + o);
	d[u][0] -= z;
	d[u][2] -= z;
	d[u][1] -= o;
	d[u][3] -= o;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    p.assign(n, 0); a.assign(n, 0);
    d.assign(n, vi(4));
    g.assign(n, vi());
    c.assign(n, 0);
    
    vi cnt(4);
    forn(i, 0, n){
    	int b, c;
    	cin >> a[i] >> b >> c;
    	if (b ^ c) {d[i][b]++; d[i][2 + c]++;}
    	cnt[b]++; cnt[2 + c]++;
    }
    if (cnt[0] != cnt[2] || cnt[1] != cnt[3]){
    	cout << "-1"; return 0;
    }
    
    forn(i, 0, n-1){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v); g[v].pb(u);
    	// vdebug(g[u])
    }
    
    dfs(0, INT_MAX);
    cout << c[0];
}
