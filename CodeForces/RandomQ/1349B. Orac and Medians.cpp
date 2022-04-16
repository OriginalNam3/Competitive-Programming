// Problem: B. Orac and Medians
// Contest: Codeforces - Codeforces Round #641 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1349/B
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
#define rsor(x) sort(x.rbegin(), x.rend())
#define pb push_back

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define fors(i,a,b,s) for (int i = (a); i < (b); i+=s)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)
#define debug(x) cout << #x << " = " << x << "\n";

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, k;
	cin >> n >> k;
	bool ok = false;
	vi a(n);
	int less = 0, greater = 0;
	forn(i, 0, n){
		cin >> a[i];
		if (a[i] == k) ok = true;
	}
	if (!ok){
		cout << "no\n"; return;
	}
	ok = false;
	if (n == 1) ok = true;
	forn(i, 0, n-1){
		if (a[i] < k) continue;
		if (a[i+1] >= k) ok = true;
		if (i < n-2) if (a[i+2] >= k) ok = true;
	}
	cout << (ok? "yes\n": "no\n");
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
