// Problem: E. Minimum Path
// Contest: Codeforces - Educational Codeforces Round 102 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1473/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int main (){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vpi> g(n);
    forn(i, 0, m){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--; v--;
    	g[u].pb(mp(v, w));
    	g[v].pb(mp(u, w));
    }
    set<pair<ll, qq> > q; // weight, {u, added, removed} for dijkstra
    vector<vll> dist(n, vll(4, LLONG_MAX)); // dist[u][2*i+j] where u = vertex, i = whether an edge has been removed, j = whether another edge has been removed
    dist[0][0] = 0;
    qq e = {0, 0, 0};
    q.insert(mp(0, e));
    while (!q.empty()){
    	auto [u, add, rem] = q.begin()->s;
    	q.erase(q.begin());
    	// cout << u << mx << mn << "\n";
    	for (pi p: g[u]){
    		int v = p.f, w = p.s;
    		// cout << v << " " << w << "\n";
    		forn(i, 0, 2-add) forn(j, 0, 2-rem){ // wlog, if add, cannot have add = 1 again
    			// if i: total weight = dist[u][2] + 2*w
    			// if j: total weight = dist[u][1]
    			// if i & j: total weight = dist[u][3] + w
    			// if neither: total weight = dist[u][0] + w
    			if (dist[v][2*(add|i)+(rem|j)] > dist[u][2*add+rem] + (1+i-j)*w){
    				// cout << "FOUND\n";
    				qq e = {v, add|i, rem|j};
    				auto dup = q.find(mp(dist[v][2*(add|i)+(rem|j)], e));
    				if (dup != q.end()) q.erase(dup);
    				dist[v][2*(add|i)+(rem|j)] = dist[u][2*add+rem] + (1+i-j)*w;
    				q.insert(mp(dist[v][2*(add|i)+(rem|j)], e));
    			}
    		}
    	}
    }
    forn(i, 1, n){
    	cout << dist[i][3] << " ";
    }
}
