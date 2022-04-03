// Problem: C. The Sports Festival
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1509/C
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

const int N = 2e3 + 2;
ll dp[N][N], a[N];

ll rdp(int l, int r){
	// cout << l << " " << r << "\n";
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return 0;
	dp[l][r] = a[r] - a[l] + min(rdp(l + 1, r), rdp(l, r-1));
	return dp[l][r];
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n){
    	cin >> a[i];
    }
    sort(a, a+n);
    memset(dp, -1, sizeof dp);
    cout << rdp(0, n-1);
}
