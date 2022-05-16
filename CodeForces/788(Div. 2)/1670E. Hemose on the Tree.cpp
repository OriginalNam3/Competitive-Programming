// Problem: E. Hemose on the Tree
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-16 12:15:55
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

const int N = 3e5 + 5;

int n, cnt;
vector<int> edges(N), ans(N);
vector<vector<pair<int, int> > > g;

void dfs(int u, int p, bool b){
	for (pair<int, int> vi: g[u]){
		int v = vi.f, i = vi.s;
		if (v == p) continue;
		if (b){
			edges[i] = n + cnt;
			ans[v] = cnt;
		}
		else{
			edges[i] = cnt;
			ans[v] = n + cnt;
		}
		cnt++;
		dfs(v, u, !b);
	}
}

void solve(){
	cin >> n;
	n = (1 << n);
	g.assign(n, vector<pair<int, int> > ());
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	cnt = 2;
	for (int u = 0; u < n; u++){
		if (g[u].size() == 1){
			cout << u + 1 << "\n";
			ans[u] = 1;
			edges[g[u][0].s] = n + 1;
			ans[g[u][0].f] = n;
			dfs(g[u][0].f, u, 0);
			break;
		}
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n-1; i++){
		cout << edges[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
