// Problem: D. Cleaning the Phone
// Contest: Codeforces - Codeforces Round #697 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1475/D
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
#define rofn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(n) for (int _ = 0; _ < n; _++)
#define each(x, a) for (auto& x: a)

const int mod = 1e9+7;
const int INF = INT_MAX >> 1;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n;
	ll m;
	cin >> n;
	cin >> m;
	vi a(n), b(n);
	ll sum = 0;
	each (x, a) {
		cin >> x;
		sum += x;
	}
	each(x, b) cin >> x;
	vi one, two;
	forn(i, 0, n){
		if (b[i] == 1) one.pb(a[i]);
		else two.pb(a[i]);
	}
	rsor(one); rsor(two);
	if (sum < m){
		cout << "-1\n";
		return;
	}
	ll osum = 0, tsum = 0, j = 0, ans = LLONG_MAX;
	while (j < two.size() && tsum < m){
		tsum += two[j];
		j++;
	}
	if (tsum >= m) ans = 2 * j;
	forn(i, 0, one.size()){
		// cout << osum << " " << tsum << " " << ans << " " << c << "\n";
		osum += one[i];
		while (j > 0 && osum + tsum - two[j-1] >= m){
			j--;
			tsum -= two[j];
		}
		if (osum + tsum >= m) ans = min(ans, 2*j+i+1);
		// cout << "TANS: " << ans << "\n";
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
