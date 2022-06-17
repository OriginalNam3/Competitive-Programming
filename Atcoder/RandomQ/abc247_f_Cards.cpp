// Problem: F - Cards
// Contest: AtCoder - AtCoder Beginner Contest 247
// URL: https://atcoder.jp/contests/abc247/tasks/abc247_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-13 22:11:58
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

const int mod = 998244353;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

#define N 200005

vector<int> a, b, ind;
vector<bool> vis;
int cur, c[N][3];

void dfs(int i){
	dbg(i);
	if (vis[i]) return;
	vis[i] = 1;
	cur++;
	dfs(ind[b[i]]);
}

void solve(){
	
	int n;
	cin >> n;
	c[0][1] = 0;
	c[0][0] = 1;
	for (int i = 1; i <= n; i++){
		c[i][0] = c[i-1][1];
		c[i][1] = add(c[i-1][0], c[i-1][1]);
	}
	
	a.assign(n, 0);
	b.assign(n, 0);
	ind.assign(n + 1, 0);
	vis.assign(n, 0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ind[a[i]] = i;
	}
	for (int &x: b) cin >> x;
	
	ll ans = 1;
	for (int i = 0; i < n; i++){
		if (!vis[i]){
			cur = 0;
			dfs(i);
			ans = mul(ans, add(mul(c[cur][0], 2), c[cur][1]));
		}
	}
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
