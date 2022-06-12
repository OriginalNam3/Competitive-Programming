// Problem: E - Small d and k
// Contest: AtCoder - AtCoder Beginner Contest 254
// URL: https://atcoder.jp/contests/abc254/tasks/abc254_e
// Memory Limit: 1024 MB
// Time Limit: 3500 ms
// Date & Time: 2022-06-11 23:12:16
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
int d, k;
vector<vector<int> > g;
set<int> vertices;
void dfs(int u, int p){
	vertices.insert(u);
	dbg(u);
	if (++d > k) {
		d--;
		return;
	}
	for (int v: g[u]){
		if (v == p) continue;
		dfs(v, u);
	}
	d--;
}

void solve(){
	int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    dbg(g);
    
    int q; cin >> q;
    for (int rep = 0; rep < q; rep++){
    	int x;
    	cin >> x >> k;
    	int ans = 0;
    	dfs(x, x);
    	while (!vertices.empty()){
    		ans += *vertices.begin();
    		vertices.erase(vertices.begin());
    	}
    	cout << ans << "\n";
    }
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
