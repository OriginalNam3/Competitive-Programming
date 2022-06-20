// Problem: E - Takahashi's Anguish
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2022（AtCoder Beginner Contest 256)
// URL: https://atcoder.jp/contests/abc256/tasks/abc256_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-18 13:42:33
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

ll ans;
vector<int> x, c, vis, p;

void solve(){
	int n;
	cin >> n;
	
	x.assign(n, 0), c.assign(n, 0), vis.assign(n, 0), p.assign(n, 0);
	for (int &e: x) {
		cin >> e;
		e--;
	}
	for (int &e: c) cin >> e;

	ans = 0;	
	for (int i = 0; i < n; i++){
		int cur = i;
		while (vis[cur] == 0){
			vis[cur]++;
			p[x[cur]] = cur;
			cur = x[cur];
		}
		if (vis[cur] == 1){
			int mn = c[cur], u = cur;
			cur = p[cur];
			while (cur != u){
				mn = min(c[cur], mn);
				cur = p[cur];
			}
			ans += mn;
		}
		cur = i;
		while (vis[cur] == 1){
			vis[cur]++;
			cur = x[cur];
		}
	}
	cout << ans;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
