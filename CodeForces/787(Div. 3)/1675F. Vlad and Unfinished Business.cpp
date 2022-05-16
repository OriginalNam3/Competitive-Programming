// Problem: F. Vlad and Unfinished Business
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1675/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-10 21:20:16
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

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<vi> g;
vb vis;
vi dist;
int ans;

void dfs(int u, int p){
	// debug(u)
	for (int v: g[u]){
		if (v == p) continue;
		dist[v] = dist[u] + 1;
		dfs(v, u);
		if (vis[v]) {
			ans += 2;
			vis[u] = 1;
		}
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	int x, y;
	cin >> x >> y;
	x--; y--;
	
	g.assign(n, vi());
	vis.assign(n, 0);
	dist.assign(n, 0);
	
	for (int i = 0; i < k; i++){
		int u; cin >> u; u--;
		vis[u] = 1;
	}
	
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	ans = 0;
	dfs(x, x);
	
	queue<pair<int, int> > q;
	q.push(mp(y, y));
	
	vi d(n);
	
	while (!q.empty()){
		int u = q.front().f, p = q.front().s;
		q.pop();
		if (vis[u]){
			ans += d[u] - dist[u];
			// debug(u) debug(d[u]) debug(dist[u])
			cout << ans << "\n";
			return;
		}
		for (int v: g[u]){
			if (v == p) continue;
			q.push(mp(v, u));
			d[v] = d[u] + 1;
		}
	}
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
