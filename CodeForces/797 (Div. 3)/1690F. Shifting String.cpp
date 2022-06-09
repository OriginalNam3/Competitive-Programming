// Problem: F. Shifting String
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1690/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date & Time: 2022-06-07 20:14:04
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
#define pb push_back

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

vector<int> a(201);
vector<bool> searched(201);
str s;

ll lcm(ll a, ll b){
	if (b == 0) return a;
	b /= gcd(a, b);
	return a * b;
}

string search(int i, str cur){
	int siz = cur.size();
	if (searched[i]) return cur;
	searched[i] = 1;
	return search(a[i] - 1, cur + s[i]);
}

void solve(){
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) searched[i] = 0;
	
	ll ans = 1;
	for (int i = 0; i < n; i++){
		if (!searched[i]){
			str cur = search(i, "");
			dbg(cur);
			int mx = 1;
			for (; mx < cur.size(); mx++){
				bool ok = false;
				for (int j = 0; j < cur.size(); j++){
					if (cur[j] != cur[(j + mx) % cur.size()]){
						ok = true; 
						break;
					}
				}
				if (!ok) break;
			}
			ans = lcm(ans, mx);
		}
	}
	
	cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
