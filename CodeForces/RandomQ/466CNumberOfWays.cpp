// Problem: C. Number of Ways
// Contest: Codeforces - Codeforces Round #266 (Div. 2)
// URL: https://codeforces.com/problemset/problem/466/C
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

#define forn(i,a,b) for (int i = (a); i < (b); ++i)
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    each(x, a) cin >> x;
    vll ls(n), rs(n);
    ll lsum = 0, rsum = 0;
    forn(i, 0, n){
    	lsum += a[i];
    	ls[i] = lsum;
    	rsum += a[n-1-i];
    	rs[n-1-i] = rsum;
    }
    if (lsum%3 != 0){
    	cout << 0;
    	return 0;
    }
    
    lsum /= 3;
    if (rs[n-1] == lsum) rs[n-1] = 1;
    else rs[n-1] = 0;
    rofn(i, 0, n-1){
    	if (rs[i] == lsum) rs[i] = rs[i+1] + 1;
    	else rs[i] = rs[i+1];
    	// cout << rs[i] << " ";
    }

    ll ans = 0;
    forn(i, 0, n-2){
    	if (ls[i] == lsum) {
    		ans += rs[i+2];
    	}
    }
    cout << ans;
}
