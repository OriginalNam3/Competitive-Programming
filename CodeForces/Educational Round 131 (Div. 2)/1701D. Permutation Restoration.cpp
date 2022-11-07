// Problem: D. Permutation Restoration
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Date & Time: 2022-07-08 23:25:37
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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<pair<int, int> > b;
	for (int i = 0; i < n; i++){
		b.pb(make_pair((i + 1) / (a[i] + 1) + 1, i));
	}
	sor(b);
	dbg(b);
	vector<int> ans(n);
	int j = 0;
	set<pair<int, int> > c;
	for (int i = 1; i <= n; i++){
		while (j < n && b[j].f == i){
			c.insert(mp((a[b[j].s] == 0 ? n: (b[j].s + 1)/a[b[j].s]), b[j].s));
			j++;
			dbg(c, j);
		}
		ans[c.begin()->s] = i;
		c.erase(c.begin());
	}
	for (int x: ans) cout << x << " ";
	cout << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
