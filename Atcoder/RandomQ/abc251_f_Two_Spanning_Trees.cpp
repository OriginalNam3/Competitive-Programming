// Problem: F - Two Spanning Trees
// Contest: AtCoder - Panasonic Programming Contest 2022(AtCoder Beginner Contest 251)
// URL: https://atcoder.jp/contests/abc251/tasks/abc251_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 14:49:14
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

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
#define pb emplace_back

#ifdef ORIGINAL_LOCAL
#include <bits/debug.h>
#else
#define dbg(...) 42
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

vector<vector<int> > g;
vector<pair<int, int> > t1, t2;
vector<bool> used;

void dfs(int u){
	for (int v: g[u]){
		if (!used[v]){
			used[v] = 1;
			cout << u + 1 << " " << v + 1 << "\n";
			dfs(v);
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	g.assign(n, vector<int>());
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	used.assign(n, 0);
	used[0] = 1;
	dfs(0);
	
	used.assign(n, 0);
	used[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (int v: g[u]){
			if (!used[v]){
				used[v] = 1;
				cout << u + 1 << " " << v + 1 << "\n";
				q.push(v);
			}
		}
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
