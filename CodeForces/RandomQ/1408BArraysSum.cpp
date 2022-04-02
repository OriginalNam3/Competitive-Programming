// Problem: B. Arrays Sum
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	forn(i, 0, n){
		cin >> a[i];
	}
	if (k == 1){
		int c = a[0];
		forn(i, 1, n){
			if (a[i] != c){
				cout << "-1\n";
				return;
			}
		}
		cout << "1\n";
		return;
	}
	vb b(101);
	int cnt = 0;
	forn(i, 0, n){
		if (!b[a[i]]){
			b[a[i]] = 1;
			cnt++;
		}
	}
	if (cnt <= k){
		cout << "1\n";
		return;
	}
	cnt -= k;
	int ans = 1 + cnt/(k-1);
	if (cnt%(k-1) > 0) ans++;
	cout << ans << "\n";
	return;
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	solve();
    }
}
