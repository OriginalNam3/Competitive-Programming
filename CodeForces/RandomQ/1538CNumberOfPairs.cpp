// Problem: C. Number of Pairs
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1538/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef string str;

#define mp make_pair
#define f first
#define s second

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef array<int, 3> qq;

#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back

#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define rf(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define each(x, a) for (auto& x: a)

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vi a(n);
	each(x, a) cin >> x;
	sor(a);
	ll ans = 0;
	fr(i, 0, n){
		ans += lower_bound(all(a), r - a[i] + 1) - upper_bound(all(a), l - a[i] - 1);
		if (l <= a[i] * 2 && a[i] * 2 <= r) ans--;
	}
	cout << ans/2 << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
