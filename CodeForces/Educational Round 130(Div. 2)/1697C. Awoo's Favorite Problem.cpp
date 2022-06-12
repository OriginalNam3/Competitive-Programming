// Problem: C. awoo's Favorite Problem
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-12 18:07:41
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
	str s, t;
	cin >> s >> t;
	bool ok = true;
	int i = 0, j = 0;
	while (i < n && j < n){
		while (i < n && s[i] == 'b') i++;
		while (j < n && t[j] == 'b') j++;
		dbg(i, j);
		if (i == n || j == n) break;
		if (s[i] != t[j] || (s[i] == 'a' && j < i) || (s[i] == 'c' && j > i)) {
			ok = false;
			break;
		}
		i++;
		j++;
	}
	
	while (i < n && s[i] == 'b') i++;
	while (j < n && t[j] == 'b') j++;
	if (i < n || j < n) ok = false;
	cout << (ok ? "YES\n": "NO\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
