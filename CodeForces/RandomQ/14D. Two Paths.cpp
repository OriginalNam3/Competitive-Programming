// Problem: D. Two Paths
// Contest: Codeforces - 27-03-2022 TCP (Graphs)
// URL: https://codeforces.com/problemset/problem/14/D
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Date & Time: 2022-04-27 18:39:58
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
template<class T> using V = vector<T>;
typedef array<int, 3> qq;

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

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<vi> g;
int subtreemx;

int dfs(int u, int p){
	int mx = 0, smx = 0;
	each(v, g[u]){
		if (v == p) continue;
		int nmx = dfs(v, u);
		if (nmx > mx){
			smx = mx;
			mx = nmx;
		}
		else if (nmx > smx){
			smx = nmx;
		}
	}
	subtreemx = max(subtreemx, mx + 1 + smx);
	return mx + 1;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    g.assign(n, vi());
    
    vpi r(n-1);
    
    forn(i, 0, n-1){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	g[u].pb(v);
    	g[v].pb(u);
    	r[i].f = u;
    	r[i].s = v;
    }
    
    int ans = 0;
    forn(i, 0, n-1){
    	// debug(r[i].f); debug(r[i].s);
    	subtreemx = 0;
    	dfs(r[i].f, r[i].s);
    	int mx1 = subtreemx;
    	subtreemx = 0;
    	dfs(r[i].s, r[i].f);
    	int mx2 = subtreemx;
    	// debug(mx1.f); debug(mx1.s); debug(mx2.f); debug(mx2.s);
    	ans = max(ans, (mx1-1) * (mx2-1));
    }
    
    cout << ans << "\n";
}
