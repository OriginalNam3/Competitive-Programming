// Problem: D. Replace by MEX
// Contest: Codeforces - Codeforces Global Round 9
// URL: https://codeforces.com/problemset/problem/1375/D
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
	int n;
	cin >> n;
	vi a(n);
	forn(i, 0, n){
		cin >> a[i];
	}
	vb mex(2 * n);
	vector<set<int> > ind(2 * n);
	forn(i, 0, n){
		mex[a[i]] = 1;
		ind[a[i]].insert(i);
	}
	int mx = n + 1;
	forn(i, 0, n+1){
		if (!mex[i]) {
			mx = i;
			break;
		}
	}
	// debug(mx);
	vi ans; int k = 0;
	while (mx < n){
		k++;
		ind[a[mx]].erase(mx);
		ans.pb(mx);
		int tmp = a[mx];
		a[mx] = mx;
		mex[mx] = 1;
		if (ind[tmp].empty()) {
			if (tmp < mx) mx = tmp;
			mex[tmp] = 0;
		}
		// debug(mx);
		while (mx < 2 * n && mex[mx]) mx++;
	}
	vi pos(2 * n);
	forn(i, 0, n){
		pos[a[i]] = i;
	}
	forn(i, 0, n){
		if (a[i] != i){
			// debug(mx);
			if (mx == i){
				k++;
				ans.pb(i);
				mex[a[i]] = 0;
				mex[mx] = 1;
				pos[a[i]] = -1;
				while (mx < 2 * n && mex[mx]) mx++;
				continue;
			}
			k += 2;
			int j = pos[i];
			a[j] = mx;
			pos[mx] = j;
			mex[mx] = 1;
			int tmp = a[i];
			mex[a[i]] = 0;
			a[i] = i;
			ans.pb(j); ans.pb(i);
			mex[i] = 1;
			if (tmp < mx) mx = tmp;
			while (mx < 2 * n && mex[mx]) mx++;
		}
	}
	cout << k << "\n";
	forn(i, 0, ans.size()){
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
}
