// Problem: E. MinOr Tree
// Contest: Codeforces - 11-5-2022 Evening
// URL: https://codeforces.com/problemset/problem/1624/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-05-11 18:48:18
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

vector<int> point, sz;
void setn(int n){
	point.assign(n, -1);
	sz.assign(n, 1);
}
int find(int u){
	if (point[u] == -1) return u;
	return find(point[u]);
}
void join(int u, int v){
	// u = find(u); v = find(v);
	// if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	point[v] = u;
	sz[u] += sz[v];
}

typedef array<int, 3> qq;
qq mt(int a, int b, int c){
	qq e = {a, b, c};
	return e;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	vector<qq> e;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		e.pb(mt(w, u, v));
	}
	sor(e);

	int ans = 0;
	for (int bit = (1 << 30); bit >= 1; bit /= 2){
		setn(n);
		
		int cnt = 0, cur = ans + bit;
		// debug(cur)
		for (int i = 0; i < m && cnt < n-1; i++){
			int x = e[i][0] & cur;
			// debug(x)
			if (x == 0){
				int u = find(e[i][1]), v = find(e[i][2]);
				// debug(u) debug(v)
				if (u == v) continue;
				join(u, v);
				cnt++;
			}
		}
		// debug(cnt);
		if (cnt == n-1){
			ans += bit;
		}
	}
	
	ans ^= INT_MAX;
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
