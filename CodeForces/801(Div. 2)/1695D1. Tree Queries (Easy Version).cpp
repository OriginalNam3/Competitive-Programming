// Problem: D1. Tree Queries (Easy Version)
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 17:33:38
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

vector<vector<int> > g;
vector<int> ans;

void dfs(int u, int p){
	int cnt = 0;
	for (int v: g[u]){
		if (v == p) continue;
		dfs(v, u);
		if (ans[v] == 0) cnt++;
	}

	for (int v: g[u]){
		if (v == p) continue;
		if (ans[v] > 0){
			ans[u] += ans[v];
		}
	}
	ans[u] += max(0, cnt - 1);
}

void solve(){
	int n;
	cin >> n;
	if (n == 1){
		cout << "0\n"; return;
	}
	
	g.assign(n, vector<int>());
	
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	ans.assign(n, 0);
	int mn = 1;
	for (int u = 0; u < n; u++){
		if (g[u].size() >= 3){
			dfs(u, u);
			mn = ans[u];
			break;
		}
	}
	dbg(ans);
	
	cout << mn << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
