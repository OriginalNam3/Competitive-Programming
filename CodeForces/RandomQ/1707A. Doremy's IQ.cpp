// Problem: A. Doremy's IQ
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1707/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-21 16:04:22
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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<bool> ans(n);
	int cur = 0;
	for (int i = n - 1; i >= 0; i--){
		if (a[i] <= cur) {
			ans[i] = 1;
			continue;
		}
		if (cur < q){
			ans[i] = 1;
			cur++;
			ans[i] = 1;
		}
	}
	dbg(ans);
	for (bool x: ans) cout << x;
	cout << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
