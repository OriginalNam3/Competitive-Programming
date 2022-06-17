// Problem: C. Dolce Vita
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1671/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-10 10:25:52
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
#define pb emplace_back

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C> (i, j); }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << ", " + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << ", " << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ", "; dbg_out(G, T...); }

#ifdef ORIGINAL_LOCAL
#define dbg(...) cerr << "Debug: " << #__VA_ARGS__ << " => [", dbg_out(__VA_ARGS__)
#else
#define dbg(...) 
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	sor(a);
	
	ll ans = 0;
	for (int i = 0; i < n; i++){
		x -= a[i];
		dbg(x);
		if (x < 0) break;
		ans += x/(i + 1) + 1;
		dbg(ans);
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}