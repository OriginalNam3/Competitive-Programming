// Problem: B. Rising Sand
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-07-02 15:55:31
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int ans = 0;
	for (int i = 1; i < n - 1; i++){
		if (a[i] > a[i-1] + a[i + 1]) ans++;
	}
	if (k == 1) ans = (n - 1)/2;
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    solve();
}
