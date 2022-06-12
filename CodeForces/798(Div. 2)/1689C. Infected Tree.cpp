// Problem: C. Infected Tree
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/contest/1689/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-06-10 21:25:39
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

vector<int> siz, dp, p;
vector<vector<int> > g;

void dfs(int u){
	vector<int> mx(2);
	bool cur = 0;
	for (int v: g[u]){
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);
		mx[cur] += dp[v];
		mx[!cur] += siz[v] - 1;
		siz[u] += siz[v];
		cur ^= 1;
	}
	dp[u] = max(mx[0], mx[1]);
}

void solve(){
	int n;
	cin >> n;
	g.assign(n, vector<int>());
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	siz.assign(n, 1);
	dp.assign(n, 0);
	p.assign(n, 0);
	dfs(0);
	
	cout << dp[0] << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
