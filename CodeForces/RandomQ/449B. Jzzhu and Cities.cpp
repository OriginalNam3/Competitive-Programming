// Problem: B. Jzzhu and Cities
// Contest: Codeforces - Codeforces Round #257 (Div. 1)
// URL: https://codeforces.com/problemset/problem/449/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-07-06 16:52:55
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	vector<ll> d(n, LLONG_MAX), t(n, -1);
	vector<vector<pair<int, int> > > g(n, vector<pair<int, int> >());
	
	for (int i = 0; i < m; i++){
		int u, v, x;
		cin >> u >> v >> x;
		u--; v--;
		g[u].pb(make_pair(v, x));
		g[v].pb(make_pair(u, x));
	}
	
	for (int i = 0; i < k; i++){
		int s, y;
		cin >> s >> y;
		s--;
		if (t[s] != -1) ans++;
		if (t[s] == -1 || t[s] > y) t[s] = y;
	}
	
	set<pair<ll, int> > q;
	q.insert(make_pair(0LL, 0));
	d[0] = 0;
	while (!q.empty()){
		ll w = q.begin()->first;
		int u = q.begin()->second;
		if (t[u] < w && t[u] != -1) w = t[u];
		q.erase(q.begin());
		dbg(w, u);
		for (auto p: g[u]){
			if (w + p.second < d[p.first]){
				auto it = q.find(make_pair(d[p.first], p.first));
				if (it != q.end()){
					q.erase(it);
				}
				d[p.first] = w + p.second;
				q.insert(make_pair(d[p.first], p.first));
			}
		}
	}
	dbg(t, d);
	for (int i = 1; i < n; i++){
		if (t[i] >= d[i]){
			ans++;
		}
	}
	
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
