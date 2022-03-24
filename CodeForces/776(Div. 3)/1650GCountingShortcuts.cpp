// Problem: G. Counting Shortcuts
// Contest: Codeforces - Codeforces Round #776 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1650/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

using pqi = priority_queue<int>;
using pqll = priority_queue<long long>;
using qi = queue<int>;
using qll = queue<long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

const int mod = 1e9 + 7;
vi c;
vi dist;
vector<vector<long long> > dp;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m, s, t;
    	cin >> n >> m;
    	cin >> s >> t;
    	
    	vector<vi> g(n + 2, vi());
    	fr(i, 0, m){
    		int u, v;
    		cin >> u >> v;
    		g[u].pb(v);
    		g[v].pb(u);
    	}
    	
    	dist.assign(n + 1, INT_MAX);
    	dp.assign(2, vector <long long> (n+1));
    	c.assign(n+1, 0);
    	
    	dist[s] = 0;
    	dp[0][s] = 1;
    	c[s] = 1;
    	
    	queue <pair<pi, int> > q;
    	q.push(mp(mp(s, 0), 0));
    	int u, d = 0, cnt = 0, mind = INT_MAX - 2;
    	while (d < mind + 2 && !q.empty()) {
    		u = q.front().f.f; d = q.front().f.s;
    		// cout << u << " " << d << endl;
    		int p = q.front().s;
    		q.pop();
    		if (mind == INT_MAX - 2) {
    			if (u == t) mind = d;
    		}
    		// cout << q.size() << " " << mind << endl;
    		if (u == t && d <= mind + 1) {
    			cnt = (cnt + dp[p][u]) % mod;
    			// cout << u << " " << d << endl;
    			if (cnt > mod) cnt -= mod;
    		}
    		for (int v: g[u]) {
    			dist[v] = min(dist[v], d + 1);
    			if (d <= dist[v]) {
    				dp[d - dist[v] + 1][v] = (dp[d - dist[v] + 1][v] + dp[p][u]) % mod;
    				
    				if (c[v] == 0 || (c[v] == 1 && d ==	dist[v])) {q.push(mp(mp(v, d + 1), c[v]++));}
    			}
    		}
    		// cout << endl;
    	}
    	cout << cnt << "\n";
    }
}
