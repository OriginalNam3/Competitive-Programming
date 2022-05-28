// Problem: D. Traps
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1684/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-21 20:42:47
// 
// Powered by CP Editor (https://cpeditor.org)

// https://codeforces.com/profile/Intellegent <3

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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	vector<ll> b(n);
	ll ans = 1LL * (-k * (k - 1)) / 2;
	for (int i = 0; i < n; i++){
		ans += a[i];
		b[i] = 1LL * -a[i] + (n - i - 1);
	}
	
	sor(b);
	for (int i = 0; i < k; i++){
		ans += b[i];
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
