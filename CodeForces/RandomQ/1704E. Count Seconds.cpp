// Problem: E. Count Seconds
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-11-04 20:42:55
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 998244353;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<int> res;
vector<vector<int> > f;
vector<ll> a;

void dfs(int u){
	if (res[u] != -1) return;
	res[u] = a[u];
	for (int v: f[u]){
		dfs(v);
		res[u] = add(res[u], res[v]);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	a.assign(n, 0);
	for (ll &x: a) cin >> x;
	
	vector<vector<int> > g(n);
	f.assign(n, vector<int>());
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		f[b].pb(a);
	}
	
	vector<ll> b(n);
	for (int cnt = 0; cnt < n; cnt++){
		bool ok = 1;
		for (int i = 0; i < n; i++){
			if (a[i] > 0) ok = 0;
			b[i] = max(0LL, a[i] - 1);
		}
		if (ok){
			cout << cnt << "\n";
			return;
		}
		for (int i = 0; i < n; i++){
			for (int j: g[i]){
				if (a[i] > 0) b[j] += 1;
			}
		}
		swap(a, b);
	}
	dbg(a);
	int root;
	for (int i = 0; i < n; i++) if (g[i].size() == 0) root = i;
	
	res.assign(n, -1);
	dfs(root);
	
	cout << add(n, res[root]) << "\n";
	
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
