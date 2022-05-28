// Problem: Controlled Inflation
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// Date & Time: 2022-04-24 17:07:11
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
template<class T> using V = vector<T>;
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
	int n, p;
	cin >> n >> p;
	vi a(p);
	int cur[2] = {0, 0};
	ll ans[2] = {1LL * 0, 1LL * 0};
	rep(n){
		each(x, a) cin >> x;
		sor(a);
		ll nans[2] = {0, 0};
		int bottop = abs(a[p-1] - cur[0]), toptop = abs(a[p-1] - cur[1]);
		nans[0] = 1LL * min(1LL * ans[0] + bottop, 1LL * ans[1] + toptop) + abs(a[p-1] - a[0]);
		int topbot = abs(cur[1] - a[0]), botbot = abs(cur[0] - a[0]);
		nans[1] = 1LL * min(1LL * ans[1] + topbot, 1LL * ans[0] + botbot) + abs(a[p-1] - a[0]);
		cur[0] = a[0]; cur[1] = a[p-1];
		ans[0] = nans[0]; ans[1] = nans[1];
		// debug(ans[0]);
		// debug(ans[1]);
	}
	cout << min(ans[0], ans[1]) << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    forn(i, 0, t){
    	cout << "Case #" << i + 1 << ": ";
    	solve();
    }
}
