// Problem: E. Eating Queries
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1676/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
// Date & Time: 2022-05-26 16:15:38
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
#define pb push_back

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(a.rbegin(), a.rend());
	
	vector<ll> pref(n);
	pref[0] = a[0];
	for (int i = 1; i < n; i++){
		pref[i] = a[i] + pref[i-1];
	}
	
	while (q--){
		int x; cin >> x;
		int l = 0, r = n;
		while (l < r){
			int m = (l + r) / 2;
			if (pref[m] < x) l = m + 1;
			else r = m;
		}
		if (l == n) cout << "-1\n";
		else cout << l + 1 << "\n";
	}
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
