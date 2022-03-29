// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round #20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
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

const ll INF = LLONG_MAX;

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // cout << INF << "\n";
    vector<vpi> g(n);
    fr(i, 0, m){
    	int a, b, w;
    	cin >> a >> b >> w;
    	a--; b--;
    	g[a].pb(mp(b, w)); g[b].pb(mp(a, w));
    }
    ll dist[n];
    int prev[n];
    fr(i, 0, n){
    	dist[i] = INF;
    	prev[i] = -1;
    }
    dist[0] = 0;
    priority_queue<pair<int, int> > q;
    q.push(mp(0, 0));
    while (!q.empty()){
    	int u = q.top().s;
    	q.pop();
    	for (auto p: g[u]){
    		ll nd = dist[u] + p.s;
    		if (nd < dist[p.f]){
    			dist[p.f] = nd;
    			prev[p.f] = u;
    			q.push(mp(-dist[p.f], p.f));
    		}
    	}
    }
    if (prev[n-1] == -1){
    	cout << -1;
    	return 0;
    }
    int u = n-1;
    vi ans;
    ans.pb(n);
    while (u != 0){
    	u = prev[u];
    	ans.pb(u + 1);
    }
    rf(i, 0, ans.size()){
    	cout << ans[i] << " ";
    }
}
