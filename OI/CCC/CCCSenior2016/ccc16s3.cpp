// Problem: S3 - Phonomenal Reviews
// Contest: DMOJ - CCC '16
// URL: https://dmoj.ca/problem/ccc16s3
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-11-02 20:03:24
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

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}
vector<vector<int> > g, ng;
int mx;
vector<bool> ok;

void dfs(int u, int p){
	for (int v: ng[u]){
		if (v == p) continue;
		dfs(v, u);
		if (ok[v]) ok[u] = 1;
	}
	return;
}

int find(int u, int p){
	int mx1 = 0, mx2 = 0;
	for (int v: g[u]){
		if (v == p) continue;
		int x = find(v, u);
		if (x > mx1) mx1 = x;
		else if (x > mx2) mx2 = x;
	}
	mx = max(mx1 + mx2);
	dbg(u, mx1, mx2);
	return mx1 + 1;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<bool> pho(n);
	ok.assign(n, 0);
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		pho[x] = 1;
		ok[x] = 1;
	}
	
	ng.assign(n, vector<int>());
	
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		ng[a].pb(b);
		ng[b].pb(a);
	}
	
	dfs(x, x);
	g.assign(n, vector<int>());
	for (int i = 0; i < n; i++){
		for (int v: ng[i]) if (ok[v]) g[i].pb(v);
	}
	mx = 0;
	find(x, x);
	int ans = -1;
	for (int i = 0; i < n; i++){
		if (ok[i]) ans++;
	}
	ans *= 2;
	ans -= mx;
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}
