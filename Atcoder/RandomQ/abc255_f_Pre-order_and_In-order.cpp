// Problem: F - Pre-order and In-order
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 20:48:53
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

int n, cur;
bool ok;
vector<int> pre, in, ind;
vector<bool> used;
vector<pair<int, int> > ans;

void dfs(int i, int l, int r){
	dbg(i, l, r, cur);
	used[i] = 1;
	
	if (i != l) {
		if (used[ind[pre[cur]]]) cur++;
		if (cur == n) return;
		if (ind[pre[cur]] >= l && ind[pre[cur]] < i){
			ans[in[i] - 1].f = pre[cur];
			dfs(ind[pre[cur]], l, i - 1);
		}
	}
	if (i != r){
		if (used[ind[pre[cur]]]) cur++;
		if (cur == n) return;
		if (ind[pre[cur]] > i && ind[pre[cur]] <= r){
			ans[in[i] - 1].s = pre[cur];
			dfs(ind[pre[cur]], i + 1, r);
		}
	}
}

void solve(){
	cin >> n;
	pre.assign(n, 0);
	in.assign(n, 0);
	ind.assign(n + 1, 0);
	for (int &x: pre) cin >> x;
	for (int i = 0; i < n; i++){
		cin >> in[i];
		ind[in[i]] = i;
	}
	if (pre[0] != 1){
		cout << "-1";
		return;
	}
	
	used.assign(n, 0);
	ans.assign(n, pair<int, int> (0, 0));
	ok = true;
	cur = 0;
	dfs(ind[1], 0, n-1);
	for (int i = 0; i < n && ok; i++){
		if (!used[i]) ok = false;
	}
	if (!ok){
		cout << -1;
	}
	else{
		for (auto p: ans) cout << p.f << " " << p.s << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
