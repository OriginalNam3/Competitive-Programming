// Problem: D. Mark and Lightbulbs
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1705/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Date & Time: 2022-07-21 15:52:22
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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	if (s[0] != t[0] || s[n - 1] != t[n - 1]){
		cout << "-1\n"; return;
	}
	
	vector<int> a, b;
	for (int i = 0; i < n - 1; i++){
		if (s[i] != s[i + 1]){
			a.pb(i);
		}
		if (t[i] != t[i + 1]){
			b.pb(i);
		}
	}
	dbg(a, b);
	if (a.size() != b.size()){
		cout << "-1\n"; return;
	}
	
	ll ans = 0;
	for (int i = 0; i < a.size(); i++){
		ans += abs(a[i] - b[i]);
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; 
	cin >> t;
	while (t--)
	solve();
}
