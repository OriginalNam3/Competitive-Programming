// Problem: A Bit Easy
// Contest: CodeChef - CodeChef Starters 38 Division 2 (Rated)
// URL: https://www.codechef.com/START38B/problems/ABITEZ
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Date & Time: 2022-05-11 15:47:23
// 
// Powered by CP Editor (https://cpeditor.org)

// You either sink in the coom, or coom in the sink.

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
	int n; ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	map<ll, int> cnt;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll cur = (k - a[i]) ^ a[i];
		// debug(cur)
		ans += cnt[a[i]];
		cnt[cur]++;
	}
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

// k = ai + (ai ^ aj)
