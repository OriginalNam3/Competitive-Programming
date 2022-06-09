// Problem: G. Count the Trains
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date & Time: 2022-06-08 14:10:57
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
void dbg_out() { cerr << " ]" << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ", "; dbg_out(G, T...); }

#ifdef ORIGINAL_LOCAL
#define dbg(...) cerr << #__VA_ARGS__ << " => [ ", dbg_out(__VA_ARGS__)
#else
#define dbg(...) 
#endif

const int mod = 1e9+7;
int add(int a, int b) {return (1LL * a + b) % mod;}
int mul(int a, int b) {return (1LL * a * b) % mod;}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	set<int> ind;
	int mn = a[0];
	ind.insert(0);
	for (int i = 1; i < n; i++){
		if (a[i] < mn){
			mn = a[i];
			ind.insert(i);
		}
	}
	dbg(ind);
	
	int k, d;
	for (int i = 0; i < m; i++){
		cin >> k >> d;
		k--;
		a[k] -= d;
		
		auto it = ind.lower_bound(k);
		if (it != ind.begin()){
			it--;
			if (a[*it] > a[k]) ind.insert(k);
		}
		it = ind.upper_bound(k);
		while (it != ind.end() && a[*it] >= a[k]){
			dbg(ind);
			dbg(*it);
			ind.erase(it);
			dbg(ind);
			it = ind.upper_bound(k);
		}
		cout << ind.size() << " ";
	}
	cout << "\n";
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
