// Problem: C. Helping the Nature
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1700/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-22 14:58:27
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
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	
	ll ans = 0, sub = 0;
	for (int i = 0; i < n - 1; i++){
		a[i + 1] -= sub;
		if (a[i + 1] > a[i]){
			sub += a[i + 1] - a[i];
			ans += a[i + 1] - a[i];
			a[i + 1] = a[i];
		}
		if (a[i + 1] < a[i]){
			ans += a[i] - a[i + 1];
		}
		dbg(ans, sub);
	}
	ans += abs(a[n - 1]);
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
