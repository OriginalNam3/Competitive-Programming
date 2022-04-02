// Problem: C. Kefa and Park
// Contest: Codeforces - Codeforces Round #321 (Div. 2)
// URL: https://codeforces.com/problemset/problem/580/C
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
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi cat(n);
    forn(i, 0, n){
    	cin >> cat[i];
    }
    vector<vi> t(n, vi());
    rep(n-1){
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	t[u].pb(v);
    	t[v].pb(u);
    }
    
    queue<pi> q;
    vi p(n);
    q.push(mp(0, 0));
    int ans = 0;
    while (!q.empty()){
    	int u = q.front().f, c = q.front().s;
    	// cout << u << " " << c << "\n";
    	q.pop();
    	if (cat[u]) c++;
    	else c = 0;
    	if (c > m){
    		continue;
    	}
    	int cnt = 0;
    	for (int v: t[u]){
    		// cout << v << "\n";
    		if (v == p[u]) continue;
    		p[v] = u;
    		q.push(mp(v, c));
    		cnt++;
    	}
    	if (cnt == 0) ans++;
    }
    cout << ans;
}
