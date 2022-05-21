// Problem: D. Maximum Distributed Tree
// Contest: Codeforces - Codeforces Round #665 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1401/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-17 11:46:22
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}


const int N = 1e5 + 5;
int n;
vector<vector<int > > g;
vector<int> siz(N);
vector<ll> cnt;

void dfs(int u, int parent){
	siz[u] = 1;
	for (int v: g[u]){
		if (v == parent) continue;
		dfs(v, u);
		ll ncnt = 1LL * (n - siz[v]) * siz[v];
		cnt.pb(ncnt);
		siz[u] += siz[v];
	}
}

void solve(){
	cin >> n;
	g.assign(n, vector<int > ());
	for (int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	cnt.clear();
	
	int m; 
	cin >> m;
	vector<int> p(m);
	for (int &x: p) cin >> x;
	
	if (m < n-1){
		for (int i = m; i < n-1; i++){
			p.pb(1);
		}
	}
	sor(p);
	if (m > n-1){
		int cur = 1;
		for (int i = m-1; i >= n-2; i--){
			cur = mul(cur, p[i]);
		}
		p.resize(n - 2);
		p.pb(cur);
	}
	
	dfs(0, 0);
	
	sor(cnt);
	// vdebug(p) vdebug(cnt)
	int ans = 0;
	for (int i = n-2; i >= 0; i--){
		ans = add(ans, mul(cnt[i] % mod, p[i]));
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
