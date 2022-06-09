// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/problemset/problem/1654/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-06-08 18:57:55
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

const int mod = 998244353;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

#define N 200005

vector<int> prime, factors, pfact, r;
vector<vector<pair<int, pair<int, int> > > > g;
int ans;

int qpow(int a, int b, int c){  // returns a^b % c
	int res = 1;
	while (b > 0){
		if (b & 1) res = (1LL * res * a) % c;
		b >>= 1;
		a = (1LL * a * a) % c;
	}
	return res;
}

void dfs(int u, int p){
	dbg(u, p);
	for (auto vxy: g[u]){
		if (vxy.f == p) continue;
		int x = vxy.s.f, y = vxy.s.s;
		while (x > 1){
			int cur = prime[x];
			while (x % cur == 0){
				factors[cur]++;
				x /= cur;
			}
			pfact[cur] = max(pfact[cur], factors[cur]);
		}
		while (y > 1){
			int cur = prime[y];
			while (y % cur == 0){
				factors[cur]--;
				y /= cur;
			}
		}
		dbg(factors);
		dfs(vxy.f, u);
		x = vxy.s.f, y = vxy.s.s;
		while (x > 1){
			int cur = prime[x];
			while (x % cur == 0){
				factors[cur]--;
				x /= cur;
			}
		}
		while (y > 1){
			int cur = prime[y];
			while (y % cur == 0){
				factors[cur]++;
				y /= cur;
			}
		}
	}
}

void find(int u, int p, int cur){
	ans = add(ans, cur);
	dbg(cur);
	for (auto vxy: g[u]){
		if (vxy.f == p) continue;
		cur = mul(mul(cur, r[vxy.s.f]), vxy.s.s);
		find(vxy.f, u, cur);
		cur = mul(mul(cur, r[vxy.s.s]), vxy.s.f);
	}
}

void solve(){
	int n;
	cin >> n;
	
	g.assign(n, vector<pair<int, pair<int, int> > >());
	for (int rep = 1; rep < n; rep++){
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int d = gcd(x, y);
		x /= d;
		y /= d;
		i--; j--;
		
		g[i].pb(mp(j, mp(x, y)));
		g[j].pb(mp(i, mp(y, x)));
	}
	
	factors.assign(n + 1, 0);
	pfact.assign(n + 1, 0);
	
	dfs(0, 0);
	ans = 0;
	int res = 1;
	dbg(pfact);
	for (int i = 2; i <= n; i++){
		if (pfact[i] > 0) res = mul(res, qpow(i, pfact[i], mod));
	}
	find(0, 0, res);
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    prime.assign(N, 0);
    for (int i = 2; i < N; i++){
    	if (prime[i] > 0) continue;
    	prime[i] = i;
    	for (ll j = 1LL * i * i; j < N; j += i){
    		prime[j] = i;
    	}
    }
    
    r.assign(N, 0);
    r[1] = 1;
    for (int i = 2; i < N; i++){
    	r[i] = qpow(i, mod - 2, mod);
    }
    
    int t;
    cin >> t;
    while (t--) solve();
}
