// Problem: E - Road Reduction
// Contest: AtCoder - AtCoder Beginner Contest 252
// URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-17 15:53:50
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

typedef array<int, 3> qq;
qq mt(int a, int b, int c){
	qq e = {a, b, c};
	return e;
}

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<qq> > g(n, vector<qq>());
	
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb(mt(b, c, i));
		g[b].pb(mt(a, c, i));
	}
	
	set<pair<ll, int> > q;
	vector<int> ans(n);
	vector<ll> bst(n, LLONG_MAX);
	q.insert(mp(0LL, 0));
	while (!q.empty()){
		ll d = q.begin()->f;
		int u = q.begin()->s;
		q.erase(q.begin());
		for (qq t: g[u]){
			if (d + t[1] < bst[t[0]]){
				if (bst[t[0]] != LLONG_MAX){
					auto it = q.find(mp(bst[t[0]], t[0]));
					q.erase(it);
				}
				bst[t[0]] = d + t[1];
				ans[t[0]] = t[2];
				q.insert(mp(bst[t[0]], t[0]));
			}
		}
	}
	for (int i = 1; i < n; i++) cout << ans[i] + 1 << " ";
	
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
