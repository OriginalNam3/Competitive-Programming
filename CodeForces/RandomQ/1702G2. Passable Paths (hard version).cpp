// Problem: G2. Passable Paths (hard version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1702/G2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-07-20 23:56:34
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

int n, LOG;

vector<vector<int> > g, up;
vector<int> depth;

void dfs(int u, int p){
	for (int v: g[u]){
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		up[v][0] = u;
		dfs(v, u);
	}
}

int lca(int a, int b){
	if (depth[b] < depth[a]) swap(a, b);
	
	int d = depth[b] - depth[a];
	for (int i = 0; i < LOG; i++){
		if (d & (1 << i)){
			b = up[b][i];
		}
	}
	
	if (a == b) return a;
	
	for (int i = LOG - 1; i >= 0; i--){
		if (up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	
	return up[a][0];
}

void solve(){
	cin >> n;
	LOG = __lg(n) + 1;
	g.assign(n, vector<int>());
	up.assign(n, vector<int>(LOG));
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	depth.assign(n, 0);
	dfs(0, 0);
	for (int i = 1; i < LOG; i++){
		for (int u = 0; u < n; u++){
			up[u][i] = up[up[u][i-1]][i-1];
		}
	}
	
	int q;
	cin >> q;
	while (q--){
		int k;
		cin >> k;
		vector<int> p(k);
		for (int &x: p){
			cin >> x;
			x--;
		}
		
		int mxd = -1, mx;
		for (int x: p){
			if (depth[x] > mxd){
				mxd = depth[x];
				mx = x;
			}
		}
		
		vector<bool> c(k);
		int smx = -1;
		mxd = -1;
		for (int i = 0; i < k; i++){
			if (lca(p[i], mx) == p[i]){
				c[i] = 1;
			}
			else if (depth[p[i]] > mxd){
				mxd = depth[p[i]];
				smx = p[i];
			}
		}
		
		bool ok = true;
		if (smx != -1){
			int mn = lca(mx, smx);
			dbg(mn);
			for (int i = 0; i < k && ok; i++){
				if (c[i]){
					if (lca(p[i], mn) != mn){
						ok = false;
					}
				}
				else if (lca(p[i], smx) != p[i] || lca(p[i], mn) != mn){
					ok = false;
				}
			}
		}
		
		cout << (ok ? "YES\n": "NO\n");
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
