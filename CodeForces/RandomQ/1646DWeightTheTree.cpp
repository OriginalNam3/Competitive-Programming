// Problem: D. Weight the Tree
// Contest: Codeforces - Codeforces Round #774 (Div. 2)
// URL: https://codeforces.com/contest/1646/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (int x: a)

#define maxn 200001

vi p(maxn);
pair<int, int> dp[maxn][2];
vector<vi> t(maxn, vi());

void dfs(int u) {
	// dfs for dp of good or not
	// make the sum (second of pair) negative so max gets the smallest sum
	dp[u][0].f = 0; dp[u][0].s = -1; dp[u][1].f = 1; dp[u][1].s = -t[u].size();
	for (int v: t[u]) {
		if (v == p[u]) continue;
		dfs(v);
		pi maxv = max(dp[v][0], dp[v][1]);
		dp[u][0].f += maxv.f;
		dp[u][0].s += maxv.s;
		// if (dp[v][0].f > dp[v][1].f) {
			// dp[u][0].f += dp[v][0].f;
			// dp[u][0].s += d[v][0].s;
		// }
		// if (dp[v][0].f < dp[v][1].f) {
			// dp[u][0].f += dp[v][1].f;
			// dp[u][0].s += dp[v][1].s;
		// }
		// if (dp[v][0].f == dp[v][1].f) {
			// dp[u][0].f = dp[v][0].f;
			// dp[u][0].s = max(dp[v][0].s, dp[v][1].s);
		// }
		dp[u][1].f += dp[v][0].f;
		dp[u][1].s += dp[v][0].s;
	}
	// cout << u << " " << dp[u][0].f << " " << dp[u][0].s << " " << dp[u][1].f << " " << dp[u][1].s << "\n";
}

int main () {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    fr(i, 0, n-1) {
    	int u, v;
    	cin >> u >> v;
    	t[u].pb(v);
    	t[v].pb(u);
    }
    if (n == 2) {
    	cout << "2 2\n1 1";
    	return 0;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	for (int v: t[u]) {
    		if (v == p[u]) continue;
    		p[v] = u;
    		q.push(v);
    	}
    }
    dfs(1);

    queue<pair<pi, int> > b;
    pi ans = max(dp[1][0], dp[1][1]);
    cout << ans.f << " " << -ans.s << "\n";
    b.push(mp(ans, 1));
    vb gd(n + 1);
    while (!b.empty()) {
    	pi mv = b.front().f;
    	int u = b.front().s;
    	b.pop();
    	// cout << u << "\n";
    	if (mv == dp[u][0]) {
    		gd[u] = 0;
    		for (int v: t[u]) {
    			if (v == p[u]) continue;
    			b.push(mp(max(dp[v][0], dp[v][1]), v));
    		}
    	}
    	else {
    		gd[u] = 1;
    		for (int v: t[u]) {
    			if (v == p[u]) continue;
    			b.push(mp(dp[v][0], v));
    		}
    	}
    }
    
    fr (i, 1, n + 1) {
    	if (gd[i]) cout << t[i].size() << " ";
    	else cout << "1 ";
    }
}
