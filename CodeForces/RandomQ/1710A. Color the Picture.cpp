// Problem: A. Color the Picture
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1710/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-27 17:25:29
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	for (int &x: a) cin >> x;
	
	sor(a);
	
	ll cnt = m;
	for (int i = k - 1; i >= 0 && cnt > 1; i--){
		int cur = a[i]/n;
		if (cur > 1){
			cnt -= 2;
		}
	}
	for (int i = k - 1; i >= 0 && cnt > 0; i--){
		int cur = a[i]/n - 2;
		dbg(i, cur, cnt);
		if (cur > 0){
			cnt -= cur;
		}
	}
	dbg(cnt);
	if (cnt <= 0){
		cout << "Yes\n"; return;
	}
	
	cnt = n;
	for (int i = k - 1; i >= 0 && cnt > 1; i--){
		int cur = a[i]/m;
		if (cur > 1){
			cnt -= 2;
		}
	}
	for (int i = k - 1; i >= 0 && cnt > 0; i--){
		int cur = a[i]/m - 2;
		if (cur > 0){
			cnt -= cur;
		}
	}
	
	if (cnt <= 0){
		cout << "Yes\n"; return;
	}
	
	
	cout << "No\n";
	
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
