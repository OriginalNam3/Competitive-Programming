// Problem: C. Schedule Management
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-07-08 22:44:15
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent husbando <3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

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
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int &x: a) cin >> x;
	vector<int> b(n);
	for (int i = 0; i < m; i++){
		b[a[i] - 1]++;
	}
	sor(b);
	int l = 1, r = m;
	while (l < r){
		vector<int> c = b;
		int t = (l + r)/2;
		bool ok = true;
		int i = 0, j = n - 1;
		while (i < j){
			if (c[j] < t || c[i] > t) break;
			int moved = min(c[j] - t, (t - c[i])/2);
			c[j] -= moved;
			c[i] += moved * 2;
			if (c[j] == t) j--;
			if (c[i] >= t - 1) i++;
		}
		dbg(t, c, b);
		for (int i = 0; i < n; i++){
			if (c[i] > t) ok = false;
		}
		if (ok){
			r = t;
		}
		else{
			l = t + 1;
		}
	}
	cout << l << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
