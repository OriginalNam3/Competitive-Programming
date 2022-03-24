// Problem: C. Not Assigning
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
#define fe(x, a) for (auto& x: a)

vector<vpi> a;
vi o;
int b[2] = {2, 3};
bool ok;

bool dfs(int u, int p, int i){
	int c = 0;
	for (pi v: a[u]) {
		if (v.f == p) continue;
		o[v.s] = b[i];
		dfs(v.f, u, !i);
		c++;
	} 
	// cout << c << " " << u << " " << p << "\n";
	if (c > 1) ok = false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	a.assign(n + 5, vpi());
    	o.assign(n+4, 0);
    	fr(i, 0, n-1){
    		int u, v;
    		cin >> u >> v;
    		a[u].pb(mp(v, i));
    		a[v].pb(mp(u, i));
    	}
    	int i = 1;
    	while (a[i].size() != 1) i++;
    	ok = true;
    	dfs (i, i, 0);
    	if (!ok){
    		cout << -1 << "\n";
    		continue;
    	}
    	fr(i, 0, n-1){
    		cout << o[i] << " ";
    	}
    	cout << "\n";
    }
}
