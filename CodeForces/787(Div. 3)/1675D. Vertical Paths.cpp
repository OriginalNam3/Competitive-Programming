// Problem: D. Vertical Paths
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-15 20:05:43
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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

vector<vector<int> > g, ans;
vector<int> nxt, dist;

void dfs(int u){
	for (int v: g[u]){
		dfs(v);
		if (dist[v] >= dist[u]){
			nxt[u] = v;
			dist[u] = dist[v] + 1;
		}
	}
}

int recover(int u){
	if (dist[u] != -1){
		vector<int> path(1, u+1);
		int cur = u;
		while (cur != nxt[cur]){
			cur = nxt[cur];
			dist[cur] = -1;
			path.pb(cur + 1);
		}
		ans.pb(path);
	}
	for (int v: g[u]){
		recover(v);
	}
}

void solve(){
	int n;
	cin >> n;
	g.assign(n, vector<int>());
	nxt.assign(n, 0);
	dist.assign(n, 0);
	ans.clear();
	
	int root;
	for (int u = 0; u < n; u++){
		nxt[u] = u;
		int p; cin >> p; p--;
		if (p != u) g[p].pb(u);
		else root = u;
	}
	
	dfs(root);
	recover(root);
	cout << ans.size() << "\n";
	for (auto path: ans){
		cout << path.size() << "\n";
		for (int u: path){
			cout << u << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
