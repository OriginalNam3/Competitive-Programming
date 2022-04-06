// Problem: E. Equal Tree Sums
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

vector<vi> g;
vb a;
vi ans, p;

void solve(){
	int n;
	cin >> n;
	g.assign(n, vi());
	ans.assign(n, 0);
	fr(i, 0, n-1){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		ans[u]++;
		ans[v]++;
	}
	a.assign(n, 0);
	p.assign(n, -1);
	queue<pair<int, bool> > q;
	q.push(mp(0, 0));
	while (!q.empty()){
		int u = q.front().f;
		bool x = q.front().s;
		q.pop();
		a[u] = x;
		each(v, g[u]){
			if (v == p[u]) continue;
			p[v] = u;
			q.push(mp(v, !x));
		}
	}
	fr(i, 0, n){
		if (a[i]) cout << ans[i] << " ";
		else cout << -ans[i] << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
