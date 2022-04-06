// Problem: F1. Promising String (easy version)
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1660/F1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	int n;
	cin >> n;
	str s;
	cin >> s;
	int a[n][n];
	int b[n][n];
	forn(i, 0, n){
		if (s[i] == '+') {
			a[i][0] = 1;
			b[i][0] = 0;
		}
		else{
			a[i][0] = 0;
			b[i][0] = 1;
		}
	}
	int ans = 0;
	forn(i, 1, n){
		forn(j, 0, n-i){
			a[j][i] = a[j][i-1] + a[j+i][0];
			b[j][i] = b[j][i-1] + b[j+i][0];
			if (a[j][i] <= b[j][i] && (b[j][i] - a[j][i]) % 3 == 0){
				ans++;
			}
		}
	}
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
